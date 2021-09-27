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

    for(int i=0; i<21; i++){
        if(q[i].empty()){

        }else{
            queue<int> tmp;
            long long cnt=0;
            while(!q[i].empty()){
                if(tmp.empty()){
                    tmp.push(q[i].front());
                    q[i].pop();
                }else{
                    if(q[i].front()-tmp.front()<=k){
                        tmp.push(q[i].front());
                        q[i].pop();
                        cnt+=tmp.size()-1;
                    }else{
                        tmp.pop();
                    }
                }
            }
            result+=cnt;
        }
    }

    cout<<result<<endl;

    return 0;
}