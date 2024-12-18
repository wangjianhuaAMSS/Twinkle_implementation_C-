#ifndef _RIGHT_ROTATION_H_
#define _RIGHT_ROTATION_H_
#include "main.h" 




void right_rotation( vector<uint16_t> rin, vector<int> offset, vector<uint16_t> &rout) {
    for (int i = 0; i < (int)rin.size(); i++) {
        rout[i] = 0;
    }
    for (int i = 0; i < 16; i++) {
        for (size_t j = 0; j < (int)rin.size(); j++) {
            rout[j] ^= (((rin[(j + offset[i])%((int)rin.size())]>>i) & 1) << i);
        }
    }
}
#endif

