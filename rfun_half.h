#ifndef _RFUN_HALF_H_
#define _RFUN_HALF_H_
#include "main.h"
#include "sbox_B9.h"
#include "mat.h"
#include "add_constant.h"
#include "right_rotation.h"



void rfun_half(vector<uint16_t> fin, vector<uint16_t> &fout) {
    vector<vector<uint16_t>> tmp(4, vector<uint16_t>(fin.size()));
    //sbox layer
    sbox_layer_B9(fin, tmp[0]);

    //LR1
    right_rotation(tmp[0], LR1, fout);
}

#endif