#include <iostream>
#include <algorithm>
using namespace std;

int val[8] = {0,};
int ck[8] = {0,};
int result = 0;

void gna(int n, int s, int ga[8]){
    //base
    if(s==n){
        int tmp = 0;
        for(int i=0; i<n-1; i++)tmp+=abs(ga[i]-ga[i+1]);
        result = max(result,tmp);
        return;
    }

    for(int i=0; i<n; i++){
        if(ck[i]==0){
            ck[i]=1;
            ga[s]=val[i];
            gna(n,s+1,ga);
            ga[s]=0;
            ck[i]=0;
        }
    }

    return;
}

int main(){

    int n;
    cin>>n;

    for(int i=0; i<n; i++)cin>>val[i];

    int ga[8] = {0,};

    gna(n,0,ga);

    cout<<result<<endl;

    return 0;
}