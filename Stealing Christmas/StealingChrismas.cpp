#include <stack>
#include <iostream>

using namespace std;

class Node {
public:
    char value;  // Change int to char
    Node* next;
    
    Node(char c, Node* nPtr) {  // Change int to char
        this->value = c;  // Change int to char
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
        std::cout << '[' << size << ']' << ' '; 
        while(tempPtr != nullptr) {
            std::cout << tempPtr->value << ' ';  // Display char value
            tempPtr = tempPtr->next;
        }
        std::cout << std::endl;
    }
    
    ///////////////////////////
    // Insert stuffs
    void insert(char c) {  // Change int to char
        Node* tempNode = new Node(c, this->head);  // Change int to char
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
            std::cout << "THE LIST IS ALREADY EMPTY" << std::endl;
        }
    }
    
    ///////////////////////////
    // Search stuffs
    void searchItem(char c) {  // Change int to char
        bool found = false;
        Node* tempPtr = head;
        while(tempPtr != nullptr) {
            if (tempPtr->value == c) {  // Change int to char
                found = true;
                break;
            }
            tempPtr = tempPtr->next;
        }
        std::cout << (found ? "VALUE FOUND" : "VALUE NOT FOUND") << std::endl;
    }
    
    ///////////////////////////
    // Search stuffs and delete it
    void deleteSearchItem(char c) {  // Change int to char
        bool notFound = true;
        Node* prevPtr = nullptr;
        Node* tempPtr = head;
        while(tempPtr != nullptr) {
            if (tempPtr->value == c) {  // Change int to char
                notFound = false;
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
            std::cout << "VALUE NOT FOUND" << std::endl;
        } else {
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
        head = nullptr;
        size = 0;
    }



    void stealGifts(char giftToSteal) {
        LinkedList newGifts;

        while(head != nullptr) {
            if (head->value == giftToSteal) {
                newGifts.insert(' ');
                this->deleteItem();
                break;
            }
            newGifts.insert(head->value);
            this->deleteItem();
        }

        while (newGifts.head != nullptr) {
            this->insert(newGifts.head->value);
            newGifts.deleteItem();
        }
        this->showValues();
    } 


    
};


int main() {

    LinkedList ll;
    int inputs;
    string str;
    char c;


    while (inputs != 0) {
        cin >> c >> str;
        for (char cc : str) {
            ll.insert(cc);
        }
        ll.stealGifts(c);
        ll.OBLITERATELIST();
        inputs--;
    }











    return 0;
}





