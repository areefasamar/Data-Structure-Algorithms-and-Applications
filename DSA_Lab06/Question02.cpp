// Areefa Samar - CT-25062
// Question 02 (Lab 06)

#include <iostream>
using namespace std;

void insertionSort(int* arr, int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int maxToys(int* arr, int n, int k){
    insertionSort(arr, n);
    int count = 0;
    int i;
    for (i = 0; i < n; i++){
        if (k >= arr[i]){
            k = k - arr[i];
            count++;
        }
        else
            break;
    }
    return count;
}

int main(){
    int N, K, i;
    cout << "Enter number of toys: ";
    cin >> N;
    int* arr = new int[N];
    cout << "Enter the cost of each toy: ";
    for (i = 0; i < N; i++)
        cin >> arr[i];
    cout << "Enter the amount you have: ";
    cin >> K;

    cout << "Maximum toys you can buy: " << maxToys(arr, N, K) << endl;
    delete[] arr;
    return 0;
}