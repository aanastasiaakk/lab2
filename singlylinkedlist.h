#ifndef LAB2_SINGLYLINKEDLIST_H
#define LAB2_SINGLYLINKEDLIST_H
#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

template<typename T>
struct Node {
    T data;
    shared_ptr<Node<T>> next;

    Node(const T& newData) : data(newData), next(nullptr) {}
};

template<typename T>
class SinglyLinkedList {
private:
    shared_ptr<Node<T>> head;
    shared_ptr<Node<T>> tail;
    size_t size;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void addToFront(const T& data) {
        shared_ptr<Node<T>> newNode = make_shared<Node<T>>(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void addToBack(const T& data) {
        shared_ptr<Node<T>> newNode = make_shared<Node<T>>(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void removeFromFront() {
        if (!head)
            throw runtime_error("List is empty");
        head = head->next;
        size--;
        if (!head)
            tail = nullptr;
    }

    void removeFromBack() {
        if (!head)
            throw runtime_error("List is empty");
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            shared_ptr<Node<T>> current = head;
            while (current->next != tail) {
                current = current->next;
            }
            current->next = nullptr;
            tail = current;
        }
        size--;
    }

    const T& getElementAt(int index) const {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range");
        shared_ptr<Node<T>> current = head;
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
            shared_ptr<Node<T>> newNode = make_shared<Node<T>>(data);
            shared_ptr<Node<T>> current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
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
            shared_ptr<Node<T>> current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            current->next = current->next->next;
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
        shared_ptr<Node<T>> current = head;
        while (current) {
            if (current->data == data)
                return true;
            current = current->next;
        }
        return false;
    }

    void display() const {
        shared_ptr<Node<T>> current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
#endif //LAB2_SINGLYLINKEDLIST_H
