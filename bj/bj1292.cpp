#include <iostream>
using namespace std;

int main(){

    int arr[1000];
    int tmp=1;
    int tmp_input=1;
    for(int i=0; i<1000; i++){
        if(tmp_input>0){
            arr[i]=tmp;
            tmp_input-=1;
        }
        else{
            tmp+=1;
            arr[i]=tmp;
            tmp_input=tmp-1;
        }
    }

    int n,m;

    cin>>n>>m;

    int total = 0;

    for(int i=n-1; i<m; i++)total+=arr[i];

    cout<<total<<endl;

    return 0;
}