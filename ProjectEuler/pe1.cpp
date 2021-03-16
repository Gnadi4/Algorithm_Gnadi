#include <iostream>
using namespace std;

int main(){

    long long result = 0;

    for(int i=1; i<1000; i++){
        if(i%3==0||i%5==0){
            //cout<<i<<' ';
            result+=i;
        }
    }

    cout<<result<<endl;

    return 0;
}