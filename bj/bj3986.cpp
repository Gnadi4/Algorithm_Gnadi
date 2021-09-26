#include <iostream>
#include <string>
#include <stack>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    int result=0;

    for(int te=0; te<n; te++){
        string s;
        cin>>s;

        stack<char> l;

        for(int i=0; i<s.size(); i++){
            if(l.empty()){
                l.push(s[i]);
            }else{
                if(l.top()==s[i]){
                    l.pop();
                }else{
                    l.push(s[i]);
                }
            }
        }

        if(l.empty())result+=1;
    }

    cout<<result<<endl;

    return 0;
}