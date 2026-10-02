// Areefa Samar - CT-25062
// Question 03 (Lab 02)

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

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

void splitList(Node* source, Node** frontRef, Node** backRef) {
    Node* slow = source;
    Node* fast = source->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr; 
}

Node* sortedMerge(Node* a, Node* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    Node* result = nullptr;
    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void mergeSort(Node** headRef) {
    Node* head = *headRef;
    if (head == nullptr || head->next == nullptr) {
        return; 
    }

    Node* a;
    Node* b;
    splitList(head, &a, &b); 

    mergeSort(&a); 
    mergeSort(&b);

    *headRef = sortedMerge(a, b); 
}

int main() {
    LinkedList list;
    list.insert(4);
    list.insert(2);
    list.insert(1);
    list.insert(3);

    cout << "Original List: ";
    list.display();

    mergeSort(&list.head);

    cout << "Sorted List: ";
    list.display();

    return 0;
}
