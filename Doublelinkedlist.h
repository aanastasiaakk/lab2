

#ifndef LAB2_DOUBLELINKEDLIST_H
#define LAB2_DOUBLELINKEDLIST_H


#include <memory>
#include <stdexcept>
#include <iostream>

template<typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> prev;
    std::shared_ptr<Node<T>> next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

template<typename T>
class DoublyLinkedList {
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;

public:
    DoublyLinkedList();
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

#endif //LAB2_DOUBLELINKEDLIST_H
