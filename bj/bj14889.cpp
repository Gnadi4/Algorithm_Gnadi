#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int val[20][20] = {0,};
int check[20] = {0,};
//int tmp[10] = {0,};
int result = 1000000;

int cal(int n){
    
    vector<int> a_arr;
    vector<int> b_arr;

    int a = 0;
    int b = 0;

    for(int i=0; i<n; i++){
        if(check[i]==1)a_arr.push_back(i);
        else{b_arr.push_back(i);}
    }

    // for(int i=0; i<n/2; i++){
    //     cout<<a_arr[i]<<' '<<b_arr[i]<<endl;
    // }

    for(int i=0; i<n/2; i++){
        for(int j=i+1; j<n/2; j++){
            a+=(val[a_arr[i]][a_arr[j]]+val[a_arr[j]][a_arr[i]]);
            b+=(val[b_arr[i]][b_arr[j]]+val[b_arr[j]][b_arr[i]]);
        }
    }

    // cout<<a<<' '<<b<<endl;

    if(a>=b)return a-b;
    
    return b-a;
}

void gna(int n, int c, int s){


    if(c==n/2){
        // for(int i=0; i<n; i++)cout<<check[i]<<' ';
        // cout<<endl;
        int tmp = cal(n);
        result = min(result,tmp);
    }
    if(s==n)return;

    for(int i=s; i<n; i++){
        check[i] = 1;
        gna(n,c+1,i+1);
        check[i] = 0;
    }
    return;
}

int main(){

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)cin>>val[i][j];
    }

    check[0] = 1;

    gna(n,1,1);

    cout<<result<<endl;

    return 0;
}