#include "kestrel/script/actions/SAction_AILocator.h"

const char* SAction_AILocator::GetName() const {
    return "Locator";
}
void SAction_AILocator::GetInputs(SCmdParams& params) const {
    params.SanityCheck();
    params.AddParam(SV_TEXT);
    params.AddParam(SV_WORLD_LEVEL);
}

void SAction_AILocator::GetOutputs(SCmdParams& params) const {
    params.SanityCheck();
    params.AddParam(SV_LOCATOR);
}
ActionState SAction_AILocator::Exec(ScriptContext& context) {
    return ActionInstanceData::Exec(context);
}
