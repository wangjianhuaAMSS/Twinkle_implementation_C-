
#include "twinkle_256_top.h"
#include "show.h"
#include "main.h"


#define IV0 "0 0 0 0 0 0 0 0"
#define IV1 "3eda 1095 33e5 667e ac32 659a 786c 2f4d"

#define KEY0 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
#define KEY1 "0 0 0 0 0 0 0 0 d2c4 4756 f111 6cca b5eb cd95 d758 1599 53f4 6d37 6f44 590b f93e da10 9533 e566 7eac 3265 9a78 6c2f 4d48 dcd6 d04f e3bb a60f e1af 03f5 3eda 1095 33e5 667e ac32 659a 786c 2f4d b62b 8dba d523 8837 a63c 997a 293a cf11 9ddb 7e3c 6e01 bb86 af24 5c83 becd 8a3d 39e5 67ea 63c0 359f b453 2a17 0739 dadd c895 0ac0 a871 b9ed cbc3 1f31 0671 15c6 c774 54d8 f4b1 9881 f5de"



void show_result(vector<uint16_t> iv, vector<uint16_t> key, vector<uint16_t> output) {
    cout << "key:" << endl;
    for (int i = 1280/16 - 1; i >= 0 ; i--)
        cout << hex << setw(4) << setfill('0') << right <<  key[i];
    cout << endl;
    
    cout << "iv:" << endl;
    for (int i = 128/16 - 1; i >= 0; i--)
        cout << hex << setw(4) << setfill('0') << right << iv[i];
    cout << endl;
    
    cout << "output:" << endl;
    for (int i = 1152/16 - 1; i >= 0 ; i--)
        cout << hex << setw(4) << setfill('0') << right << output[i];
    cout << endl;

}

void load_test_value(vector<uint16_t> & iv, vector<uint16_t> & key) {
    stringstream ssk, ssi;
    ssk << KEY0;
    for (int i = 1280/16 - 1; i >= 0; i--)
        ssk >> hex >> key[i];

    ssi << IV0;
    for (int i = 128/16 - 1; i >= 0 ; i--)
        ssi >> hex >> iv[i];
}

int main() {
    vector<uint16_t> iv(128/16), key(1280/16), output(1152/16);
    srand((unsigned)time(NULL));


    load_test_value(iv, key);
    
    twinkle_256_top(iv, key, output);

    show_result(iv, key, output);
    return(0);
}

