// Areefa Samar - CT-25062
// Question 01 (Lab 07)

#include <iostream>
#include <stack>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortIterative(int arr[], int low, int high) {
    stack<int> s;
    s.push(low);
    s.push(high);

    while (!s.empty()) {
        high = s.top();
        s.pop();
        low = s.top();
        s.pop();

        int pi = partition(arr, low, high);

        if (pi - 1 > low) {
            s.push(low);
            s.push(pi - 1);
        }
        if (pi + 1 < high) {
            s.push(pi + 1);
            s.push(high);
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, n);

    quickSortIterative(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
