#ifndef LRU_LRUCACHE_H
#define LRU_LRUCACHE_H

#include <map>
#include "DoublyLinkedList.h"
#include <memory>

using namespace std;

/// LRU cache can be initialized with a number of key and value tupes, listed at the bottom of the .cpp file
/// i.e. LRUCache<string,map<string, string> > json_cache = LRUCache<string,map<string, string> >(5);
/// this creates a cache with string keys and value maps with string keys and string values.
template<typename key_type, typename val_type>
class LruCache {
public:
    LruCache(int cap);
    ~LruCache();

    /// takes a key_type key as an argument, returns associated (val_type) data from the hashmap and moves its key node
    /// to the head of the doubly linked list. If the key is not present, returns null
    shared_ptr<val_type> Get(key_type key);

    /// takes a key_type key and a val_type value as arguments, adds these to the LRU hashmap and adds the key to the DLL.
    /// if the DLL size exceeds the LRU's capacity, calls DLL remove
    void Add(key_type key, val_type value);

    /// Higher order function for using the cache on top of an expensive function
    /// takes a key (key_type function argument) and a pointer to a function that returns an instance of val_type
    shared_ptr<val_type> CacheFunction(key_type key, val_type (*func)(key_type));

private:
    struct Impl;
    unique_ptr<Impl> pImpl;
};

#endif // LRU_LRUCACHE_H