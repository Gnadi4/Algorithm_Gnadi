#include <iostream>

using namespace std;

int func(int a, int b){
    int result = 1;
    for(int i=0; i<b; i++){
        result*=a;
        result%=10;
        if(result==0)result=10;
    }

    return result;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int test=0; test<n; test++){
        int a,b;
        cin>>a>>b;

        cout<<func(a,b)<<'\n';
    }

    return 0;
}