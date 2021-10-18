#include <iostream>
#include <vector>

using namespace std;

vector<int> ve;
vector<int> res;

int n,m;

void func(int pos){

    if(res.size()==m){
        for(int i=0; i<m; i++)cout<<res[i]<<' ';
        cout<<"\n";
        return;
    }

    for(int i=pos; i<n; i++){
        res.push_back(ve[i]);
        func(i);
        res.pop_back();
    }

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;

    for(int i=1; i<=n; i++){
        ve.push_back(i);
    }

    func(0);

    return 0;
}