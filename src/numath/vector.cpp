#include "numath/scalar.h"
#include "numath/vector.h"
#include <math.h>

// todo move function to NuCore
float NuFsqrt(float f) {
    return f <= 0.0f ? 0.0f : sqrt(f);
}
void NuVecNeg(NUVEC* out, NUVEC const* in) {
    out->x = -in->x;
    out->y = -in->y;
    out->z = -in->z;
}
void NuVecAdd(NUVEC* out, NUVEC const* v1, NUVEC const* v2) {
    out->x = v1->x + v2->x;
    out->y = v1->y + v2->y;
    out->z = v1->z + v2->z;
}
void NuVecSub(NUVEC* out, NUVEC const* v1, NUVEC const* v2) {
    out->x = v1->x - v2->x;
    out->y = v1->y - v2->y;
    out->z = v1->z - v2->z;
}
void NuVecScale(NUVEC* out, NUVEC const* in, float scale) {
    out->x = in->x * scale;
    out->y = in->y * scale;
    out->z = in->z * scale;
}
void NuVecAddScale(NUVEC* out, NUVEC const* v1, NUVEC const* v2, float scale) {
    out->x = v1->x + v2->x * scale;
    out->y = v1->y + v2->y * scale;
    out->z = v1->z + v2->z * scale;
}
void NuVecScaleAccum(NUVEC* v1, NUVEC const* v2, float scale) {
    v1->x += v2->x * scale;
    v1->y += v2->y * scale;
    v1->z += v2->z * scale;
}
void NuVecInvScale(NUVEC* out, NUVEC const* in, float scale) {
    if (scale == 0.0f) {
        scale = 0.0f;
    } else {
        scale = 1.0f / scale;
    }
    NuVecScale(out, in, scale);
}
float NuVecDot(NUVEC const* v1, NUVEC const* v2) {
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}
void NuVecMax(NUVEC* out, NUVEC const* v1, NUVEC const* v2) {
    out->x = v1->x > v2->x ? v1->x : v2->x;
    out->y = v1->y > v2->y ? v1->y : v2->y;
    out->z = v1->z > v2->z ? v1->z : v2->z;
}
void NuVecMin(NUVEC* out, NUVEC const* v1, NUVEC const* v2) {
    out->x = v1->x < v2->x ? v1->x : v2->x;
    out->y = v1->y < v2->y ? v1->y : v2->y;
    out->z = v1->z < v2->z ? v1->z : v2->z;
}
float NuVecMag(const NUVEC* v) {
    return NuFsqrt(NuVecDot(v, v));
}
float NuVecMagSqr(NUVEC const* v) {
    return NuVecDot(v, v);
}
float NuVecMagXZ(const NUVEC* v) {
    return NuFsqrt(v->x * v->x + v->z * v->z);
}
void NuVecLerp(NUVEC* out, NUVEC const* end, NUVEC const* start, float t) {
    out->x = (end->x - start->x) * t + start->x;
    out->y = (end->y - start->y) * t + start->y;
    out->z = (end->z - start->z) * t + start->z;
}
void NuVecRotateXOld(NUVEC* out, NUVEC const* in, int angle) {
    float angleCos = NuSinOld(angle + 16384);
    float angleSin = NuSinOld(angle);

    float x_val = in->x;
    float y = in->y;
    out->x = x_val;
    float z = in->z;

    float temp1 = angleCos * y;
    float temp2 = angleSin * y;
    float temp3 = angleSin * z;

    out->y = temp1 - temp3;

    float temp4 = angleCos * z;
    out->z = temp2 + temp4;
}
void NuVecToNuHalfVec(NUVEC const* in, NUHALFVEC* out) {
    out->x = NuFloatToHalf(in->x);
    out->y = NuFloatToHalf(in->y);
    out->z = NuFloatToHalf(in->z);
}
void NuVec4Add(NUVEC4* out, NUVEC4 const* v1, NUVEC4 const* v2) {
    out->w = v1->w + v2->w;
    out->x = v1->x + v2->x;
    out->y = v1->y + v2->y;
    out->z = v1->z + v2->z;
}
void NuVec4Sub(NUVEC4* out, NUVEC4 const* v1, NUVEC4 const* v2) {
    out->x = v1->x - v2->x;
    out->y = v1->y - v2->y;
    out->z = v1->z - v2->z;
    out->w = v1->w - v2->w;
}
void NuVec4Scale(NUVEC4* out, NUVEC4 const* in, float scale) {
    out->x = in->x * scale;
    out->y = in->y * scale;
    out->z = in->z * scale;
    out->w = in->w * scale;
}
void NuVec4AddScale(NUVEC4* out, NUVEC4 const* v1, NUVEC4 const* v2, float scale) {
    out->x = v1->x + v2->x * scale;
    out->y = v1->y + v2->y * scale;
    out->z = v1->z + v2->z * scale;
    out->w = v1->w + v2->w * scale;
}
float NuVec4Dot(NUVEC4 const* v1, NUVEC4 const* v2) {
    return v1->w * v2->w + v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}
void NuVec4Max(NUVEC4* out, NUVEC4 const* v1, NUVEC4 const* v2) {
    out->x = v1->x > v2->x ? v1->x : v2->x;
    out->y = v1->y > v2->y ? v1->y : v2->y;
    out->z = v1->z > v2->z ? v1->z : v2->z;
    out->w = v1->w > v2->w ? v1->w : v2->w;
}
void NuVec4Min(NUVEC4* out, NUVEC4 const* v1, NUVEC4 const* v2) {
    out->x = v1->x < v2->x ? v1->x : v2->x;
    out->y = v1->y < v2->y ? v1->y : v2->y;
    out->z = v1->z < v2->z ? v1->z : v2->z;
    out->w = v1->w < v2->w ? v1->w : v2->w;
}
float NuVec4Mag(NUVEC4 const* v) {
    return NuFsqrt(NuVec4MagSqr(v));
}
float NuVec4MagSqr(NUVEC4 const* v) {
    return v->w * v->w + v->x * v->x + v->y * v->y + v->z * v->z;
}
void NuVec4Lerp(NUVEC4* out, NUVEC4 const* start, NUVEC4 const* end, float t) {
    out->x = end->x + (start->x - end->x) * t;
    out->y = end->y + (start->y - end->y) * t;
    out->z = end->z + (start->z - end->z) * t;
    out->w = end->w + (start->w - end->w) * t;
}
void NuVec4ToNuHalfVec4(NUVEC4 const* in, NUHALFVEC4* out) {
    out->x = NuFloatToHalf(in->x);
    out->y = NuFloatToHalf(in->y);
    out->z = NuFloatToHalf(in->z);
    out->w = NuFloatToHalf(in->w);
}
float NuVecMagVU0(NUVEC const* v) {
    return NuFsqrt(NuVecDot(v, v));
}
