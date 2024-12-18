#include "main.h"
#include "rfun.h"
#include "rfun_half.h"
#include "padding.h"
void  twinkle_128_top(vector<uint16_t> IV, vector<uint16_t> key, vector<uint16_t> &output) {
    vector<uint16_t> state(80), tmp(80);
    
    //padding;
    padding(IV, key, state);
    //
    vector<uint16_t> key1 = key;
    for (int i = 0; i < 1280/16; i++) {
        key1[i] = (key[i] >> 1) | (key[(i+1)%(1280/16)] << 15);
    }
    key1[0] ^= key[1280/16-1] >> 15;
    for (int i = 0; i < 9; i++) {
        rfun(state, tmp);
        add_constant(i, tmp, state);
    }
    rfun_half(state, tmp);
    for (int i = 0; i < 1280/16; i++)
        state[i] = tmp[i] ^ key1[i];
    for (int i = 0; i < 1152/16; i++) {
        output[i] = state[i] ^ state[i + 8];
    }
}