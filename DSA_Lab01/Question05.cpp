#include<iostream>
using namespace std;

bool searchMatrix(int matrix[][4], int m, int n, int target){
	int left = 0;
	int right = (m * n) - 1;
	
	while(left <= right){
		int mid = left + (right - left) / 2;
		
		int row = mid / n;
		int col = mid % n;
		
		if(matrix[row][col] == target){
			return true;
		}
		else if(matrix[row][col] < target){
			left = mid + 1;   
		}
		else{
			right = mid - 1;  
		}
	}
	
	return false;  
}

int main(){
	int matrix[3][4] = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 60}
	};
	int m = 3, n = 4;
	
	int target = 3;
	if(searchMatrix(matrix, m, n, target)){
		cout<<"Target "<<target<<" found in matrix: true"<<endl;
	}
	else{
		cout<<"Target "<<target<<" found in matrix: false"<<endl;
	}
	
	target = 13;
	if(searchMatrix(matrix, m, n, target)){
		cout<<"Target "<<target<<" found in matrix: true"<<endl;
	}
	else{
		cout<<"Target "<<target<<" found in matrix: false"<<endl;
	}
	
	return 0;
}

