#include <iostream>
using namespace std;

int arr[1000002]={0,};

int main(){

    arr[0]=1;
    arr[1]=1;
    for(int i=0; i<1000002; i++){
        if(arr[i]==0){
            for(int j=i+i; j<1000002; j+=i){
                arr[j]=1;
            }
        }
    }


    int count = 0;
    for(int i=0; i<1000002; i++){
        if(arr[i]==0)count+=1;
    }

    cout<<count<<endl;

    return 0;
}