#include <iostream>
#include <memory>
#include <stdexcept>
#include "singlylinkedlist.h"
#include "doublylinkedlist.h"

using namespace std;

int main(){
        try {
            SinglyLinkedList<int> sll;
            sll.addToBack(8);
            sll.addToBack(2);
            sll.addToBack(3);
            cout << "Singly Linked List: ";
            sll.display();
            cout << "Size: " << sll.getSize() << endl;


            DoublyLinkedList<string> dll;
            dll.addToFront("World");
            dll.addToFront("Hello");
            dll.addToBack("!");
            cout << "Doubly Linked List: ";
            dll.display();
            cout << "Size: " << dll.getSize() << endl;

            sll.insertElementAt(5, 1);
            cout << "After inserting 5 at index 1: ";
            sll.display();
            sll.removeElementAt(2);
            cout << "After removing element at index 2: ";
            sll.display();

            if (dll.search("Welcome")) {
                cout << "Element found in doubly linked list." << endl;
            } else {
                cout << "Element not found in doubly linked list." << endl;
            }
        } catch (const exception& e) {
            cerr << "Exception: " << e.what() << std::endl;
        }

        return 0;

}
