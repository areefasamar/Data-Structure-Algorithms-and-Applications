#include<iostream>
#include<iomanip>
using namespace std;

float CalculateGPA(float ds=-1, float pa=-1, float dld=-1, float ps=-1, float fa=-1){
	float grades[] = {ds, pa, dld, ps, fa};
	float totalPoints = 0;
	int courseCount = 0;
	
	for(int i=0 ; i<5 ; i++){
		if(grades[i] != -1){
			totalPoints += grades[i] * 3;
			courseCount++;
		}
	}
	
	float gpa = totalPoints / (courseCount * 3);
	return gpa;
}

int main(){
	cout<<fixed<<setprecision(3);  
	
	cout<<"GPA of all Student:"<<endl;
	cout<<"Ali: "<<CalculateGPA(3.66, 3.33, 4.0, 3.0, 2.66)<<endl;
	cout<<"Hiba: "<<CalculateGPA(3.33, 3.0, 3.66, 3.0)<<endl;
	cout<<"Asma: "<<CalculateGPA(4.0, 3.66, 2.66)<<endl;
	cout<<"Zain: "<<CalculateGPA(2.66, 2.33, 4.0)<<endl;
	cout<<"Faisal: "<<CalculateGPA(3.33, 3.66, 4.0, 3.0, 3.33)<<endl;
	
	return 0;
}

