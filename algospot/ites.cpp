#include <iostream>
#include <queue>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    long long a=1983;

    int t;
    cin>>t;

    for(int test=0; test<t; test++){
        int k,n;
        cin>>k>>n;

        long long sum=0;
        long long co=0;

        for(int i=0; i<n; i++){

            if(sum==k){
                co+=1;
            }else if(sum<k){

            }else if(sum>k){

            }
        }

        cout<<co<<endl;

    }

    return 0;
}