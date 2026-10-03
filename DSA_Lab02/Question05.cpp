// Areefa Samar - CT-25062
// Question 05 (Lab 02)

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularQueue {
private:
    Node* front; 
    Node* rear;  
public:
    CircularQueue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int data) { 
        Node* newNode = new Node(data);
        if (isEmpty()) {
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
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        if (front == rear) { 
            delete front;
            front = nullptr;
            rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front; 
            delete temp;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != front); 
        cout << "(back to front)" << endl;
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Circular Queue: ";
    q.display();

    q.dequeue();
    cout << "After one dequeue: ";
    q.display();

    return 0;
}
