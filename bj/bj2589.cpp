#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int result;
int n,m;

void func(int x, int y, int p, int q, int arr[50][50], int co){
    int arr_tmp[50][50]={0,};

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         arr_tmp[i][j]=arr[i][j];
    //     }
    // }

    if(x==p && y==q){
        result = min(result,co);
    }

    if(x+1<n&&arr[x+1][y]==1){
        arr[x+1][y]=-1;
        func(x+1,y,p,q,arr,co+1);
        arr[x+1][y]=1;
    }

    if(x-1>=0&&arr[x-1][y]==1){
        arr[x-1][y]=-1;
        func(x-1,y,p,q,arr,co+1);
        arr[x-1][y]=1;
    }

    if(y+1<m&&arr[x][y+1]==1){
        arr[x][y+1]=-1;
        func(x,y+1,p,q,arr,co+1);
        arr[x][y+1]=1;
    }

    if(y-1>=0&&arr[x][y-1]==1){
        arr[x][y-1]=-1;
        func(x,y-1,p,q,arr,co+1);
        arr[x][y-1]=1;
    }

    return;
}

int main(){

    cin>>n>>m;

    int arr[50][50] = {0,};

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++){
            if(s[j]=='W'){
                arr[i][j]=0;
            }else{
                arr[i][j]=1;
            }
        }
    }

    int tmp = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==1){
                for(int l=i; l<n; l++){
                    for(int k=j; k<m; k++){
                        if(l!=i&&k!=j){
                            result=2100000000;
                            func(i,j,l,k,arr, 0);
                            if(result==2100000000)result=-1;
                            tmp = max(tmp,result);
                        }
                    }
                }
            }
        }
    }

    cout<<tmp<<endl;

    return 0;
}