#include "main.h"
#include "muladd_permutation.h"
vector<vector<int>> IVPermParam_256 = {vector<int> {1, 0},  vector<int> {3, 1}, vector<int> {5, 2}, vector<int> {7, 3}, vector<int> {11, 4}, vector<int> {13, 5},
                                vector<int> {17, 6}, vector<int> {19, 7}, vector<int> {23, 8}, vector<int> {29, 9}};
void padding(vector<uint16_t> IV, vector<uint16_t> key, vector<uint16_t> &state) {
    int state_len = 1280;
    int iv_len = 128;
    for (int i = 0; i < state_len/iv_len; i++) {
        vector<int> perm = mul_add_perm(iv_len, IVPermParam_256[i]);
        vector<uint16_t> iv_tmp(iv_len/16, 0);
        for (int j = 0; j < iv_len; j++) {
            iv_tmp[perm[j]/16] ^= (((IV[j/16] >> (j % 16)) & 1) << (perm[j] % 16));
        }
        for (int j = 0; j < iv_len/16; j++) {    
            state[i*(iv_len/16) + j] = iv_tmp[j] ^ key[i*(iv_len/16) + j];
        }
    }
}