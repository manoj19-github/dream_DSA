// merge two sorted array using two pointer method 

#include<iostream>
#include<vector>
using namespace std;

void mergeSortedArrayO(vector<int>&arr1, vector<int>&arr2,vector<int>&arr3){
    
    int i = 0,j=0;
    int total = 0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            int element = arr1[i++];
            arr3.push_back(element);
        }else{
            int element = arr2[j++];
            arr3.push_back(element);
        }

    }
    while(i<arr1.size()){
        int element = arr1[i++];
        arr3.push_back(element);
    }
    while(j<arr2.size()){
        int element = arr2[j++];
        arr3.push_back(element);
    }
}
void main(){
    vector<int>arr1={10,15,17,18,19};
    vector<int>arr2={5,7,10,13,14,15,19,21,25,27,30,38,41,110};
    vector<int>arr3;
    mergeSortedArray(arr1,arr2,arr3);
    cout<<"Merged and sorted arrays"<<endl;
    for(int iter:arr3){
        cout<<iter<<"  , ";
    }
}