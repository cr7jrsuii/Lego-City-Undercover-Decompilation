#pragma once

#include "nucore/NuInputDevice.h"

namespace NuInputDevicePS {

enum class NuControllerType : int {
    GENERIC = 1,
    HANDHELD = 7,
    JOY_CON_DUAL = 8,
    PRO_CONTROLLER = 9,
};
int ClassInitPS();
int GetNumPorts();
void ClassShutdownPS();
void UpdateAllPS(float deltaTime);
bool IsConnectedPS(unsigned int port);
bool IsInterceptedPS(unsigned int port);
int GetTypePS(unsigned int port);
int GetAttachmentTypePS(unsigned int port);
int GetCapsPS(unsigned int port);
void ReadButtonsPS(unsigned int port, float* buttons);
unsigned int GetStickDeadZone(unsigned int port);
unsigned int GetButtonDeadZone(unsigned int port);
void ReadAnalogValuesPS(unsigned int port, float* analogValues);
void ReadMotionValuesPS(unsigned int port, float* motionValues);
void ReadTouchDataPS(unsigned int port, NuInputTouchData* touchData);
void ReadMouseDataPS(unsigned int port, NuInputMouseData* mouseData);
void SetMotorsPS(unsigned int port, float lowFreq, float highFreq);
unsigned int EnableDPDPS(unsigned int port);
unsigned int DisableDPDPS(unsigned int port);
bool HasHeadphonesConnectedPS(unsigned int port);
float GetVolumePS(unsigned int port);
}  // namespace NuInputDevicePS
