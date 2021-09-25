#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    string s;
    cin>>s;
    //65~90

    vector<double> arr;
    stack<double> st;

    for(int i=0; i<n; i++){
        double tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }

    for(int i=0; i<s.size(); i++){
        if(int(s[i])>=65&&int(s[i])<=90){
            st.push(arr[s[i]-65]);
        }else{
            if(s[i]=='+'){
                double a,b;
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                st.push(a+b);
            }else if(s[i]=='-'){
                double a,b;
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                st.push(a-b);
            }else if(s[i]=='*'){
                double a,b;
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                st.push(a*b);
            }else{
                double a,b;
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                st.push(a/b);
            }
        }
    }

    printf("%0.2f",st.top());

    return 0;
}