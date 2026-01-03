#pragma once

#include <cstdint>

class NuConstStringManager {
public:
    static void Free(NuConstStringManager* mgr, char* str);
};
namespace NuCore {
NuConstStringManager* GetConstStringManager();
}
struct ScriptContext;

enum ActionState {
    ACTION_FINISHED = 1,
    ACTION_YIELD = 5,
    ACTION_UNKNOWN_7 = 7,
};

enum ScriptVarType {
    SV_VOID = 0,
    SV_INT = 1,
    SV_FLOAT = 2,
    SV_STRING = 5,
    SV_ANY = 7,  // ?
    SV_GIZMO = 31,
};

struct SCmdParamEntry {
    uint64_t _pad;

    union {
        char* m_String;
        uint64_t m_Value64;
    } m_Data;

    unsigned int m_Type;
    unsigned char m_Flag14;  // 0x14: Unknown flag
    unsigned char m_IsAllocated;
};

struct SCmdParams {
    SCmdParamEntry m_Args[64];  // 0x00 - 0x600: Array of 64 parameter entries
    int m_CurrentParamIndex;    // 0x600: Current index of arguments

    void AddParam(ScriptVarType type) {
        int idx = m_CurrentParamIndex;

        if (idx < 0) {
            m_CurrentParamIndex = 0;
            idx = 0;
        }

        SCmdParamEntry* entry = &m_Args[idx];

        entry->m_Type = type;
        entry->m_Flag14 = 0;

        uint64_t* dataPtr = &entry->m_Data.m_Value64;

        if (entry->m_IsAllocated) {
            char* strPtr = entry->m_Data.m_String;
            NuConstStringManager::Free(NuCore::GetConstStringManager(), strPtr);
            entry->m_IsAllocated = 0;
        }

        *dataPtr = 0;
        m_CurrentParamIndex++;
    }
    void SanityCheck() {
        if (m_CurrentParamIndex < 0) {
            m_CurrentParamIndex = 0;
        }
    }
};

class ActionInstanceData {
public:
    int m_Pad;
    int m_HasInput;

    virtual ~ActionInstanceData();
    virtual const char* GetName() const = 0;
    virtual void GetInputs(SCmdParams& params) const { params.SanityCheck(); }
    virtual void GetOutputs(SCmdParams& params) const { params.SanityCheck(); }
    virtual ActionState Exec(ScriptContext& context) { return ACTION_FINISHED; }
};
