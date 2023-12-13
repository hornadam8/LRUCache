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

    if (curr) {
        if (curr->prev) curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;

        if (tail == curr) tail = curr->prev;

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

template<typename key_type>
std::shared_ptr<dll_node<key_type>> DoublyLinkedList<key_type>::GetNth(int idx) {
    if (idx >= size) return nullptr;

    auto curr = head;
    for (int i = 0; i < idx; ++i) {
        curr = curr->next;
    }
    return curr;
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<string>;