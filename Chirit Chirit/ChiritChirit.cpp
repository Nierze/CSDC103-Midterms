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
    // Insert stuffs
    void insert(int n) {
        Node* tempNode = new Node(n, this->head);
        this->head = tempNode;
        size++;
    }
    
    ///////////////////////////
    // Delete stuffs
    void deleteItem() {
        if (this->size > 0) {
            Node* tempNodePtr = this->head->next;
            delete(this->head);
            this->head = tempNodePtr;
            size--;
        } else {
            cout << "THE LIST IS ALREADY EMPTY";
        }

    }

    //////////////////////
    // is it empty?
    bool isEmpty() {
        return size == 0;
    }

    ///////////////////////
    // get head
    int getTop() {
        return this->head->value;
    }

    
};


void convertToOtherBase(int nthBase, int input) {
    string base36 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    LinkedList remainders;
    int quotient = input;

    
    do {
        remainders.insert(base36[quotient % nthBase]);
        quotient = quotient / nthBase;
    } while (quotient != 0);
    
    while (!remainders.isEmpty()) {
        cout << char(remainders.getTop());
        remainders.deleteItem();
    }
}

int main() {
    
    int input, nBase;
    
    while (cin >> input >> nBase) {
        convertToOtherBase(nBase, input);
        cout << endl;
    }
    
    
    

    return 0;
}