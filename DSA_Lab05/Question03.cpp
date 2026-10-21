// Areefa Samar - CT-25062
// Question 03 (Lab 05)

#include <iostream>
#include <string>
#include <vector>
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

class Call {
public:
    int callID;
    int arrivalTime;
    string customerName;
    int duration;         

    Call() {
        callID = 0;
        arrivalTime = 0;
        customerName = "";
        duration = 0;
    }

    Call(int id, int arrival, string name, int dur) {
        callID = id;
        arrivalTime = arrival;
        customerName = name;
        duration = dur;
    }
};

class CallCenter {
private:
    Queue<Call> callQueue;        
    int CSR;                      
    vector<bool> available;       
    vector<int> endTime;         
    vector<int> currentCall;     

public:
    CallCenter(int numCSR) {
        CSR = numCSR;
        available.assign(CSR, true);
        endTime.assign(CSR, 0);
        currentCall.assign(CSR, 0);
    }

    void addCall(const Call& c) {
        callQueue.enqueue(c);
        cout << "Time " << c.arrivalTime << ": Call " << c.callID
             << " from " << c.customerName << " added to the queue." << endl;
    }

    void processCalls(int time) {
 
        for (int i = 0; i < CSR; i++) {
            if (!available[i] && time >= endTime[i]) {
                available[i] = true;
                cout << "Time " << time << ": CSR " << i + 1
                     << " completed Call " << currentCall[i] << "." << endl;
            }
        }

        for (int i = 0; i < CSR; i++) {
            if (available[i] && !callQueue.isEmpty()) {
                Call c = callQueue.peek();
                callQueue.dequeue();
                available[i] = false;
                endTime[i] = time + c.duration;
                currentCall[i] = c.callID;
                cout << "Time " << time << ": CSR " << i + 1
                     << " started Call " << c.callID << " (" << c.customerName
                     << "), will take " << c.duration << " units." << endl;
            }
        }
    }

    bool allDone() {
        if (!callQueue.isEmpty()) return false;
        for (int i = 0; i < CSR; i++) {
            if (!available[i]) return false;
        }
        return true;
    }
};

int main() {
    CallCenter center(2);         

    Call calls[5] = {
        Call(1, 0, "Ali", 4),
        Call(2, 1, "Sara", 3),
        Call(3, 2, "Ahmed", 2),
        Call(4, 3, "Hina", 5),
        Call(5, 6, "Omar", 1)
    };
    int totalCalls = 5;
    int next = 0;

    int time = 0;
    while (next < totalCalls || !center.allDone()) {
        while (next < totalCalls && calls[next].arrivalTime == time) {
            center.addCall(calls[next]);
            next++;
        }
        center.processCalls(time);
        time++;
    }

    cout << "All calls handled." << endl;
    return 0;
}