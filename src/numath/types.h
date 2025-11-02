#pragma once

struct NUVEC {
    float x;
    float y;
    float z;
};
struct NUVEC4 {
    float x;
    float y;
    float z;
    float w;
};
struct NUMTX {
    float m[4][4];
};
struct NUHALFVEC {
    unsigned short x;
    unsigned short y;
    unsigned short z;
};
struct NUHALFVEC4 {
    unsigned short x;
    unsigned short y;
    unsigned short z;
    unsigned short w;
};
struct NUPLANE {
    NUVEC normal;
    float d;
};
struct NUANGVEC {
    int x;
    int y;
    int z;
};
