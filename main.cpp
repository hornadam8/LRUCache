#include <iostream>
#include "LruCache.h"
#include "SlowMath.h"
#include <sys/time.h>

using namespace std;

int main() {
    LruCache<int, long> cache = LruCache<int, long>(3);
    cout << "\nGet from empty cache should return nullptr. Equals nullptr?: " << (cache.Get(5) == nullptr) << endl;
    cache.Add(2,4);
    cache.Add(3, 9);
    cache.Add(4, 16);
    cache.Add(5, 25);
    cache.Add(6, 36);

    cout << "\nCache with capacity 3 should not contain 4th most recent item. Equals nullptr?: " << endl;
    shared_ptr<long> ret = cache.Get(3);
    cout << (ret == nullptr) << endl;

    cout << "\nCache with capacity 3 should contain second most recent item" << endl;
    ret = cache.Get(5);
    cout << *ret << endl;

    cout << "\nCache with capacity 3 should contain third most recent item" << endl;
    ret = cache.Get(4);
    cout << *ret << endl;

    cout << "\nAdding an item should remove the least recently used item. Equals nullptr?:" << endl;
    cache.Add(7, 49);
    ret = cache.Get(6);
    cout << (ret == nullptr) << endl;

    cout << "\nSlow math should take a while the first time" << endl;
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int start = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    ret = cache.CacheFunction(40, SlowMath::NthFibonacci);
    cout << *ret << endl;
    gettimeofday(&tp, NULL);
    long int end = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout << "took: " << end - start << " ms" << endl;


    cout << "\nSlow math should be fast the second time" << endl;
    gettimeofday(&tp, NULL);
    start = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    ret = cache.CacheFunction(40, SlowMath::NthFibonacci);
    cout << *ret << endl;
    gettimeofday(&tp, NULL);
    end = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout << "took: " << end - start << " ms" << endl;
    return 0;
}
