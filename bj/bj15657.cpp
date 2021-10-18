#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> res;

int n,m;

void func(int pos, vector<int> ve){

    if(int(res.size())==m){
        for(int i=0; i<m; i++)cout<<res[i]<<' ';
        cout<<"\n";
        return;
    }

    for(int i=pos; i<n; i++){
        res.push_back(ve[i]);
        func(i,ve);
        res.pop_back();
    }

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;

    vector<int> ve;

    for(int i=1; i<=n; i++){
        int a;
        cin>>a;
        ve.push_back(a);
    }

    sort(ve.begin(),ve.end());

    func(0,ve);

    return 0;
}