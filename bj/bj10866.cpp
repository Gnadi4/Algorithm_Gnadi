#include <iostream>
#include <deque>
#include <string>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    deque<int> dq;

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;

        if(s=="push_front"){
            int a;
            cin>>a;
            dq.push_front(a);
        }else if(s=="push_back"){
            int a;
            cin>>a;
            dq.push_back(a);
        }else if(s=="pop_front"){
            if(dq.empty()){
                cout<<-1<<endl;
            }else{
                cout<<dq.front()<<endl;
                dq.pop_front();
            }
        }else if(s=="pop_back"){
            if(dq.empty()){
                cout<<-1<<endl;
            }else{
                cout<<dq.back()<<endl;
                dq.pop_back();
            }
        }else if(s=="size"){
            cout<<dq.size()<<endl;
        }else if(s=="back"){
            if(dq.empty()){
                cout<<-1<<endl;
            }else{
                cout<<dq.back()<<endl;
            }
        }else if(s=="front"){
            if(dq.empty()){
                cout<<-1<<endl;
            }else{
                cout<<dq.front()<<endl;
            }
        }else if(s=="empty"){
            if(dq.empty()){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }

    return 0;
}