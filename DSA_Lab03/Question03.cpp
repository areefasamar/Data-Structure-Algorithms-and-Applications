// Areefa Samar - CT-25062
// Question 03 (Lab 03)

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void concatenate(DoublyLinkedList &other) {
        Node* temp = other.head;
        while (temp != NULL) {
            insertAtEnd(temp->data);
            temp = temp->next;
        }
    }

    void displayForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList L, M, N;

    for (int i = 2; i <= 10; i += 2) L.insertAtEnd(i);  
    for (int i = 1; i <= 9; i += 2)  M.insertAtEnd(i);  
    cout << "List L: ";
    L.displayForward();

    cout << "List M: ";
    M.displayForward();

    N.concatenate(L);
    N.concatenate(M);

    cout << "List N (L + M): ";
    N.displayForward();

    return 0;
}