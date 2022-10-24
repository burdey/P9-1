//
// Created by Satori on 2022/10/23.
//

#ifndef P9_POLISHPREFIX_H
#define P9_POLISHPREFIX_H
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

class PolishPrefix {
private:
    string prefix;
public:
    PolishPrefix();
    PolishPrefix(string Polish);
    int PrefixNotation();
    void setPrefixNotation(string Polish);
    string PrintPrefix();
    ~PolishPrefix();
};


#endif //P9_POLISHPREFIX_H
