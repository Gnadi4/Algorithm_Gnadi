#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> res;
vector<vector<int> > arr;

int n,m;

void func(vector<int> ve){

    if(int(res.size())==m){
        vector<int> tmp;
        for(int i=0; i<m; i++){
            tmp.push_back(res[i]);
        }
        
        arr.push_back(tmp);
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

    sort(arr.begin(),arr.end());

    for(int j=0; j<m; j++)cout<<arr[0][j]<<' ';
    cout<<"\n";

    for(int i=1; i<arr.size(); i++){
        int co = 0;
        for(int j=0; j<m; j++)if(arr[i-1][j]==arr[i][j])co+=1;
        if(co!=m){
            for(int j=0; j<m; j++)cout<<arr[i][j]<<' ';
            cout<<"\n";
        }
    }

    return 0;
}