// find in a sorted and rotated array 


#include <iostream>
#include<vector>
using namespace std;

//  find   pivot element 
int getPivotElement(vector<int>vec){
    int start=0;
    int end=vec.size()-1;
    int mid = start+(end-start)/2;
    while(start<end){
        if(vec[0]<=vec[mid]) start=mid+1;
        else end=mid;
        mid = start+(end-start)/2;
    }
    return start;
}

// binary search 
int binarySearchElem(vector<int>vec,int start,int end,int searchKey){
 //base case
 if(start>end) return-1;
 int mid = start+(end-start)/2;
 if(vec[mid]==searchKey) return mid;
 if(vec[mid]>searchKey) return binarySearchElem(vec,start,mid-1,searchKey);
 return binarySearchElem(vec,mid+1,end,searchKey);
}

int searchInRotatedAndSortedArray(vector<int>vec,int searchKey){
    int pivot = getPivotElement(vec);
    cout<<"pivot : "<<pivot<<endl;
    int end=vec.size()-1;
    if(searchKey>=vec[pivot] && searchKey <= vec[end])
        return binarySearchElem(vec,pivot,end,searchKey);
    return binarySearchElem(vec,0,pivot,searchKey);
}


int main() {
    vector<int>vec={7,8,1,3,5};
    int result = searchInRotatedAndSortedArray(vec,5);
    cout<<"Result"<<endl;
    cout<<result<<endl;
    return 0;
}