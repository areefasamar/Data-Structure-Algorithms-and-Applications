#include<iostream>
using namespace std;

int search(int nums[], int n, int target){
	int left = 0;
	int right = n - 1;
	
	while(left <= right){
		int mid = left + (right - left) / 2;  
		
		if(nums[mid] == target){
			return mid;
		}
		else if(nums[mid] < target){
			left = mid + 1;   
		}
		else{
			right = mid - 1;  
		}
	}
	
	return -1;  
}

int main(){
	int nums[] = {-1, 0, 3, 5, 9, 12};
	int n = sizeof(nums) / sizeof(nums[0]);  
	
	int target = 9;
	cout<<"Target "<<target<<" found at index: "<<search(nums, n, target)<<endl;
	
	target = 2;
	cout<<"Target "<<target<<" found at index: "<<search(nums, n, target)<<endl;
	
	return 0;
}

