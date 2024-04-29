#ifndef LAB2_QUEUE_H
#define LAB2_QUEUE_H
#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

template<typename T>
class QueueArray {
private:
    T* arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    QueueArray(int capacity) {
        this->capacity = capacity;
        arr = new T[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~QueueArray() {
        delete[] arr;
    }

    void Enqueue(const T& item) {
        if (isFull()) {
            throw overflow_error("Queue is full");
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
    }

    T Dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        T item = arr[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    T Peek() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
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
class QueueLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    QueueLinkedList() : head(nullptr), tail(nullptr) {}

    ~QueueLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void Enqueue(const T& item) {
        Node* newNode = new Node(item);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    T Dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        T item = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) {
            tail = nullptr;
        }
        return item;
    }

    T Peek() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        return head->data;
    }

    bool isEmpty() const {
        return !head;
    }

};

#endif //LAB2_QUEUE_H
