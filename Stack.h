#ifndef LAB2_STACK_H
#define LAB2_STACK_H
#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

template<typename T>
class StackArray {
private:
    T* arr;
    int top;
    int capacity;

public:
    StackArray(int cap) : capacity(cap), top(-1) {
        arr = new T[capacity];
    }

    ~StackArray() {
        delete[] arr;
    }

    void push(const T& item) {
        if (isFull()) {
            throw runtime_error("Stack is full");
        }
        arr[++top] = item;
    }

    T pop() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return arr[top--];
    }

    T peek() const {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return arr[top];
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == capacity - 1;
    }
};

template<typename T>
class StackLinkedList {
private:
    Node<T>* top;

public:
    StackLinkedList() : top(nullptr) {}

    ~StackLinkedList() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& item) {
        Node<T>* newNode = new Node<T>(item);
        newNode->next = top;
        top = newNode;
    }

    T pop() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        T item = top->data;
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        return item;
    }

    T peek() const {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};


#endif //LAB2_STACK_H
