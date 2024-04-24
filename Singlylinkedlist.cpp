
#include "Singlylinkedlist.h"

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr) {}

template<typename T>
void SinglyLinkedList<T>::append(const T& value) {
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
    if (!head) {
        head = newNode;
    } else {
        std::shared_ptr<Node<T>> temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

template<typename T>
void SinglyLinkedList<T>::prepend(const T& value) {
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
    newNode->next = head;
    head = newNode;
}

template<typename T>
void SinglyLinkedList<T>::removeFirst() {
    if (!head) {
        throw std::runtime_error("List is empty");
    }
    head = head->next;
}

template<typename T>
void SinglyLinkedList<T>::removeLast() {
    if (!head) {
        throw std::runtime_error("List is empty");
    }
    if (!head->next) {
        head = nullptr;
        return;
    }
    std::shared_ptr<Node<T>> temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    temp->next = nullptr;
}

template<typename T>
void SinglyLinkedList<T>::insertAt(int index, const T& value) {
    if (index < 0 || index > size()) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        prepend(value);
        return;
    }
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
    std::shared_ptr<Node<T>> temp = head;
    for (int i = 0; i < index - 1; ++i) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

template<typename T>
void SinglyLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= size()) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        removeFirst();
        return;
    }
    std::shared_ptr<Node<T>> temp = head;
    for (int i = 0; i < index - 1; ++i) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

template<typename T>
T& SinglyLinkedList<T>::operator[](int index) {
    if (index < 0 || index >= size()) {
        throw std::out_of_range("Index out of range");
    }
    std::shared_ptr<Node<T>> temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    return temp->data;
}

template<typename T>
int SinglyLinkedList<T>::size() {
    int count = 0;
    std::shared_ptr<Node<T>> temp = head;
    while (temp) {
        ++count;
        temp = temp->next;
    }
    return count;
}

template<typename T>
bool SinglyLinkedList<T>::isEmpty() {
    return head == nullptr;
}

template<typename T>
bool SinglyLinkedList<T>::search(const T& value) {
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
void SinglyLinkedList<T>::print() {
    std::shared_ptr<Node<T>> temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}