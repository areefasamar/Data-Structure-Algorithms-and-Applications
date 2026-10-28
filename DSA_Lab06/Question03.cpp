// Areefa Samar - CT-25062
// Question 03 (Lab 06)

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Sort{
    int comparisons;
    int swaps;

public:
    Sort(){
        comparisons = 0;
        swaps = 0;
    }

    int getComparisons(){ return comparisons; }
    int getSwaps(){ return swaps; }

    void reset(){
        comparisons = 0;
        swaps = 0;
    }

    void bubbleSort(int* arr, int n){
        int i, j;
        for (i = 0; i < n - 1; i++){
            for (j = 0; j < n - i - 1; j++){
                comparisons++;
                if (arr[j] > arr[j + 1]){
                    swap(arr[j], arr[j + 1]);
                    swaps++;
                }
            }
        }
    }

    void selectionSort(int* arr, int n){
        int i, j, min_idx;
        for (i = 0; i < n - 1; i++){
            min_idx = i;
            for (j = i + 1; j < n; j++){
                comparisons++;
                if (arr[j] < arr[min_idx])
                    min_idx = j;
            }
            if (min_idx != i){
                swap(arr[min_idx], arr[i]);
                swaps++;
            }
        }
    }

    void insertionSort(int* arr, int n){
        int i, key, j;
        for (i = 1; i < n; i++){
            key = arr[i];
            j = i - 1;
            while (j >= 0){
                comparisons++;
                if (arr[j] > key){
                    arr[j + 1] = arr[j];
                    swaps++;
                    j = j - 1;
                }
                else
                    break;
            }
            arr[j + 1] = key;
        }
    }

    void sortArray(int* arr, int n, string choice){
        reset();
        if (choice == "bubble")
            bubbleSort(arr, n);
        else if (choice == "selection")
            selectionSort(arr, n);
        else if (choice == "insertion")
            insertionSort(arr, n);
        else
            cout << "Invalid choice" << endl;
    }

    // Run all 3 techniques on copies of the same random array
    // Results are stored in comps[] and swps[] (0 = bubble, 1 = selection, 2 = insertion)
    void analyze(int n, int* comps, int* swps){
        int* original = new int[n];
        int* temp = new int[n];
        int i;
        for (i = 0; i < n; i++)
            original[i] = rand() % 1000;

        string names[3] = {"bubble", "selection", "insertion"};
        int t;
        for (t = 0; t < 3; t++){
            for (i = 0; i < n; i++)
                temp[i] = original[i];
            sortArray(temp, n, names[t]);
            comps[t] = comparisons;
            swps[t] = swaps;
        }
        delete[] original;
        delete[] temp;
    }
};

void printArray(int* arr, int size){
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    srand(time(0));
    Sort s;

    int n, i;
    cout << "Enter number of elements: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    string choice;
    cout << "Enter sorting technique (bubble / selection / insertion): ";
    cin >> choice;
    s.sortArray(arr, n, choice);
    cout << "Sorted array: ";
    printArray(arr, n);
    delete[] arr;

    int size;
    cout << "\nEnter size of random array for analysis: ";
    cin >> size;
    int comps[3], swps[3];
    s.analyze(size, comps, swps);

    string names[3] = {"Bubble Sort", "Selection Sort", "Insertion Sort"};
    cout << "\nTechnique\t\tComparisons\tSwaps\tTotal" << endl;
    for (i = 0; i < 3; i++)
        cout << names[i] << "\t\t" << comps[i] << "\t\t" << swps[i]
             << "\t" << comps[i] + swps[i] << endl;

    int best = 0, worst = 0;
    for (i = 1; i < 3; i++){
        if (comps[i] + swps[i] < comps[best] + swps[best])
            best = i;
        if (comps[i] + swps[i] > comps[worst] + swps[worst])
            worst = i;
    }
    cout << "\nBest technique: " << names[best] << endl;
    cout << "Worst technique: " << names[worst] << endl;
    return 0;
}