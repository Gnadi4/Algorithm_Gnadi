#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    if(m>(n-m))m=n-m;

    vector<int> arr;
    vector<int> arr_m;

    for(int i=0; i<m; i++){
        arr.push_back(n-i);
        arr_m.push_back(i+1);
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(arr[i]%arr_m[j]==0&&arr_m[j]!=1){
                arr[i]/=arr_m[j];
                arr_m[j]=1;
                break;
            }
        }
    }

    long long total = 1;
    long long total_m = 1;

    for(int i=0; i<m; i++){
        total*=arr[i];
        total_m*=arr_m[i];
    }
    // cout<<total_m<<endl;
    // cout<<total/total_m<<endl;

    return total/total_m;

    // return 0;
}