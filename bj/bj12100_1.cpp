#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int result = 0;
int arr[20][20] = {0,};

void run_program(int co, int size_n){
    if(co==5){
        for(int i=0; i<size_n; i++){
            for(int j=0; j<size_n; j++){
                result = max(result,arr[i][j]);
            }
        }
        return;
    }

    int save_arr[20][20] = {0,};

    for(int i=0; i<size_n; i++){
        for(int j=0; j<size_n; j++){
            save_arr[i][j] = arr[i][j];
        }
    }
    
    //01
    for(int i=0; i<size_n; i++){
        int tmp_line[20] = {0,};
        int k = 0;
        for(int j=0; j<size_n; j++){
            if(arr[i][j]!=0){
                if(tmp_line[k]!=0){
                    if(tmp_line[k]==arr[i][j]){
                        tmp_line[k]*=2;
                        k+=1;
                    }
                    else{
                        k+=1;
                        tmp_line[k]=arr[i][j];
                    }
                }else{
                    tmp_line[k]=arr[i][j];
                }
            }
        }
        for(int j=0; j<size_n; j++){
            arr[i][j] = tmp_line[j];
        }
    }
    run_program(co+1,size_n);
    for(int i=0; i<size_n; i++){
        for(int j=0; j<size_n; j++)arr[i][j] = save_arr[i][j];
    }

    //02
    for(int i=0; i<size_n; i++){
        int tmp_line[20] = {0,};
        int k = size_n-1;
        for(int j=size_n-1; j>=0; j--){
            if(arr[i][j]!=0){
                if(tmp_line[k]!=0){
                    if(tmp_line[k]==arr[i][j]){
                        tmp_line[k]*=2;
                        k-=1;
                    }
                    else{
                        k-=1;
                        tmp_line[k]=arr[i][j];
                    }
                }else{
                    tmp_line[k]=arr[i][j];
                }
            }
        }
        for(int j=size_n-1; j>=0; j--){
            arr[i][j] = tmp_line[j];
        }
    }
    run_program(co+1,size_n);
    for(int i=0; i<size_n; i++){
        for(int j=0; j<size_n; j++)arr[i][j] = save_arr[i][j];
    }

    //03
    for(int j=0; j<size_n; j++){
        int tmp_line[20] = {0,};
        int k = 0;
        for(int i=0; i<size_n; i++){
            if(arr[i][j]!=0){
                if(tmp_line[k]!=0){
                    if(tmp_line[k]==arr[i][j]){
                        tmp_line[k]*=2;
                        k+=1;
                    }
                    else{
                        k+=1;
                        tmp_line[k]=arr[i][j];
                    }
                }else{
                    tmp_line[k]=arr[i][j];
                }
            }
        }
        for(int i=0; i<size_n; i++){
            arr[i][j] = tmp_line[i];
        }
    }
    run_program(co+1,size_n);
    for(int i=0; i<size_n; i++){
        for(int j=0; j<size_n; j++)arr[i][j] = save_arr[i][j];
    }

    //04
    for(int j=0; j<size_n; j++){
        int tmp_line[20] = {0,};
        int k = size_n-1;
        for(int i=size_n-1; i>=0; i--){
            if(arr[i][j]!=0){
                if(tmp_line[k]!=0){
                    if(tmp_line[k]==arr[i][j]){
                        tmp_line[k]*=2;
                        k-=1;
                    }
                    else{
                        k-=1;
                        tmp_line[k]=arr[i][j];
                    }
                }else{
                    tmp_line[k]=arr[i][j];
                }
            }
        }
        for(int i=size_n-1; i>=0; i--){
            arr[i][j] = tmp_line[i];
        }
    }
    run_program(co+1,size_n);
    for(int i=0; i<size_n; i++){
        for(int j=0; j<size_n; j++)arr[i][j] = save_arr[i][j];
    }
}

int main(){

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    run_program(0, n);

    cout<<result<<endl;

    return 0;
}