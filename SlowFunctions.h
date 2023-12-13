//
// Created by Adam Horn on 12/12/23.
//

#ifndef LRU_SLOWMATH_H
#define LRU_SLOWMATH_H

#include <string>
#include<map>
using namespace std;

class SlowFunctions {
public:
    static long NthFibonacci(int n);
    static string ReverseString(string str);
    static map<char, int> CountChars(string str);
};
#endif //LRU_SLOWMATH_H
