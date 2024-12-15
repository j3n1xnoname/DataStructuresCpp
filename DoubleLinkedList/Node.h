#ifndef NODE_H
#define NODE_H

// The node of list
template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    explicit Node(T _data, Node* _prev = nullptr, Node* _next = nullptr) : data(_data), prev(_prev), next(_next) {}
};

#endif //NODE_H
