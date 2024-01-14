
#include <iostream>
#include<vector>
using namespace std;

int firstOccurence(vector<int>vec,int searchKey){
    int start=0;
    int end = vec.size()-1;
    int mid = start+(end-start)/2;
    int ans=-1;
    while(start<=end){
        if(vec[mid]==searchKey){
            ans = mid;
            end=mid-1;
        }else if(vec[mid]>searchKey){
            end=mid-1;
        }else{
            start=mid+1;
        }
        
        mid = start+(end-start)/2;
    }
    return ans;
    
}
int lastOccurence(vector<int>vec,int searchKey){
    int start=0;
    int end = vec.size()-1;
    int mid = start+(end-start)/2;
    int ans=-1;
    while(start<=end){
        if(vec[mid]==searchKey){
            ans = mid;
            start=mid+1;
        }else if(vec[mid]>searchKey){
            end=mid-1;
        }else{
            start=mid+1;
        }
        
        mid = start+(end-start)/2;
    }
    return ans;
    
}
int main() {
    vector<int>vec={12,34,34,39,43,43,90};
    int first = firstOccurence(vec,34);
    int last = lastOccurence(vec,34);
    cout<<"First occurence : "<<first<<endl;
    cout<<"Last occurence :"<<last<<endl;
   
}