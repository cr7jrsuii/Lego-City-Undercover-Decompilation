#include "kestrel/script/actions/DebugMsg.h"

const char* SActionDebugMsg::GetName() const {
    return "DebugMsg";
}
void SActionDebugMsg::GetInputs(SCmdParams& params) const {
    params.SanityCheck();
    params.AddParam(SV_STRING);
}
void SActionDebugMsg::GetOutputs(SCmdParams& params) const {
    ActionInstanceData::GetOutputs(params);
}
ActionState SActionDebugMsg::Exec(ScriptContext& context) {
    return ActionInstanceData::Exec(context);
}
