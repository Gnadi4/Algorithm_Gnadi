#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> res;

int n,m;

void func(vector<int> ve){

    if(int(res.size())==m){
        for(int i=0; i<m; i++)cout<<res[i]<<' ';
        cout<<"\n";
        return;
    }

    for(int i=0; i<n; i++){
        if(ve[i]!=-1){
            int tmp = ve[i];
            res.push_back(ve[i]);
            ve[i]=-1;
            func(ve);
            res.pop_back();
            ve[i]=tmp;
        }
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

    func(ve);

    return 0;
}