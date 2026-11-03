// Areefa Samar - CT-25062
// Question 03 (Lab 07)

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<vector<int> >& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<vector<int> > L(arr.begin() + left, arr.begin() + mid + 1);
    vector<vector<int> > R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i][0] <= R[j][0]) {
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

void mergeSort(vector<vector<int> >& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

vector<vector<int> > mergeIntervals(vector<vector<int> > intervals) {
    vector<vector<int> > result;
    if (intervals.empty())
        return result;

    mergeSort(intervals, 0, intervals.size() - 1);

    result.push_back(intervals[0]);
    for (int i = 1; i < (int)intervals.size(); i++) {
        if (intervals[i][0] <= result.back()[1]) {
            if (intervals[i][1] > result.back()[1])
                result.back()[1] = intervals[i][1];
        } else {
            result.push_back(intervals[i]);
        }
    }
    return result;
}

void printIntervals(const vector<vector<int> >& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << "[" << v[i][0] << "," << v[i][1] << "]";
        if (i != (int)v.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
}

vector<int> makeInterval(int a, int b) {
    vector<int> x;
    x.push_back(a);
    x.push_back(b);
    return x;
}

int main() {
    vector<vector<int> > intervals1;
    intervals1.push_back(makeInterval(1, 3));
    intervals1.push_back(makeInterval(2, 6));
    intervals1.push_back(makeInterval(8, 10));
    intervals1.push_back(makeInterval(15, 18));

    cout << "Example 1 Output: ";
    printIntervals(mergeIntervals(intervals1));

    vector<vector<int> > intervals2;
    intervals2.push_back(makeInterval(1, 4));
    intervals2.push_back(makeInterval(4, 5));

    cout << "Example 2 Output: ";
    printIntervals(mergeIntervals(intervals2));

    return 0;
}
