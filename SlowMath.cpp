//
// Created by Adam Horn on 12/12/23.
//

#include "SlowMath.h"

long SlowMath::NthFibonacci(int n) {
    if (n < 3) {
        return 1;
    } else {
        return NthFibonacci(n-1) + NthFibonacci(n-2);
    }
}