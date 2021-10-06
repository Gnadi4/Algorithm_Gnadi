#include <iostream>
#include <map>

using namespace std;
using ll = long long;


void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,p,q;
    cin>>n>>p>>q;

    map<ll, ll> ma;
    
    pair<ll, ll> pa;
    pa=make_pair(1,0);
    ma.insert(pa);
    int tmp = 0;
    map<ll, ll>::iterator iter1 = ma.begin();
    map<ll, ll>::iterator iter2 = ma.begin();
    int p_tmp = iter1->first;
    int q_tmp = iter2->first;
    for(int i=1; i<=n; i++){
        int a;
        map<ll, ll>::iterator iter1_original;
        map<ll, ll>::iterator iter2_original;
        iter1_original=iter1;
        iter2_original=iter2;
        iter1++;
        iter2++;
        if(i/p==iter1->second){
            
        }else{
            iter1 = iter1_original;
        }
        if(i/q==iter2->second){

        }else{
            iter2 = iter2_original;
        }

        a=iter1->first+iter2->first;
        
        if(i==n)cout<<a<<'\n';

        pair<ll, ll> pa;
        pa=make_pair(a,i);
        
        if(ma.find(a)==ma.end())ma.insert(pa);
    }

    return 0;
}

/*
7 2 3
*/
