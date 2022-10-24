#include <iostream>
#include <string>
#include "PolishPrefix.h"
using namespace std;

int main() {
    string prefix;
    getline(cin, prefix);

    PolishPrefix polish(prefix);

    string print = polish.PrintPrefix();
    cout << print;
    if (print.compare("Error") != 0){
        int notation = polish.PrefixNotation();
        cout << " = " << notation;
    }
    return 0;
}
