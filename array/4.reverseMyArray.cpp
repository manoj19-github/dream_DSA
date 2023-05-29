#include<iostream>
#include<vector>
using namespace std;

void swap(int *ptr1,int *ptr2){
    *ptr1=*ptr1+*ptr2;
    *ptr2=*ptr1-*ptr2;
    *ptr1=*ptr1 - *ptr2;
}
void reverseMyArray(vector<int>&arr){
    int start=0,end = arr.size()-1;
    while(start<=end){
        swap(&arr[start],&arr[end]);
        start++;
        end--;
    }
}
void main(){
    vector<int>arr={10,20,43,56,92,40};
    cout<<endl<<"Initial state"<<endl;
    for(int iter:arr){
        cout<<iter<<" , ";
    }
    reverseMyArray(arr);
    cout<<endl<<"Reverse state"<<endl;
    for(int iter:arr){
        cout<<iter<<" , ";
    }
}