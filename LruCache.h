#ifndef LRU_LRUCACHE_H
#define LRU_LRUCACHE_H

#include <map>
#include "DoublyLinkedList.h"
#include <memory>

using namespace std;

template<typename key_type, typename val_type>
class LruCache {
public:
    LruCache(int cap);
    ~LruCache();

    val_type Get(key_type key);
    void Add(key_type key, val_type value);
    val_type CacheFunction(key_type key, val_type (*func)(key_type));

private:
    struct Impl;
    unique_ptr<Impl> pImpl;
};

#endif // LRU_LRUCACHE_H