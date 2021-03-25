#include <iostream>
using namespace std;

int main(){

    long long a = 0;

    long long b = 0;

    for(int i=1; i<=100; i++){
        a+=i;
        b+=(i*i);
    }

    cout<<(a*a)-b<<endl;

    return 0;
}