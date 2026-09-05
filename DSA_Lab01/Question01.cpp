#include<iostream>
using namespace std;

int main(){
    int r, c;
    cout<<"Enter rows and columns of 2D array:"<<endl;
    cin>>r>>c;
    
    int array[r][c];
    
    cout<<"Enter elements of 2D array:"<<endl;
    for(int i=0 ; i<r ; i++){
        for(int j=0 ; j<c ; j++){
            cout<<"Enter element at index "<<i<<" & "<<j<<":"<<endl;
            cin>>array[i][j];
        }
    }
    
    int s = r*c;
    int arr[s];
    
    int k = 0;
    for(int j=0 ; j<c ; j++){       
        for(int i=0 ; i<r ; i++){   
            arr[k] = array[i][j];
            k++;
        }
    }
    
    cout<<"1D array in Column Major Order:"<<endl;
    for(int i=0 ; i<s ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}

