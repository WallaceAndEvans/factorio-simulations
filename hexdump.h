#ifndef __HEXDUMP_H
#define __HEXDUMP_H

#include <cstdio>

template <typename T>
void dump(T& obj) {
    void* vp = &obj;
    unsigned char* cursor = static_cast<unsigned char*>(vp);
    fprintf(stderr, "%02lu: ", sizeof obj);
    for (unsigned int i = 0; i < sizeof obj; ++i) {
        fprintf(stderr, "%02x ", cursor[i] & 0xFF);
    }
    fprintf(stderr, "\n");
};

#endif

