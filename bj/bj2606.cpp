#include <iostream>
#include <algorithm>

using namespace std;

int arr[100][100] = {0,};
int chk_arr[100] = {0,};
int N;

void func(int k){

    
    for(int j=k+1; j<N; j++){
        if(arr[k][j]!=0){
            chk_arr[j]=1;
            func(j);
        }
    }
 

    return;
}

int main(){

    int inputcase;

    cin>>N>>inputcase;

    for(int i=0; i<inputcase; i++){
        int a,b;
        cin>>a>>b;

        arr[a-1][b-1]=1;
        arr[b-1][a-1]=1;
    }

    chk_arr[0]=1;

    for(int i=0; i<N; i++){
        for(int j=1; j<N; j++){
            if(arr[i][j]!=0&&chk_arr[i]==1){
                chk_arr[j]=1;
                func(j);
            }
        }
    }

    int co = 0;

    for(int i:chk_arr){
        //cout<<i<<' ';
        if(i==1)co+=1;
    }

    cout<<co-1<<endl;

    return 0;
}