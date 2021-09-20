#include <iostream>
#include <algorithm>
using namespace std;

int arr[250];

int result = 300;

void find(int k, int s, int num){
    //cout<<k<<endl;
    //if(k==0)return;
    for(int i=k; i>=1; i--){
        if(arr[i]==num){
            result = min(result,s+1);
        }else if(arr[i]<num && i>0){
            find(249,s+1,num-arr[i]);
        }
    }
    return;
}

int main(){

    int n;
    cin>>n;

    for(int i=0; i<250; i++)arr[i]=i*i;

    find(249, 0, n);

    cout<<result<<endl;

    return 0;
}