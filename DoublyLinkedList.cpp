#include "DoublyLinkedList.h"

template<typename key_type>
DoublyLinkedList<key_type>::DoublyLinkedList() : size(0), head(nullptr), tail(nullptr) {}

template<typename key_type>
DoublyLinkedList<key_type>::~DoublyLinkedList() = default;

template<typename key_type>
void DoublyLinkedList<key_type>::Insert(key_type key) {
    shared_ptr<dll_node<key_type>> new_node = shared_ptr<dll_node<key_type>>(new dll_node<key_type>);
    new_node->key = key;

    if (head) {
        new_node->next = head;
        head->prev = new_node;
    }
    head = new_node;

    if (!tail) {
        tail = new_node;
    }

    size++;
}

template<typename key_type>
key_type DoublyLinkedList<key_type>::Remove() {
    if (!tail) return key_type(); // Return default if list is empty

    auto removed_key = tail->key;
    tail = tail->prev;

    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }

    size--;
    return removed_key;
}

template<typename key_type>
void DoublyLinkedList<key_type>::MoveToHead(key_type key) {
    if (!head || head->key == key) return;

    auto curr = head;
    while (curr && curr->key != key) {
        curr = curr->next;
    }
    // if the key was found
    if (curr) {
        curr->prev->next = curr->next;
        // removing the node from its current position
        if (tail == curr) {
            // if curr is tail, update the tail node
            tail = curr->prev;
            tail->next = nullptr;
        } else {
            // otherwise, update next and previous nodes to remove it
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
        }
        // adding it to the head of the list
        curr->next = head;
        curr->prev = nullptr;
        head->prev = curr;
        head = curr;
    }
}

template<typename key_type>
int DoublyLinkedList<key_type>::GetSize() const {
    return size;
}

// this function is primarily for easily testing capacity
template<typename key_type>
shared_ptr<dll_node<key_type>> DoublyLinkedList<key_type>::GetNth(int idx) {
    if (idx >= size) return nullptr;

    auto curr = head;
    for (int i = 0; i < idx; ++i) {
        curr = curr->next;
    }
    return curr;
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<string>;