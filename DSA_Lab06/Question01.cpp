// Areefa Samar - CT-25062
// Question 01 (Lab 06)

#include <iostream>
using namespace std;

void bubbleSort(int* arr, int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++){
        swapped = false;
        
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
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
    bubbleSort(arr, N);
    cout << "Sorted array: \n";
    printArray(arr, N);
    delete[] arr;
    return 0;
}