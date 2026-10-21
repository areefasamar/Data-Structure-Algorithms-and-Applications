// Areefa Samar - CT-25062
// Question 03 (Lab 04)

#include <iostream>
#include <vector>
using namespace std;

void generatePermutations(vector<int>& nums, int index, vector<vector<int>>& result) {

    if (index == nums.size()) {
        result.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);              
        generatePermutations(nums, index + 1, result);
        swap(nums[index], nums[i]);            
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;

    generatePermutations(nums, 0, result);

    for (auto& perm : result) {
        for (int num : perm)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}