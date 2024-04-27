#ifndef LAB2_DOUBLYLINKEDLIST_H
#define LAB2_DOUBLYLINKEDLIST_H
#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

template<typename T>
struct DoubleNode {
    T data;
    shared_ptr<DoubleNode<T>> prev;
    shared_ptr<DoubleNode<T>> next;

    DoubleNode(const T& newData) : data(newData), prev(nullptr), next(nullptr) {}
};

template<typename T>
class DoublyLinkedList {
private:
    shared_ptr<DoubleNode<T>> head;
    shared_ptr<DoubleNode<T>> tail;
    size_t size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void addToFront(const T& data) {
        shared_ptr<DoubleNode<T>> newNode = make_shared<DoubleNode<T>>(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void addToBack(const T& data) {
        shared_ptr<DoubleNode<T>> newNode = make_shared<DoubleNode<T>>(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void removeFromFront() {
        if (!head)
            throw runtime_error("List is empty");
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        size--;
    }

    void removeFromBack() {
        if (!head)
            throw runtime_error("List is empty");
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        size--;
    }

    const T& getElementAt(int index) const {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range");
        shared_ptr<DoubleNode<T>> current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    void insertElementAt(const T& data, int index) {
        if (index < 0 || index > size)
            throw out_of_range("Index out of range");
        if (index == 0) {
            addToFront(data);
        } else if (index == size) {
            addToBack(data);
        } else {
            shared_ptr<DoubleNode<T>> newNode = make_shared<DoubleNode<T>>(data);
            shared_ptr<DoubleNode<T>> current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            size++;
        }
    }

    void removeElementAt(int index) {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range");
        if (index == 0) {
            removeFromFront();
        } else if (index == size - 1) {
            removeFromBack();
        } else {
            shared_ptr<DoubleNode<T>> current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            current->next = current->next->next;
            current->next->prev = current;
            size--;
        }
    }

    size_t getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool search(const T& data) const {
        shared_ptr<DoubleNode<T>> current = head;
        while (current) {
            if (current->data == data)
                return true;
            current = current->next;
        }
        return false;
    }

    void display() const {
        shared_ptr<DoubleNode<T>> current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

#endif //LAB2_DOUBLYLINKEDLIST_H
