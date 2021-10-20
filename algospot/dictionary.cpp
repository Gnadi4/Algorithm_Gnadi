#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

vector<vector<int> > arr;
vector<bool> visited;
bool chk = false;
vector<int> result;

void func(string a, string b){
    int pos = min(a.size(), b.size());

    for(int i=0; i<pos; i++){
        if(a[i]!=b[i]){
            arr[int(a[i])-97][int(b[i])-97] = 1;
            return;
        }
    }
}

void dfs(int here){

    visited[here] = true;
    for(int i=0; i<26; i++){
        int there = arr[here][i];

        if(!visited[there])dfs(there);
        else{chk = true; return;}
    }
}

void dfsAll(){
    visited = vector<bool>(arr.size(), false);
    for(int i=0; i<26; i++){
        if(!visited[i])dfs(i);
        if(chk)return;
    }
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int c;
    cin>>c;

    for(int test=0; test<c; test++){
        int n;
        cin>>n;
        // ! vector 관련 기본
        arr = vector<vector<int> >(26, vector<int>(26, 0));

        vector<string> s;
        chk = false;

        for(int i=0; i<n; i++){
            string a;
            cin>>a;
            s.push_back(a);
        }
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                func(s[i],s[j]);
            }
        }

        dfsAll();
        if(chk){
            cout<<"INVALID HYPOTHESIS"<<"\n";
        }else{

        }

    }

    return 0;
}