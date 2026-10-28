// Areefa Samar - CT-25062
// Question 05 (Lab 06)

#include <iostream>
using namespace std;

void sortColors(int* nums, int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = nums[i];
        j = i - 1;
        while (j >= 0 && nums[j] > key){
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
}

void printArray(int* arr, int size){
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int n, i;
    cout << "Enter number of objects: ";
    cin >> n;
    int* nums = new int[n];
    cout << "Enter the colors (0 = red, 1 = white, 2 = blue): ";
    for (i = 0; i < n; i++)
        cin >> nums[i];
    sortColors(nums, n);
    cout << "Sorted colors: ";
    printArray(nums, n);
    delete[] nums;
    return 0;
}