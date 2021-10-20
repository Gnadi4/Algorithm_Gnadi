#include <iostream>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,k;
    cin>>n>>k;

    int m = 1;
    int j = 1;

    for(int i=1; i<=k; i++){
        m*=i;
    }
    for(int i=0; i<k; i++){
        j*=n;
        n-=1;
    }

    cout<<j/m<<"\n";

    return 0;
}