#include <iostream>
#include <memory>
#include <stdexcept>
#include "singlylinkedlist.h"
#include "doublylinkedlist.h"
#include "Queue.h"
#include "CircularQueue.h"
#include "Stack.h"

using namespace std;

int main(){
        try {
            SinglyLinkedList<int> sll;
            sll.addToBack(8);
            sll.addToBack(90);
            sll.addToBack(3);
            cout << "Singly Linked List: ";
            sll.display();
            cout << "Size: " << sll.getSize() << endl;


            DoublyLinkedList<string> dll;
            dll.addToFront("I");
            dll.addToFront("am");
            dll.addToBack("Anastasia");
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
            cout << endl;

            QueueLinkedList<string>queueLinkedList;
            queueLinkedList.Enqueue("HI");
            queueLinkedList.Enqueue("CAT");
            queueLinkedList.Enqueue("DOG");
            cout << "Peek: " << queueLinkedList.Peek() << endl;
            cout << "Dequeue: " << queueLinkedList.Dequeue() << endl;
            cout << "Peek: " << queueLinkedList.Peek() << endl;
            cout << endl;

            CircularQueueArray<int> circularQueueArray(5);
            circularQueueArray.enqueue(1);
            circularQueueArray.enqueue(6);
            circularQueueArray.enqueue(8);
            cout << "Front: " << circularQueueArray.peek() << endl;
            cout << "Dequeuing: " << circularQueueArray.dequeue() << endl;
            cout << "Front after dequeue: " << circularQueueArray.peek() << endl;
            cout << endl;

            StackArray<int> stackArray(3 );
            stackArray.push(1);
            stackArray.push(2);
            stackArray.push(3);
            cout << "Top: " << stackArray.peek() << endl;
            cout << "Popping: " << stackArray.pop() << endl;
            cout << "Top after pop: " << stackArray.peek() << endl;
            cout << endl;


        } catch (const exception& e) {
            cerr << "Exception: " << e.what() << endl;

        }

        return 0;

}
