// Areefa Samar - CT-25062
// Question 04 (Lab 03)

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

    void sortDescending() {
        if (head == NULL) return;
        bool swapped = true;
        while (swapped) {
            swapped = false;
            Node* temp = head;
            while (temp->next != NULL) {
                if (temp->data < temp->next->data) {
                    int t = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = t;
                    swapped = true;
                }
                temp = temp->next;
            }
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
    N.concatenate(L);
    N.concatenate(M);

    cout << "List N before sorting: ";
    N.displayForward();

    N.sortDescending();

    cout << "List N sorted descending: ";
    N.displayForward();

    return 0;
}