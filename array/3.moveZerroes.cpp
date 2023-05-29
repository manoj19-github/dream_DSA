// move zerroes

#include<iostream>
#include<vector>
using namespace std;
void swap(int *ptr1,int *ptr2){
    *ptr1=*ptr1+*ptr2;
    *ptr2=*ptr1-*ptr2;
    *ptr1=*ptr1 - *ptr2;
}
void moveZerroes(vector<int>&arr){
    int nonZerroes = 0;
    for(int iter=0; iter<arr.size();iter++){
        if(arr[iter] !=0){
            swap(&arr[iter],&arr[nonZerroes]);
            nonZerroes++;
        }
    }
}
void main(){
    vector<int> arr = {10,2,0,4,34,0,423,0,4,20};
    cout<<endl<<"Initial state : "<<endl;
    for(int iter:arr){
        cout<<" "<<iter<<" , ";

    
    }
    moveZerroes(arr);
    cout<<endl<<"after processing state : "<<endl;
    for(int iter:arr){
        cout<<" "<<iter<<" , ";
        
    }

}