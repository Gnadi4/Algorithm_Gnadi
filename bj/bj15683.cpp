#include <iostream>
#include <algorithm>
using namespace std;

int n = 0;
int m = 0;
int result = 2100000000;

void func(int x, int y, int arr[8][8]){
    //cout<<n<<' '<<m<<endl;
    int arr_tmp[8][8] = {0,};
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            // cout<<arr[i][j]<<' ';
            arr_tmp[i][j]=arr[i][j];
        }
        // cout<<endl;
    }

    // if(x>=n||y>=m){
    //     int co = 0;
    //     for(int p=0; p<n; p++){
    //         for(int q=0; q<m; q++){
    //             if(arr_tmp[p][q]==0)co+=1;
    //         }
    //     }
    //     result = max(result,co);
    //     return;
    // }

    // if(x==3&&y==2){
    //     for(int l=0;l<n;l++){
    //         for(int z=0; z<m; z++)cout<<arr_tmp[l][z]<<' ';
    //         cout<<endl;
    //     }
    // }

    for(int i=x; i<n; i++){
        for(int j=0; j<m; j++){
            // if(i==3&&j==0){
            //     for(int l=0;l<n;l++){
            //         for(int z=0; z<m; z++)cout<<arr_tmp[l][z]<<' ';
            //         cout<<endl;
            //     }
            // }
            if(arr[i][j]==1){
                arr_tmp[i][j] = -1;
                for(int k=i; k<n; k++){
                    if(arr[k][j]==6)break;
                    else if(arr[k][j]==0)arr_tmp[k][j]=-1;
                }
                func(i,j,arr_tmp);
                for(int l=0; l<8; l++){
                    for(int z=0; z<8; z++){
                        arr_tmp[l][z]=arr[l][z];
                    }
                }
                arr_tmp[i][j] = -1;
                for(int k=i; k>=0; k--){
                    if(arr[k][j]==6)break;
                    else if(arr[k][j]==0)arr_tmp[k][j]=-1;
                }
                func(i,j,arr_tmp);
                for(int l=0; l<8; l++){
                    for(int z=0; z<8; z++){
                        arr_tmp[l][z]=arr[l][z];
                    }
                }
                arr_tmp[i][j] = -1;
                for(int k=j; k<m; k++){
                    if(arr[i][k]==6)break;
                    else if(arr[i][k]==0)arr_tmp[i][k]=-1;
                }
                func(i,j,arr_tmp);
                for(int l=0; l<8; l++){
                    for(int z=0; z<8; z++){
                        arr_tmp[l][z]=arr[l][z];
                    }
                }
                arr_tmp[i][j] = -1;
                for(int k=j; k>=0; k--){
                    if(arr[i][k]==6)break;
                    else if(arr[i][k]==0)arr_tmp[i][k]=-1;
                }
                func(i,j,arr_tmp);
                for(int l=0; l<8; l++){
                    for(int z=0; z<8; z++){
                        arr_tmp[l][z]=arr[l][z];
                    }
                }
                return;
            }else if(arr[i][j]==2){
                arr_tmp[i][j] = -1;
                for(int k=i; k<n; k++){
                    if(arr[k][j]==6)break;
                    else if(arr[k][j]==0)arr_tmp[k][j]=-1;
                }
                for(int k=i; k>=0; k--){
                    if(arr[k][j]==6)break;
                    else if(arr[k][j]==0)arr_tmp[k][j]=-1;
                }
                func(i,j,arr_tmp);
                for(int l=0; l<8; l++){
                    for(int z=0; z<8; z++){
                        arr_tmp[l][z]=arr[l][z];
                    }
                }
                arr_tmp[i][j] = -1;
                for(int k=j; k<m; k++){
                    if(arr[i][k]==6)break;
                    else if(arr[i][k]==0)arr_tmp[i][k]=-1;
                }
                for(int k=j; k>=0; k--){
                    if(arr[i][k]==6)break;
                    else if(arr[i][k]==0)arr_tmp[i][k]=-1;
                }
                func(i,j,arr_tmp);
                for(int l=0; l<8; l++){
                    for(int z=0; z<8; z++){
                        arr_tmp[l][z]=arr[l][z];
                    }
                }
                return;
            }else if(arr[i][j]==3){
                arr_tmp[i][j] = -1;
                for(int k=i; k<n; k++){
                    if(arr[k][j]==6)break;
                    else if(arr[k][j]==0)arr_tmp[k][j]=-1;
                }
                for(int k=j; k<m; k++){
                    if(arr[i][k]==6)break;
                    else if(arr[i][k]==0)arr_tmp[i][k]=-1;
                }
                func(i,j,arr_tmp);
                for(int l=0; l<8; l++){
                    for(int z=0; z<8; z++){
                        arr_tmp[l][z]=arr[l][z];
                    }
                }
                arr_tmp[i][j] = -1;
                for(int k=i; k>=0; k--){
                    if(arr[k][j]==6)break;
                    else if(arr[k][j]==0)arr_tmp[k][j]=-1;
                }
                for(int k=j; k<m; k++){
                    if(arr[i][k]==6)break;
                    else if(arr[i][k]==0)arr_tmp[i][k]=-1;
                }
                func(i,j,arr_tmp);
                for(int l=0; l<8; l++){
                    for(int z=0; z<8; z++){
                        arr_tmp[l][z]=arr[l][z];
                    }
                }
                arr_tmp[i][j] = -1;
                for(int k=i; k<n; k++){
                    if(arr[k][j]==6)break;
                    else if(arr[k][j]==0)arr_tmp[k][j]=-1;
                }
                for(int k=j; k>=0; k--){
                    if(arr[i][k]==6)break;
                    else if(arr[i][k]==0)arr_tmp[i][k]=-1;
                }
                func(i,j,arr_tmp);
                for(int l=0; l<8; l++){
                    for(int z=0; z<8; z++){
                        arr_tmp[l][z]=arr[l][z];
                    }
                }
                arr_tmp[i][j] = -1;
                for(int k=i; k>=0; k--){
                    if(arr[k][j]==6)break;
                    else if(arr[k][j]==0)arr_tmp[k][j]=-1;
                }
                for(int k=j; k>=0; k--){
                    if(arr[i][k]==6)break;
                    else if(arr[i][k]==0)arr_tmp[i][k]=-1;
                }
                func(i,j,arr_tmp);
                for(int l=0; l<8; l++){
                    for(int z=0; z<8; z++){
                        arr_tmp[l][z]=arr[l][z];
                    }
                }
                return;
            }else if(arr[i][j]==4){
                arr_tmp[i][j] = -1;
                for(int k=i; k<n; k++){
                    if(arr[k][j]==6)break;
                    else if(arr[k][j]==0)arr_tmp[k][j]=-1;
                }
                for(int k=i; k>=0; k--){
                    if(arr[k][j]==6)break;
                    else if(arr[k][j]==0)arr_tmp[k][j]=-1;
                }
                for(int k=j; k<m; k++){
                    if(arr[i][k]==6)break;
                    else if(arr[i][k]==0)arr_tmp[i][k]=-1;
                }
                func(i,j,arr_tmp);
                for(int l=0; l<8; l++){
                    for(int z=0; z<8; z++){
                        arr_tmp[l][z]=arr[l][z];
                    }
                }
                arr_tmp[i][j] = -1;
                for(int k=i; k<n; k++){
                    if(arr[k][j]==6)break;
                    else if(arr[k][j]==0)arr_tmp[k][j]=-1;
                }
                for(int k=i; k>=0; k--){
                    if(arr[k][j]==6)break;
                    else if(arr[k][j]==0)arr_tmp[k][j]=-1;
                }
                for(int k=j; k>=0; k--){
                    if(arr[i][k]==6)break;
                    else if(arr[i][k]==0)arr_tmp[i][k]=-1;
                }
                func(i,j,arr_tmp);
                for(int l=0; l<8; l++){
                    for(int z=0; z<8; z++){
                        arr_tmp[l][z]=arr[l][z];
                    }
                }
                arr_tmp[i][j] = -1;
                for(int k=i; k<n; k++){
                    if(arr[k][j]==6)break;
                    else if(arr[k][j]==0)arr_tmp[k][j]=-1;
                }
                for(int k=j; k>=0; k--){
                    if(arr[i][k]==6)break;
                    else if(arr[i][k]==0)arr_tmp[i][k]=-1;
                }
                for(int k=j; k<m; k++){
                    if(arr[i][k]==6)break;
                    else if(arr[i][k]==0)arr_tmp[i][k]=-1;
                }
                func(i,j,arr_tmp);
                for(int l=0; l<8; l++){
                    for(int z=0; z<8; z++){
                        arr_tmp[l][z]=arr[l][z];
                    }
                }
                arr_tmp[i][j] = -1;
                for(int k=i; k>=0; k--){
                    if(arr[k][j]==6)break;
                    else if(arr[k][j]==0)arr_tmp[k][j]=-1;
                }
                for(int k=j; k>=0; k--){
                    if(arr[i][k]==6)break;
                    else if(arr[i][k]==0)arr_tmp[i][k]=-1;
                }
                for(int k=j; k<m; k++){
                    if(arr[i][k]==6)break;
                    else if(arr[i][k]==0)arr_tmp[i][k]=-1;
                }
                func(i,j,arr_tmp);
                for(int l=0; l<8; l++){
                    for(int z=0; z<8; z++){
                        arr_tmp[l][z]=arr[l][z];
                    }
                }
                return;
            }else if(arr[i][j]==5){
                // cout<<i<<' '<<j<<endl;
                arr_tmp[i][j] = -1;
                for(int k=i; k<n; k++){
                    if(arr[k][j]==6)break;
                    else if(arr[k][j]==0)arr_tmp[k][j]=-1;
                }
                for(int k=i; k>=0; k--){
                    if(arr[k][j]==6)break;
                    else if(arr[k][j]==0)arr_tmp[k][j]=-1;
                }
                for(int k=j; k<m; k++){
                    if(arr[i][k]==6)break;
                    else if(arr[i][k]==0)arr_tmp[i][k]=-1;
                }
                for(int k=j; k>=0; k--){
                    if(arr[i][k]==6)break;
                    else if(arr[i][k]==0)arr_tmp[i][k]=-1;
                }
                func(i,j,arr_tmp);
                for(int l=0; l<8; l++){
                    for(int z=0; z<8; z++){
                        arr_tmp[l][z]=arr[l][z];
                    }
                }
                return;
            }

            if(i==n-1&&j==m-1){
                int co = 0;
                for(int p=0; p<n; p++){
                    for(int q=0; q<m; q++){
                        //cout<<arr_tmp[p][q]<<' ';
                        if(arr_tmp[p][q]==0)co+=1;
                    }
                    //cout<<endl;
                }
                result = min(result,co);
                return;
            }
        }
    }

    return;
}

int main(){

    cin>>n>>m;

    int arr[8][8];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    func(0,0,arr);

    cout<<result<<endl;

    return 0;
}