#include <iostream>
#include <map>

using namespace std;
using ll = long long;

map<ll, ll> ma;
ll n,p,q;

ll func(long long i){

    if(ma.count(i)){
        return ma[i];
    }
    
    ma[i]=func(i/p)+func(i/q);

    return ma[i];
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>p>>q;

    ma[0] = 1;
    cout<<func(n)<<endl;

    return 0;
}