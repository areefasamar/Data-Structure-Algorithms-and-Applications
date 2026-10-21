// Areefa Samar - CT-25062
// Question 02 (Lab 05)

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
private:
    T* data;
    size_t capacity;
    size_t front;
    size_t rear;
    size_t size;

    void resize() {
        size_t newCapacity = capacity * 2;
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[(front + i) % capacity];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
        front = 0;
        rear = size;
    }

public:
    Queue(size_t initialCapacity = 4) : capacity(initialCapacity), front(0), rear(0), size(0) {
        data = new T[capacity];
    }
    ~Queue() {
        delete[] data;
    }
    void enqueue(const T& value) {
        if (size == capacity) {
            resize();
        }
        data[rear] = value;
        rear = (rear + 1) % capacity;
        ++size;
    }
    void dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        front = (front + 1) % capacity;
        --size;
    }
    T& peek() const {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return data[front];
    }
    bool isEmpty() const {
        return size == 0;
    }
    size_t getSize() const {
        return size;
    }
};

int findTheWinner(int n, int k) {
    Queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.enqueue(i);                 
    }

    while (q.getSize() > 1) {
    
        for (int i = 1; i < k; i++) {
            int x = q.peek();
            q.dequeue();
            q.enqueue(x);
        }
        
        q.dequeue();
    }
    return q.peek();                  
}

int main() {
    cout << "n = 5, k = 2, Winner: " << findTheWinner(5, 2) << endl;   
    cout << "n = 6, k = 5, Winner: " << findTheWinner(6, 5) << endl;   
    return 0;
}