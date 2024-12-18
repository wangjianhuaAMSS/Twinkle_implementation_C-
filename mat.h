#ifndef _MAT_H_
#define _MAT_H_
#include "main.h"



uint16_t mat(uint16_t m_in) {
    uint16_t m_out = 0;
    m_out = m_in ^ ((m_in << 5) | (m_in >> 11)) ^ ((m_in << 12) | (m_in >> 4));
    return(m_out);
}

void mat_layer(vector<uint16_t> m_in, vector<uint16_t> &m_out) {
    for (int i = 0; i < (int)m_in.size(); i++) {
        m_out[i] = mat(m_in[i]);
    }
}
#endif
