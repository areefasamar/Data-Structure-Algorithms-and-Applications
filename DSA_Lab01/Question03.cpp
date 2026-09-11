#include<iostream>
#include<vector>
using namespace std;

class MedianFinder {
	vector<int> arr;
	
public:
	MedianFinder(){
		
	}
	
	void addNum(int num){
		
		int i = 0;
		while(i < arr.size() && arr[i] < num){
			i++;
		}
		arr.insert(arr.begin() + i, num);
	}
	
	double findMedian(){
		int n = arr.size();
		if(n % 2 == 1){
			return arr[n/2];
		}
		else{
			return (arr[n/2 - 1] + arr[n/2]) / 2.0;
		}
	}
};

int main(){
	MedianFinder medianFinder;
	
	medianFinder.addNum(1);
	medianFinder.addNum(2);
	cout<<"Median: "<<medianFinder.findMedian()<<endl;  
	
	medianFinder.addNum(3);
	cout<<"Median: "<<medianFinder.findMedian()<<endl;  
	
	return 0;
}

