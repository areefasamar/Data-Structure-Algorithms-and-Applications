// Areefa Samar - CT-25062
// Question 06 (Lab 02)

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

class Stack {
private:
    Node* top; 

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int data) { 
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    void pop() { 
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() { 
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;
    }

    void display() {
        Node* temp = top;
        cout << "Top -> ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack: ";
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "After popping: ";
    s.display();

    return 0;
}