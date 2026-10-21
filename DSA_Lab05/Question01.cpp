// Areefa Samar - CT-25062
// Question 01 (Lab 05)

#include <iostream>
using namespace std;

class MyCircularDeque {
private:
    int* data;
    int capacity;
    int front;   
    int rear;    
    int size;

public:
    MyCircularDeque(int k) {
        capacity = k;
        data = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    ~MyCircularDeque() {
        delete[] data;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;   
        data[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        data[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;    
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return data[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return data[(rear - 1 + capacity) % capacity];
    }
};

int main() {
    MyCircularDeque d(3);
    cout << boolalpha;
    cout << "insertLast(1): "  << d.insertLast(1) << endl;  
    cout << "insertLast(2): "  << d.insertLast(2) << endl;  
    cout << "insertFront(3): " << d.insertFront(3) << endl;  
    cout << "insertFront(4): " << d.insertFront(4) << endl;  
    cout << "getRear(): "      << d.getRear() << endl;       
    cout << "isFull(): "       << d.isFull() << endl;        
    cout << "deleteLast(): "   << d.deleteLast() << endl;    
    cout << "insertFront(4): " << d.insertFront(4) << endl;  
    cout << "getFront(): "     << d.getFront() << endl;     
    return 0;
}