#include <iostream>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    int result = 0;

    for(int i=0; i<5; i++){
        int a;
        cin>>a;

        if(n==a)result+=1;
    }

    cout<<result<<"\n";

    return 0;
}