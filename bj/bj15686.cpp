#include <iostream>
#include <cstdlib>
using namespace std;

int home[100][2];
int chicken[13][2];
int result = 2100000000;

void func(int arr[100][13], int m, int *min_arr, int c, int h, int k){
    int sum = 0;

    if(m==0 || k>=c){
        for(int j=0; j<h; j++){
            // if(m==3)cout<<tmp[j]<<endl;
            sum+=min_arr[j];
        }
        result = min(result,sum);
        return;
    }

    for(int i=k; i<c; i++){
        int tmp[100] = {0,};
        for(int j=0; j<h; j++){
            tmp[j] = min(min_arr[j],arr[j][i]);
        }
        func(arr, m-1, tmp, c, h, i+1);
    }
    return;
}

int main(){

    int n,m;
    cin>>n>>m;

    int arr[100][13];

    int h = 0;
    int c = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int a;
            cin>>a;
            if(a==1){
                home[h][0] = i;
                home[h][1] = j;
                h+=1;
            }else if(a==2){
                chicken[c][0] = i;
                chicken[c][1] = j;
                c+=1;
            }
        }
    }

    for (int i=0; i<c; i++){
        for(int j=0; j<h; j++){
            arr[j][i] = abs(home[j][0]-chicken[i][0])+abs(home[j][1]-chicken[i][1]);
        }
    }

    // for (int i=0; i<c; i++){
    //     for(int j=0; j<h; j++){
    //         cout<<arr[j][i]<<' ';
    //     }cout<<endl;
    // }

    int min_arr[100];
    for(int i=0; i<100; i++)min_arr[i]=100;

    func(arr, m, min_arr, c, h, 0);

    cout<<result<<endl;

    return 0;
}