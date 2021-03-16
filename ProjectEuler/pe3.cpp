#include <iostream>
#include <cmath>
using namespace std;

int main(){

    long num = 600851475143;

    //long double k = sqrt(num);

    cout<<num<<endl;

    // int prime[]
    
    // while(true){
    // }

    // long a = 775146;
    // a*=a;

    //cout<<a<<endl;

    long t = 2;
    int result = 0;

    while(true){
        if(num<t)break;

        if(num%t==0){
            num/=t;
            result = t;
        }else{
            t+=1;
        }
    }

    cout<<result<<endl;

    return 0;
}