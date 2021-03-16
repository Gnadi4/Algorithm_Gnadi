#include <iostream>
using namespace std;

int main(){

    long long result = 2;

    int first = 1;
    int second = 2;

    while(true){
        int tmp = first+second;
        if(tmp>4000000)break;

        if(tmp%2==0)result+=tmp;

        first = second;
        second = tmp;
    }

    cout<<result<<endl;

    return 0;
}