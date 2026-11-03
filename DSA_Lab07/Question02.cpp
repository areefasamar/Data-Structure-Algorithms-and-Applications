// Areefa Samar - CT-25062
// Question 02 (Lab 07)

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortIterative(int arr[], int n) {
    for (int size = 1; size < n; size = size * 2) {
        for (int left = 0; left < n - 1; left += 2 * size) {
            int mid = left + size - 1;
            int right = left + 2 * size - 1;
            if (mid >= n - 1)
                break;
            if (right > n - 1)
                right = n - 1;
            merge(arr, left, mid, right);
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, arr_size);

    mergeSortIterative(arr, arr_size);

    cout << "Sorted array: ";
    printArray(arr, arr_size);

    return 0;
}
