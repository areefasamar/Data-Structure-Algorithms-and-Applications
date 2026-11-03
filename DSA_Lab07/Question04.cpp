// Areefa Samar - CT-25062
// Question 04 (Lab 07)

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

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

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int findLHS(vector<int> nums) {
    int n = nums.size();
    if (n == 0)
        return 0;

    mergeSort(nums, 0, n - 1);

    int best = 0;
    int left = 0;
    for (int right = 0; right < n; right++) {
        while (nums[right] - nums[left] > 1)
            left++;
        if (nums[right] - nums[left] == 1) {
            if (right - left + 1 > best)
                best = right - left + 1;
        }
    }
    return best;
}

int main() {
    int a1[] = {1, 3, 2, 2, 5, 2, 3, 7};
    vector<int> nums1(a1, a1 + 8);
    cout << "Example 1 Output: " << findLHS(nums1) << endl;

    int a2[] = {1, 2, 3, 4};
    vector<int> nums2(a2, a2 + 4);
    cout << "Example 2 Output: " << findLHS(nums2) << endl;

    int a3[] = {1, 1, 1, 1};
    vector<int> nums3(a3, a3 + 4);
    cout << "Example 3 Output: " << findLHS(nums3) << endl;

    return 0;
}
