#include "kestrel/script/actions/SAction_CreateLegoProgressBackup.h"

const char* SAction_CreateLegoProgressBackup::GetName() const {
    return "CreateLegoProgressBackup";
}
void SAction_CreateLegoProgressBackup::GetInputs(SCmdParams& params) const {
    ActionInstanceData::GetInputs(params);
}
void SAction_CreateLegoProgressBackup::GetOutputs(SCmdParams& params) const {
    ActionInstanceData::GetOutputs(params);
}
