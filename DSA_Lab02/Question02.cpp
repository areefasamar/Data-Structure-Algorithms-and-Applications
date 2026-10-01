// Areefa Samar - CT-25062
// Question 02 (Lab 02)

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

    // Since the list is sorted, duplicates are always next to each other
    void deleteDuplicates() {
        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->data == temp->next->data) {
                Node* duplicate = temp->next;
                temp->next = temp->next->next; // skip the duplicate node
                delete duplicate;
            } else {
                temp = temp->next; // only move forward if no duplicate removed
            }
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

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(3);

    cout << "Original List: ";
    list.display();

    list.deleteDuplicates();

    cout << "After Removing Duplicates: ";
    list.display();

    return 0;
}