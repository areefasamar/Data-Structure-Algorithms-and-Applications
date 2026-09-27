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


Node* mergeTwoLists(Node* list1, Node* list2) {
    Node* dummy = new Node(0);   
    Node* tail = dummy;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != nullptr) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    Node* mergedHead = dummy->next;
    delete dummy;
    return mergedHead;
}

int main() {
    LinkedList list1, list2;
    list1.insert(1);
    list1.insert(2);
    list1.insert(4);

    list2.insert(1);
    list2.insert(3);
    list2.insert(4);

    cout << "List1: ";
    list1.display();
    cout << "List2: ";
    list2.display();

    Node* mergedHead = mergeTwoLists(list1.head, list2.head);

    cout << "Merged List: ";
    Node* temp = mergedHead;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}
