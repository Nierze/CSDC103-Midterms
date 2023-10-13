////////////////////////////////////////////////////////////////////////
// MELCHOR FILIPPE S. BULANON
////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;


//////////////////////////////
// Node class
//////////////////////////////
class Node {
public:
    
    int value;
    Node* next;
    
    Node(int n, Node* nPtr) {
        this->value = n;
        this->next = nPtr;
    }
};


//////////////////////////////
// Linked List class
//////////////////////////////
class LinkedList {
    Node* head;
    int size;
    
public:

    ///////////////////////////
    // Constructor thingy
    LinkedList(){
        this->head = nullptr;
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
        Node* tempNode = new Node(n, this->head);
        this->head = tempNode;
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
    
    ///////////////////////////
    // Search stuffs and delete it
    void deleteSearchItem(int n) {
        bool notFound = 1;
        Node* prevPtr = nullptr;
        Node* tempPtr = head;
        while(tempPtr != nullptr) {
            
            if (tempPtr->value == n) {
                notFound = 0;
                size--;
                if (prevPtr == nullptr) {
                    Node* tempPtrNext = tempPtr->next;
                    delete(tempPtr);
                    head = tempPtrNext;
                } else {
                    Node* tempPtrNext = tempPtr->next;
                    delete(tempPtr);
                    prevPtr->next = tempPtrNext;
                }
                break;
            }
            
            
            prevPtr = tempPtr;
            tempPtr = tempPtr->next;
        }
        
        if (notFound) {
            cout << "VALUE NOT FOUND";
        } else {
            showValues();
        }
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
        size = 0;
        showValues();
    }
};


int main() {
    LinkedList ll;
    char c;
    int n;
    
    while(cin >> c >> n) {
        switch (c) {
            case 'i': ll.insert(n); break;
            case 'd': ll.deleteItem(); break;
            case 's': ll.searchItem(n); break;
            case 'x': ll.deleteSearchItem(n); break;
            case 'r': ll.OBLITERATELIST(); break;
            default: cout <<"INVALID COMMAND";
        }
        cout << endl;
    }
    return 0;
}