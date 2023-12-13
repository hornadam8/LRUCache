#include "LruCache.h"
#include <iostream>
#include <string>

template<typename key_type, typename val_type>
struct LruCache<key_type, val_type>::Impl {
    std::map<key_type, val_type> hashmap;
    DoublyLinkedList<key_type> queue;
    int capacity;

    Impl(int cap) : capacity(cap) {}
};

template<typename key_type, typename val_type>
LruCache<key_type, val_type>::LruCache(int cap) : pImpl(make_unique<Impl>(cap)) {}

template<typename key_type, typename val_type>
LruCache<key_type, val_type>::~LruCache() = default;

template<typename key_type, typename val_type>
shared_ptr<val_type> LruCache<key_type, val_type>::Get(key_type key) {
    if (pImpl->hashmap.count(key)) {
        val_type val = pImpl->hashmap[key];
        pImpl->queue.MoveToHead(key);
        return make_shared<val_type>(val);
    }
    return nullptr;
}

template<typename key_type, typename val_type>
void LruCache<key_type, val_type>::Add(key_type key, val_type value) {
    pImpl->hashmap[key] = value;
    pImpl->queue.Insert(key);
    if (pImpl->queue.GetSize() > pImpl->capacity) {
        key_type removed = pImpl->queue.Remove();
        pImpl->hashmap.erase(removed);
    }
}

template<typename key_type, typename val_type>
shared_ptr<val_type> LruCache<key_type, val_type>::CacheFunction(key_type key, val_type (*func)(key_type)) {
    if (pImpl->hashmap.count(key)) {
        return Get(key);
    }
    val_type val = func(key);
    Add(key, val);
    return make_shared<val_type>(val);
}

// Explicit template instantiation
template class LruCache<int, long>;
template class LruCache<int, int>;
template class LruCache<int, bool>;
template class LruCache<int, map<int, int> >;
template class LruCache<int, map<int, bool> >;
template class LruCache<string, string>;
template class LruCache<string, map<string, string> >;
// Add more explicit instantiations if needed for other types