//
// Created by Nastya on 24/04/2024.
//

#include "Doublelinkedlist.h"

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template<typename T>
void DoublyLinkedList<T>::append(const T& value) {
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template<typename T>
void DoublyLinkedList<T>::prepend(const T& value) {
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
    newNode->next = head;
    if (head) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
}

template<typename T>
void DoublyLinkedList<T>::removeFirst() {
    if (!head) {
        throw std::runtime_error("List is empty");
    }
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
}

template<typename T>
void DoublyLinkedList<T>::removeLast() {
    if (!head) {
        throw std::runtime_error("List is empty");
    }
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
}

template<typename T>
void DoublyLinkedList<T>::insertAt(int index, const T& value) {
    if (index < 0 || index > size()) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        prepend(value);
        return;
    }
    if (index == size()) {
        append(value);
        return;
    }
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
    std::shared_ptr<Node<T>> temp = head;
    for (int i = 0; i < index - 1; ++i) {
        temp = temp->next;
    }
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
}

template<typename T>
void DoublyLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= size()) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        removeFirst();
        return;
    }
    if (index == size() - 1) {
        removeLast();
        return;
    }
    std::shared_ptr<Node<T>> temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
}

template<typename T>
T& DoublyLinkedList<T>::operator[](int index) {
    if (index < 0 || index >= size()) {
        throw std::out_of_range("Index out of range");
    }
    std::shared_ptr<Node<T>> temp;
    if (index < size() / 2) {
        temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
    } else {
        temp = tail;
        for (int i = size() - 1; i > index; --i) {
            temp = temp->prev;
        }
    }
    return temp->data;
}

template<typename T>
int DoublyLinkedList<T>::size() {
    int count = 0;
    std::shared_ptr<Node<T>> temp = head;
    while (temp) {
        ++count;
        temp = temp->next;
    }
    return count;
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty() {
    return head == nullptr;
}

template<typename T>
bool DoublyLinkedList<T>::search(const T& value) {
    std::shared_ptr<Node<T>> temp = head;
    while (temp) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template<typename T>
void DoublyLinkedList<T>::print() {
    std::shared_ptr<Node<T>> temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}