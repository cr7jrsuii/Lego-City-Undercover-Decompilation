#include "angle.h"
#include <algorithm>

constexpr float PI = 3.1415927f;

// todo Inlining of functions and improve readability
int NuAngAdd(int a, int b) {
    int sum = a + b;
    int temp = std::min(0x8000, sum);
    sum -= sum + ~temp + 0x10000 & 0xffff0000;
    temp = std::max(-0x7FFF, sum);
    sum += 0xFFFF - sum + temp & 0xffff0000;
    return sum;
}

int NuAngWrap(int angle) {
    int temp = std::min(0x8000, angle);
    angle -= angle + ~temp + 0x10000 & 0xffff0000;
    temp = std::max(-0x7FFF, angle);
    angle += 0xFFFF - angle + temp & 0xffff0000;
    return angle;
}
int NuAngSub(int a, int b) {
    int sum = a - b;
    int temp = std::min(0x8000, sum);
    sum -= sum + ~temp + 0x10000 & 0xffff0000;
    temp = std::max(-0x7FFF, sum);
    sum += 0xFFFF - sum + temp & 0xffff0000;
    return sum;
}
void NuAng2AltSol(int* out1, int* out2, int* out3, int a, int b, int c) {
    *out1 = a + 0x8000;
    *out2 = -0x8000 - b;
    *out3 = c + 0x8000;
}
float NuAngWrapRads(float angle) {
    while (angle > PI) {
        angle -= PI * 2;
    }
    while (-PI >= angle) {
        angle += PI * 2;
    }
    return angle;
}
float NuAngAddRads(float a, float b) {
    float sum = a + b;

    while (sum > PI) {
        sum -= PI * 2;
    }
    while (-PI >= sum) {
        sum += PI * 2;
    }
    return sum;
}
float NuAngSubRads(float a, float b) {
    float difference = a - b;

    while (difference > PI) {
        difference -= PI * 2;
    }
    while (-PI >= difference) {
        difference += PI * 2;
    }
    return difference;
}

void NuAngVecAddRads(NUVEC& out, NUVEC const& a, NUVEC const& b) {
    float angle = a.x + b.x;
    while (angle > PI) {
        angle -= PI * 2;
    }
    while (angle <= -PI) {
        angle += PI * 2;
    }
    out.x = angle;

    angle = a.y + b.y;
    while (angle > PI) {
        angle -= PI * 2;
    }
    while (angle <= -PI) {
        angle += PI * 2;
    }
    out.y = angle;

    angle = a.z + b.z;
    while (angle > PI) {
        angle -= PI * 2;
    }
    while (angle <= -PI) {
        angle += PI * 2;
    }
    out.z = angle;
}
void NuAngVecSubRads(NUVEC& out, NUVEC const& a, NUVEC const& b) {
    float angle = a.x - b.x;
    while (angle > PI) {
        angle -= PI * 2;
    }
    while (angle <= -PI) {
        angle += PI * 2;
    }
    out.x = angle;

    angle = a.y - b.y;
    while (angle > PI) {
        angle -= PI * 2;
    }
    while (angle <= -PI) {
        angle += PI * 2;
    }
    out.y = angle;

    angle = a.z - b.z;
    while (angle > PI) {
        angle -= PI * 2;
    }
    while (angle <= -PI) {
        angle += PI * 2;
    }
    out.z = angle;
}
