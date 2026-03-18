#pragma once
#include <string>

struct NPAt {
    int S;
    unsigned __int64 M;
    __int64 e;
    int q;
};

NPAt convertToNPAt(std::string s, std::string label);
NPAt addNPAt(NPAt n1, NPAt n2, long long current_z, bool show);
std::string convertNPAtToDecimal(NPAt n);