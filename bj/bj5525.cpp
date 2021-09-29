#include <iostream>
#include <string>
#include <queue>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    string s;
    cin>>s;

    queue<char> q;

    int result=0;

    for(int i=0; i<m; i++){
        if(q.empty()){
            if(s[i]=='I'){
                q.push(s[i]);
            }
        }else{
            if(s[i]=='I'&&q.back()=='O'){
                q.push(s[i]);
            }else if(s[i]=='O'&&q.back()=='I'){
                q.push(s[i]);
            }else{
                while(!q.empty()){
                    q.pop();
                }
                if(s[i]=='I')q.push(s[i]);
            }
        }
        if(q.size()==(n*2+1)){
            result+=1;
            q.pop();
            q.pop();
        }
    }

    cout<<result<<endl;

    return 0;
}