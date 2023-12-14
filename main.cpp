#include <iostream>
#include "LruCache.h"
#include "SlowFunctions.h"
#include <sys/time.h>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    LruCache<int, long> fibo_cache = LruCache<int, long>(3);
    cout << "\nGet from empty fibo_cache should return nullptr. Equals nullptr?: " << (fibo_cache.Get(5) == nullptr) << endl;
    fibo_cache.Add(2,4);
    fibo_cache.Add(3, 9);
    fibo_cache.Add(4, 16);
    fibo_cache.Add(5, 25);
    fibo_cache.Add(6, 36);

    cout << "\nfibo_cache with capacity 3 should not contain 4th most recent item. Equals nullptr?: " << endl;
    shared_ptr<long> long_ret = fibo_cache.Get(3);
    cout << (long_ret == nullptr) << endl;

    cout << "\nfibo_cache with capacity 3 should contain second most recent item" << endl;
    long_ret = fibo_cache.Get(5);
    cout << *long_ret << endl;

    cout << "\nfibo_cache with capacity 3 should contain third most recent item" << endl;
    long_ret = fibo_cache.Get(4);
    cout << *long_ret << endl;

    cout << "\nAdding an item should remove the least recently used item. Equals nullptr?:" << endl;
    fibo_cache.Add(7, 49);
    long_ret = fibo_cache.Get(6);
    cout << (long_ret == nullptr) << endl;

    cout << "\nSlow fibonacci should take a while the first time" << endl;
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int start = tp.tv_sec * 1000 + tp.tv_usec / 1000;

    long_ret = fibo_cache.CacheFunction(40, SlowFunctions::NthFibonacci);

    cout << *long_ret << endl;
    gettimeofday(&tp, NULL);
    long int end = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout << "took: " << end - start << " ms" << endl;


    cout << "\nSlow fibonacci should be fast the second time" << endl;
    gettimeofday(&tp, NULL);
    start = tp.tv_sec * 1000 + tp.tv_usec / 1000;

    long_ret = fibo_cache.CacheFunction(40, SlowFunctions::NthFibonacci);

    cout << *long_ret << endl;
    gettimeofday(&tp, NULL);
    end = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout << "took: " << end - start << " ms" << endl;

    
    LruCache<string,string> reverse_cache = LruCache<string, string>(3);
    ifstream t("words.txt");
    stringstream buffer;
    buffer << t.rdbuf();
    string str = buffer.str();
    shared_ptr<string> rev_ret = shared_ptr<string>(new string);

    // This reverse string implementation sleeps to simulate much large input
    cout << "\nSlow string reverse should take a while the first time (function sleeps to simulate large input)" << endl;
    gettimeofday(&tp, NULL);
    start = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    rev_ret = reverse_cache.CacheFunction(str, SlowFunctions::ReverseString);
    //cout << *rev_ret << endl; commenting this out because its a really long string
    gettimeofday(&tp, NULL);
    end = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout << "took: " << end - start << " ms" << endl;



    cout << "\nSlow string reverse should be fast the second time" << endl << endl;
    gettimeofday(&tp, NULL);
    start = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    rev_ret = reverse_cache.CacheFunction(str, SlowFunctions::ReverseString);
    //cout << *rev_ret << endl; commenting this out because its a really long string
    gettimeofday(&tp, NULL);
    end = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout << "took: " << end - start << " ms" << endl;

    LruCache<string, map<char,int>> char_count_cache = LruCache<string, map<char, int>>(3);
    map<char,int> result;
    shared_ptr<map<char,int>> chars_ret = shared_ptr<map<char,int>>(new map<char, int>);

    // This reverse string implementation sleeps to simulate much large input
    cout << "\nSlow count chars should take a while the first time"  << endl;
    gettimeofday(&tp, NULL);
    start = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    chars_ret = char_count_cache.CacheFunction(str, SlowFunctions::CountChars);
    result = *chars_ret;
    for (const auto& c : result) {
        cout << c.first << ": " << c.second << endl;
    }

    gettimeofday(&tp, NULL);
    end = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout << "took: " << end - start << " ms" << endl;

    cout << "\nSlow count chars should be fast the second time" << endl;
    gettimeofday(&tp, NULL);
    start = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    chars_ret = char_count_cache.CacheFunction(str, SlowFunctions::CountChars);
    result = *chars_ret;
    for (const auto& c : result) {
        cout << c.first << ": " << c.second << endl;
    }
    gettimeofday(&tp, NULL);
    end = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout << "took: " << end - start << " ms" << endl;

    return 0;
}
