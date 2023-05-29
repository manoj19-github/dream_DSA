//Move all negative numbers to beginning and positive to end with constant extra space
//input : [-12,40,-9,1,-3,45,53] , output: [-12,-9,-3,40,1,45,53]

#include <iostream>
#include <vector>
using namespace std;
void swap(int *ptr1,int *ptr2){
    *ptr1=*ptr1+*ptr2;
    *ptr2=*ptr1-*ptr2;
    *ptr1=*ptr1 - *ptr2;
}
void moveNegativeNumbers(vector<int>&vec){
    int j=0;
    for(int i=0;i<vec.size();i++){
        if(vec[i] < 0){
            if(i!=j) swap(&vec[i],&vec[j]);
            j++;
        }
    }

}

void main(){
    vector<int>arr = {-12,40,-9,1,-3,45,53};
    cout<<"Initial State:"<<endl;
    for(int iter:arr){
        cout<<iter<<" , ";
    }
    moveNegativeNumbers(arr);
    cout<<endl<<"After processing:"<<endl;
    for(int iter:arr){
        cout<<iter<<" , ";
    }
}