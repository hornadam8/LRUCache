//
// Created by Adam Horn on 12/12/23.
//

#include "SlowFunctions.h"
#include <string>
#include <chrono>
#include <thread>


long SlowFunctions::NthFibonacci(int n) {
    if (n < 3) {
        return 1;
    } else {
        return NthFibonacci(n-1) + NthFibonacci(n-2);
    }
}

string SlowFunctions::ReverseString(string str) {
    reverse(str.begin(), str.end());
    return str;
}

map<char, int> SlowFunctions::CountChars(string str) {
    map<char,int> ret;
    for (char c : str) {
        if (ret.count(c)) {
            ret[c]++;
        } else {
            ret[c] = 1;
        }
    }
    return ret;
}