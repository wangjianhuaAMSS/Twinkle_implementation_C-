#ifndef _SBOX_B9_H_
#define _SBOX_B9_H_

#include "main.h"

void sbox_B9(uint16_t sin, uint16_t &sout) {
    switch (sin) {
        case 0:
            sout = 0x0;
            break;
        case 1:
            sout = 0x3;
            break;
        case 2:
            sout = 0x5;
            break;
        case 3:
            sout = 0xd;
            break;
        case 4:
            sout = 0x6;
            break;
        case 5:
            sout = 0xf;
            break;
        case 6:
            sout = 0xa;
            break;
        case 7:
            sout = 0x8;
            break;
        case 8:
            sout = 0xb;
            break;
        case 9:
            sout = 0x4;
            break;
        case 10:
            sout = 0xe;
            break;
        case 11:
            sout = 0x2;
            break;
        case 12:
            sout = 0x9;
            break;
        case 13:
            sout = 0xc;
            break;
        case 14:
            sout = 0x7;
            break;
        case 15:
            sout = 0x1;
            break;
        default:
            sout = 0;
            break;
    }
}

void sbox_layer_B9(vector<uint16_t> sin, vector<uint16_t> &sout) {
    for (size_t i = 0; i < sin.size(); i++) {
        sout[i] = 0;
        for (int j = 0; j < 4; j++) {
            uint16_t tmp_in, tmp_out;
            tmp_in = (((sin[i] >> 4*j) & 1) << 3) ^ (((sin[i] >> (4*j+1)) & 1) << 2) ^ (((sin[i] >> (4*j+2)) & 1) << 1) ^ (((sin[i] >> (4*j+3)) & 1) << 0); 
            sbox_B9(tmp_in, tmp_out);
            sout[i] ^= ((((tmp_out >> 3) & 1) << 4*j) ^ (((tmp_out >> 2) & 1) << (4*j+1)) ^ (((tmp_out >> 1) & 1) << (4*j+2)) ^ (((tmp_out >> 0) & 1) << (4*j+3)));
        }       
    }
}

#endif