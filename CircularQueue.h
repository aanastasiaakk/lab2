#ifndef LAB2_CIRCULARQUEUE_H
#define LAB2_CIRCULARQUEUE_H
#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;


template<typename T>
class CircularQueueArray {
private:
    T* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    CircularQueueArray(int cap) : capacity(cap), front(0), rear(-1), size(0) {
        arr = new T[capacity];
    }

    ~CircularQueueArray() {
        delete[] arr;
    }

    void enqueue(const T& item) {
        if (isFull()) {
            throw runtime_error("Queue is full");
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        T item = arr[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    T peek() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return arr[front];
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }
};


template<typename T>
class CircularQueueLinkedList {
private:
    Node<T>* front;
    Node<T>* rear;
    int size;
    int capacity;

public:
    CircularQueueLinkedList(int cap) : capacity(cap), size(0), front(nullptr), rear(nullptr) {}

    ~CircularQueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const T& item) {
        if (isFull()) {
            throw runtime_error("Queue is full");
        }
        Node<T>* newNode = new Node<T>(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        rear->next = front;
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        T item = front->data;
        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } else {
            Node<T>* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
        size--;
        return item;
    }

    T peek() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return front->data;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }
};

#endif //LAB2_CIRCULARQUEUE_H
