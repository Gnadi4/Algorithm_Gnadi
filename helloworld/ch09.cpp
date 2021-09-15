#include <iostream>
#include <string>

using namespace std;

#define PI 3.14

int main(){

    // string a = "Hello";

    // cout<<a<<endl;

    // cout<<PI<<endl;

    // int num = 10;

    // int &b = num;

    // b = 3;

    // cout<<num<<endl;

    int arr[] = {0,1,2,3,4,5};

    for(int &i:arr){
        i+=1;
    }
    for(int i:arr){
        cout<<i<<endl;
    }

    return 0;
}