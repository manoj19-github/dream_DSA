#include <iostream>
using namespace std;

int facto(int num){
    if(num==0) return 1;
    return 1* facto(num-1);
}
int main(){
    int num = 5;
    int result = facto(num);
    cout<<result<<endl;

}

int fibo(int num){
    if(num ==0) return 0;
    if(num ==1) return 1;
    return fibo(num-1)+fibo(num-2);
}

void main(){
    int ans;
    cout<<"Enter Number : "<<;
    cin>>num;
    cout<<fibo(num);
}