#include <iostream>
#include <math.h>
using namespace std;

int main(){

    int N,K;
    cin>>N>>K;
    int count = 0;
    //for 문 범위 조심좀 하자
    for(int i=1; i<=N; i++){
        if(N%i==0)count+=1;
        if(count==K){
            cout<<i<<endl;
            return 0;
        }
    }
    //0을 출력한다면 출력을 표시해줘야 할듯?
    cout<<0<<endl;
    return 0;
}