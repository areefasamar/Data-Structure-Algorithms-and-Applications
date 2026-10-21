// Areefa Samar - CT-25062
// Question 02 (Lab 03)

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

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = NULL;
        rear = NULL;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (front == NULL) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertRear(int value) {
        Node* newNode = new Node(value);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void deleteFront() {
        if (front == NULL) {
            cout << "Deque is empty." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front != NULL) front->prev = NULL;
        else rear = NULL;             
        delete temp;
    }

    void deleteRear() {
        if (rear == NULL) {
            cout << "Deque is empty." << endl;
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        if (rear != NULL) rear->next = NULL;
        else front = NULL;            
        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Deque is empty." << endl;
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    cout << "Deque: ";
    dq.display();

    dq.deleteRear();
    cout << "After deleteRear: ";
    dq.display();

    dq.deleteFront();
    cout << "After deleteFront: ";
    dq.display();

    return 0;
}