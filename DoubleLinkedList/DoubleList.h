#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include "Node.h"

template <typename  T>
class DoubleList {
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    DoubleList() : head(nullptr), tail(nullptr), size(0) {}

    [[nodiscard]] int getSize() const {return size;}
    [[nodiscard]] bool isEmpty() const {return size == 0;}

    void pop_front();
    void pop_back();
    void push_front(T elem);
    void push_back(T elem);
    void insert(int index, T elem);
    void erase(int index);
    void clear();
};

template <typename T>
void DoubleList<T>::clear() {
    while (size != 0) {
        pop_back();
    }
}


template <typename T>
void DoubleList<T>::erase(int index) {
    if (size == 0) {
        return;
    }

    if (index == 0) {
        pop_front();
    }
    else if (index == size - 1) {
        pop_back();
    }
    else {
        int currentIndex = 0;
        Node<T>* cur = head;
        // We can do it an optimization, we can start to find index from head or tail.
        while (cur != nullptr) {
            if (index == currentIndex) {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete cur;
                break;
            }
            cur = cur->next;
            currentIndex++;
        }

        size--;
    }
}

// Indexing starts with zero
template <typename T>
void DoubleList<T>::insert(const int index, T elem) {
    if (size == 0) {
        head = new Node<T>(elem);
        tail = head;
        size++;
        return;
    }

    if (index == 0) {
        push_front(elem);
    }
    else if (index > size - 1) {
        push_back(elem);
    }
    else {
        int currentIndex = 0;
        Node<T>* cur = head;
        // We can do it an optimization, we can start to find index from head or tail.
        while (cur != nullptr) {
            if (currentIndex == index) {
                auto newNode = new Node<T>(elem, cur->prev, cur);
                cur->prev->next = newNode;
                cur->prev = newNode;
                break;
            }
            cur = cur->next;
            currentIndex++;
        }

        size++;
    }
}


template <typename T>
void DoubleList<T>::pop_back() {
    if (size == 0) {
        return;
    }

    const Node<T>* nodeDel = tail;
    tail = tail->prev;
    if (tail != nullptr)
        tail->next = nullptr;
    delete nodeDel;
    size--;
    // If we don't do that, head or tail will be contained an address which refer to deleted datas.
    if (size == 0) {
        head = nullptr;
        tail = head;
    }
}

template <typename T>
void DoubleList<T>::pop_front() {
    if (size == 0) {
        return;
    }

    const Node<T>* nodeDel = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    delete nodeDel;
    size--;
    // If we don't do that, head or tail will be contained an address which refer to deleted datas.
    if (size == 0) {
        head = nullptr;
        tail = head;
    }
}

template <typename T>
void DoubleList<T>::push_back(T elem) {
    if (size == 0) {
        head = new Node<T>(elem);
        tail = head;
    }
    else {
        tail->next = new Node<T>(elem, tail, nullptr);
        tail = tail->next;
    }
    size++;
}

template <typename T>
void DoubleList<T>::push_front(T elem) {
    if (size == 0) {
        head = new Node<T>(elem);
        tail = head;
    }
    else {
        head->prev = new Node<T>(elem, nullptr, head);
        head = head->prev;
    }
    size++;
}

#endif //DOUBLELIST_H
