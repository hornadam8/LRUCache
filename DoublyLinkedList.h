#ifndef LRU_DOUBLYLINKEDLIST_H
#define LRU_DOUBLYLINKEDLIST_H

#include <memory>

template<typename key_type>
struct dll_node {
    key_type key;
    std::shared_ptr<dll_node<key_type>> next;
    std::shared_ptr<dll_node<key_type>> prev;
};

template<typename key_type>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void Insert(key_type key);
    void MoveToHead(key_type key);
    key_type Remove();
    std::shared_ptr<dll_node<key_type>> GetNth(int idx);
    int GetSize() const;

private:
    int size;
    std::shared_ptr<dll_node<key_type>> head;
    std::shared_ptr<dll_node<key_type>> tail;
};

#endif //LRU_DOUBLYLINKEDLIST_H