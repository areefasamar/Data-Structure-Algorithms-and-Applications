// Areefa Samar - CT-25062
// Question 01 (Lab 03)

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == NULL) {           
            front = newNode;
            rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;       
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        if (front == rear) {        
            delete front;
            front = NULL;
            rear = NULL;
            return;
        }
        Node* temp = front;
        front = front->next;
        rear->next = front;            
        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cout << "Queue: ";
    cq.display();

    cq.dequeue();
    cout << "After dequeue: ";
    cq.display();

    return 0;
}