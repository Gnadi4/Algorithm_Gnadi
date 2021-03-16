#include <iostream>
using namespace std;

int rec(int n){
    if(n==1)return 1;
    return n+rec(n-1);
}

int main(){

    cout<<rec(10)<<endl;

    return 0;
}