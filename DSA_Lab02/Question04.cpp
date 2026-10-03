// Areefa Samar - CT-25062
// Question 04 (Lab 02)

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

    bool isPalindrome() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        int* values = new int[count];
        temp = head;
        int index = 0;
        while (temp != nullptr) {
            values[index] = temp->data;
            index++;
            temp = temp->next;
        }

        int left = 0;
        int right = count - 1;
        bool result = true;
        while (left < right) {
            if (values[left] != values[right]) {
                result = false;
                break;
            }
            left++;
            right--;
        }

        delete[] values;
        return result;
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(2);
    list.insert(1);

    cout << "List: ";
    list.display();

    if (list.isPalindrome()) {
        cout << "true (the list is a palindrome)" << endl;
    } else {
        cout << "false (the list is not a palindrome)" << endl;
    }

    return 0;
}
