#include <iostream>
#include<vector>
using namespace std;
bool isArraySorted(int *arr,int size,bool isAsc){
    //base case 
    if(size ==1 || size ==0) return true;
    // remaining 
    if((isAsc && arr[0]>arr[1] ) || (!isAsc && arr[0]<arr[1])) return false;
    return isArraySorted(arr+1,size-1,isAsc);
    
    
}

int main() {
    int arr[]={12,40,85,67,90,231};
    if(isArraySorted(arr,sizeof(arr)/sizeof(arr[0]),true)){
        cout<<"this is sorted array"<<endl;
    }else{
        cout<<"this is  unsorted array"<<endl;
    }
    
}