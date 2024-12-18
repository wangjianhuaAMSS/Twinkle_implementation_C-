#ifndef _PERMUTATION_H_
#define _PERMUTATION_H_
#include "main.h"
vector<int> mul_add_perm(int len, vector<int> param) {
    vector<int> perm;
    vector<int> tmp;
    assert(param.size() == 2);

    for (int i = 0; i < len; i++) {
        int d = (i * param[0] + param[1]) % len;
        perm.push_back(d);
    }
    return(perm);
}
#endif