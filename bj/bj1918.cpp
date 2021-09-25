#include <iostream>
#include <stack>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin>>s;

    stack<char> st;

    for(int i=0; i<s.size(); i++){
        if(s[i]=='+'){
            while(true){
                if(st.empty()){
                    st.push(s[i]);
                    break;
                }else if(st.top()=='*'||st.top()=='/'||st.top()=='+'||st.top()=='-'){
                    cout<<st.top();
                    st.pop();
                }else if(st.top()=='('){
                    st.push(s[i]);
                    break;
                }
            }
        }else if(s[i]=='-'){
            while(true){
                if(st.empty()){
                    st.push(s[i]);
                    break;
                }else if(st.top()=='*'||st.top()=='/'||st.top()=='+'||st.top()=='-'){
                    cout<<st.top();
                    st.pop();
                }else if(st.top()=='('){
                    st.push(s[i]);
                    break;
                }
            }
        }else if(s[i]=='*'){
            while(true){
                if(st.empty()){
                    st.push(s[i]);
                    break;
                }else if(st.top()=='*'||st.top()=='/'){
                    cout<<st.top();
                    st.pop();
                }else if(st.top()=='('||st.top()=='+'||st.top()=='-'){
                    st.push(s[i]);
                    break;
                }
            }
        }else if(s[i]=='/'){
            while(true){
                if(st.empty()){
                    st.push(s[i]);
                    break;
                }else if(st.top()=='*'||st.top()=='/'){
                    cout<<st.top();
                    st.pop();
                }else if(st.top()=='('||st.top()=='+'||st.top()=='-'){
                    st.push(s[i]);
                    break;
                }
            }
        }else if(s[i]=='('){
            st.push(s[i]);
        }else if(s[i]==')'){
            while(true){
                if(st.top()=='('){
                    st.pop();
                    break;
                }else{
                    cout<<st.top();
                    st.pop();
                }
            }
        }else{
            cout<<s[i];
        }
    }

    while(true){
        if(st.empty())break;
        else{
            cout<<st.top();
            st.pop();
        }
    }

    return 0;
}