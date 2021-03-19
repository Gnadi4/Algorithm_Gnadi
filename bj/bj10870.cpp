#include <iostream>
using namespace std;

int pibonacci(int a, int b, int n){

    if(n==1)return b;

    return pibonacci(b, a+b, n-1);
}

int main(){

    int n;
    cin>>n;

    int a = 0;
    int b = 1;

    if(n==0)cout<<a<<endl;
    else if(n==1)cout<<b<<endl;
    else{
        cout<<pibonacci(a,b,n)<<endl;
    }

    return 0;
}