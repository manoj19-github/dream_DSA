// get square root of a number


#include <iostream>
#include<vector>
using namespace std;

int getSqrt(long long int num){
    int start=0;
    int end=num;
    long long int mid = start+(end - start)/2;
    int ans = 0;
    while(start<=end){
        if(mid*mid == num) return mid;
        else if(mid*mid<=num){
            ans=mid;
            start = mid+1;
        }else{
            end = mid -1;
        }
        mid = start+(end - start)/2;
        
    }
    return ans;
}
 double morePrecision(int num,int tempSol,int precision){
     double factor=1;
     double ans=tempSol;
     for(int i=0;i<precision;i++){
         factor = factor/10;
         for(double j=tempSol;j*j <=num;j+=factor){
             ans=j;
         }
     }
     return ans;
 }
 
int main() {
    int result = getSqrt(29);
    cout<<"Answer is : "<<morePrecision(29,result,4);
    
    
    

    return 0;
}