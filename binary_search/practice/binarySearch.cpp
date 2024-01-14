#include <iostream>
#include<stack>
#include<vector>
using namespace std;

int searchBinaryRecursive(vector<int>vec,int searchKey,int start,int end){
    if(start>end) return-1;
    int mid = start+(end-start)/2;
    if(vec[mid]==searchKey) return mid;
    if(vec[mid]>searchKey) return searchBinaryRecursive(vec,searchKey,start,mid-1);
    return searchBinaryRecursive(vec,searchKey,mid+1,end);
}

int searchBinary(vector<int>vec,int searchKey){
    int start = 0;
    int end = vec.size()-1;
    int mid = start+(end-start)/2;
    while(start<=end){
        if(vec[mid]==searchKey) return mid;
        if(vec[mid]<searchKey)start=mid-1;
        else end= mid+1;
        mid = start+(end-start)/2;
    }
    return-1;
}

int main() {
    // Write C++ code here
    
    vector<int>vec={12,34,56,90,342,903};
    int result = searchBinary(vec,34);
    cout<<result<<endl;
    int result2 = searchBinaryRecursive(vec,34,0,5);
    cout<<result2;
    return 0;
}