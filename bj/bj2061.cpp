#include <iostream>
#include <math.h>
using namespace std;

int main(){

    long long K,L;
    cin>>K>>L;

    for(long long i=2; i<=long long(sqrt(K)); i++){
        if(K%i==0&&i<L){
            cout<<"BAD"<<" "<<i<<endl;
            return 0;
        }
    }
    cout<<"GOOD"<<endl;

    return 0;
}