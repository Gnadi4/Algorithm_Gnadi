#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,k;
    cin>>n>>k;

    queue<int> q[21];
    queue<int> arr;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        q[s.size()].push(i);
    }

    long long result=0;

    for(int i=0; i<n; i++){
        arr.push(q.front());
        q.pop();
        if(arr.size()>k)arr.pop();
        for(int j=0; j<arr.size(); j++){
            if(arr.front()==q.front())result+=1;
            arr.push(arr.front());
            arr.pop();
        }
    }

    cout<<result<<endl;

    return 0;
}