#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501];
int arr_chk[501][501];
int n,m;
int result = 0;

void func(int k, int tmp[4][2]){
    
    if(k==4){
        int sum = 0;
        for(int i=0; i<k; i++){
            sum+=arr[tmp[i][0]][tmp[i][1]];
        }
        result = max(result,sum);
        return;
    }

    int tmp_arr[4][2];

    for(int i=0; i<k; i++){
        tmp_arr[i][0]=tmp[i][0];
        tmp_arr[i][1]=tmp[i][1];
    }

    for(int i=0; i<k; i++){
        if(tmp[i][0]+1<n&&arr_chk[tmp[i][0]+1][tmp[i][1]]==0){
            arr_chk[tmp[i][0]+1][tmp[i][1]]=1;
            tmp_arr[k][0] = tmp_arr[i][0]+1;
            tmp_arr[k][1] = tmp_arr[i][1];
            func(k+1,tmp_arr);
            arr_chk[tmp[i][0]+1][tmp[i][1]]=0;
        }
        if(tmp[i][0]-1>=0&&arr_chk[tmp[i][0]-1][tmp[i][1]]==0){
            arr_chk[tmp[i][0]-1][tmp[i][1]]=1;
            tmp_arr[k][0] = tmp_arr[i][0]-1;
            tmp_arr[k][1] = tmp_arr[i][1];
            func(k+1,tmp_arr);
            arr_chk[tmp[i][0]-1][tmp[i][1]]=0;
        }
        if(tmp[i][1]+1<m&&arr_chk[tmp[i][0]][tmp[i][1]+1]==0){
            arr_chk[tmp[i][0]][tmp[i][1]+1]=1;
            tmp_arr[k][0] = tmp_arr[i][0];
            tmp_arr[k][1] = tmp_arr[i][1]+1;
            func(k+1,tmp_arr);
            arr_chk[tmp[i][0]][tmp[i][1]+1]=0;
        }
        if(tmp[i][1]-1>=0&&arr_chk[tmp[i][0]][tmp[i][1]-1]==0){
            arr_chk[tmp[i][0]][tmp[i][1]-1]=1;
            tmp_arr[k][0] = tmp_arr[i][0];
            tmp_arr[k][1] = tmp_arr[i][1]-1;
            func(k+1,tmp_arr);
            arr_chk[tmp[i][0]][tmp[i][1]-1]=0;
        }
    }

    return;
}

int main(){

    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    int tmp[4][2];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr_chk[i][j]=1;
            tmp[0][0]=i;
            tmp[0][1]=j;
            func(1,tmp);
            arr_chk[i][j]=0;
        }
    }
    
    cout<<result<<endl;
    

    return 0;
}