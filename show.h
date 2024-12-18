#ifndef _SHOW_H_
#define _SHOW_H_
#include "main.h" 

void write_state(vector<uint16_t> state, ofstream & file) {
    for (size_t i = 0; i < state.size(); i++) {
        file << hex << state[i] << " ";
    }
    file << dec << endl;
}


void draw_boundary(ofstream &file) {
    string str(100, '*');
    file << str << endl;
}
#endif