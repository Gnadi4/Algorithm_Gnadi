#include <iostream>
#include <stack>

using namespace std;

void func(){

    return;
}

int main(){

    int n;
    cin>>n;

    bool chk = false;

    stack<char> l;

    for(int test=0; test<n; test++){
        chk = false;
        string s;
        cin>>s;
        
        while(!l.empty()){l.pop();}

        for(int i=0; i<s.length(); i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                l.push(s[i]);
            }else{
                if(s[i]==')'){
                    if(l.empty()){
                        chk=true;
                        break;
                    }
                    if(l.top()=='('){
                        l.pop();
                    }else{
                        chk=true;
                    }
                }else if(s[i]==']'){
                    if(l.empty()){
                        chk=true;
                        break;
                    }
                    if(l.top()=='['){
                        l.pop();
                    }else{
                        chk=true;
                    }
                }else if(s[i]=='}'){
                    if(l.empty()){
                        chk=true;
                        break;
                    }
                    if(l.top()=='{'){
                        l.pop();
                    }else{
                        chk=true;
                    }
                }
            }
        }

        if(!l.empty())chk=true;

        if(chk){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }

    return 0;
}