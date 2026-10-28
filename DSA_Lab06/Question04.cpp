// Areefa Samar - CT-25062
// Question 04 (Lab 06)

#include <iostream>
using namespace std;

void flip(int* arr, int k){
    int i = 0, j = k - 1;
    while (i < j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int pancakeSort(int* arr, int n, int* flips){
    int count = 0;
    int size, i, max_idx;

    for (size = n; size > 1; size--){
    
        max_idx = 0;
        for (i = 1; i < size; i++)
            if (arr[i] > arr[max_idx])
                max_idx = i;

       
        if (max_idx == size - 1)
            continue;


        if (max_idx != 0){
            flip(arr, max_idx + 1);
            flips[count++] = max_idx + 1;
        }
        flip(arr, size);
        flips[count++] = size;
    }
    return count;
}

void printArray(int* arr, int size){
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int N, i;
    cout << "Enter number of elements: ";
    cin >> N;
    int* arr = new int[N];
    cout << "Enter the elements: ";
    for (i = 0; i < N; i++)
        cin >> arr[i];

    int* flips = new int[2 * N];
    int count = pancakeSort(arr, N, flips);

    cout << "Flip k-values: ";
    printArray(flips, count);
    cout << "Sorted array: ";
    printArray(arr, N);
    delete[] arr;
    delete[] flips;
    return 0;
}