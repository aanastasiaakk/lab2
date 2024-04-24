//
// Created by Nastya on 24/04/2024.
//

#ifndef LAB2_SINGLYLINKEDLIST_H
#define LAB2_SINGLYLINKEDLIST_H

#include <memory>
#include <stdexcept>
#include <iostream>

template<typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template<typename T>
class SinglyLinkedList {
private:
    std::shared_ptr<Node<T>> head;

public:
    SinglyLinkedList();
    void append(const T& value);
    void prepend(const T& value);
    void removeFirst();
    void removeLast();
    void insertAt(int index, const T& value);
    void removeAt(int index);
    T& operator[](int index);
    int size();
    bool isEmpty();
    bool search(const T& value);
    void print();
};

#endif //LAB2_SINGLYLINKEDLIST_H
