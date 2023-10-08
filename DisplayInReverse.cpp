#include <cstddef>
#include <iostream>

using namespace std;


//////////////////////////////
// Node class
//////////////////////////////
class Node {
public:
    
    int value;
    Node* next;
    Node* prev;
    
    Node(int n, Node* nPtr, Node* pPtr) {
        this->value = n;
        this->next = nPtr;
        this->prev = pPtr;
    }
};


//////////////////////////////
// Linked List class
//////////////////////////////
class LinkedList {
    Node* head;
    Node* tail;
    int size;
    
public:

    ///////////////////////////
    // Constructor thingy
    LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }
    
    ///////////////////////////
    // Display stuffs
    void showValues() {
        Node* tempPtr = this->head;
        cout << '[' << size << ']' << ' '; 
        while(tempPtr != NULL) {
            cout << tempPtr->value << ' ';
            tempPtr = tempPtr->next;
        }
    }
    
    ///////////////////////////
    // Insert stuffs
    void insert(int n) {
        Node* tempNode = new Node(n, this->head, this->tail);
        if (this->size == 0) {
            this->head = tempNode;
            this->tail = tempNode;
        } else {
            this->head->prev = tempNode;
            this->head = tempNode;
        }
        size++;
        showValues();
    }
    
    ///////////////////////////
    // Delete stuffs
    void deleteItem() {
        if (this->size > 0) {
            Node* tempNodePtr = this->head->next;
            delete(this->head);
            this->head = tempNodePtr;
            size--;
            showValues();
        } else {
            cout << "THE LIST IS ALREADY EMPTY";
        }

    }
    
    ///////////////////////////
    // Search stuffs
    void searchItem(int n) {
        bool found = 0;
        Node* tempPtr = head;
        while(tempPtr != NULL) {
            if (tempPtr->value == n) {
                found = 1;
                break;
            }
            tempPtr = tempPtr->next;
        }
        cout << ((found) ? "VALUE FOUND" : "VALUE NOT FOUND");
        
    }
    
    
    //////////////////////////////////
    // O B L I T E R A T E S the list
    void OBLITERATELIST(){
        Node* tempNode = head;
        while (tempNode != nullptr) {
            Node* tempNext = tempNode->next;
            delete(tempNode);
            tempNode = tempNext;
        }
        head = NULL;
        tail = NULL;
        size = 0;
        showValues();
    }

    ////////////////////////////
    // Reverse list
    void reverse() {
        Node* loopTempPtr = this->head;
        Node* tempPtr = this->head;
        this->head = this->tail;
        this->tail = tempPtr;

        while(loopTempPtr != NULL) {
            // Hold the 'next' of the current ptr
            Node* nextHolder = loopTempPtr->next;

            // Variable for swapping
            Node* tempSwapPtr = loopTempPtr->next;

            // The swap
            loopTempPtr->next = loopTempPtr->prev;
            loopTempPtr->prev = tempSwapPtr;

            loopTempPtr = nextHolder;
        }
        showValues();
    }
};

int main() {
    LinkedList ll;
    ll.insert(69);
    cout << endl;
    ll.insert(420);
    cout << endl;
    ll.insert(4);
    cout << endl;
    ll.insert(5);
    cout << endl;
    ll.reverse();
    return 0;
}