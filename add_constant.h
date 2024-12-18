#ifndef _ADD_CONSTANT_H_
#define _ADD_CONSTANT_H_
#include "main.h"
#include "rc.h"
void add_constant(int r, vector<uint16_t> ain, vector<uint16_t> &aout) {
    if (ain.size() * 16 == 1280) {
        for (int i = 0; i < (int)ain.size(); i++) {
            aout[i] = ain[i] ^ rc1280[r][i];
        }
    } else if (ain.size() * 16 == 1024) {
        for (int i = 0; i < (int)ain.size(); i++) {
            aout[i] = ain[i] ^ rc1280[r][i+16];
        }
    } else if (ain.size() * 16 == 256) {
        for (int i = 0; i < (int)ain.size(); i++) {
            aout[i] = ain[i] ^ rc1280[r/5][i+16*(r%5)];
        }
    } 
}
#endif