#include <iostream>
using namespace std;

int val[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

int main(){

    for(int i=0; i<20; i++){
        for(int j=i+1; j<20; j++){
            if(val[j]%val[i]==0){
                val[j]/=val[i];
            }
        }
    }

    int result = 1;

    //for(int i=0; i<20; i++)cout<<val[i]<<endl;
    for(int i=0; i<20; i++)result*=val[i];

    cout<<result<<endl;

    // int tmp = 1;

    // for(int i=1; i<=10; i++)tmp*=i;

    // cout<<tmp<<endl;

    return 0;
}