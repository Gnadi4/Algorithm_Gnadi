#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    for(int te=0; te<t; te++){
        string s="";
        cin>>s;
        int a;
        cin>>a;
        deque<int> dq;
        dq.clear();
        string tmp="";
        cin>>tmp;
        vector<string> buf;
        buf.clear();
        string tmp2="";
        for(int i=0; i<tmp.size(); i++){
            if(tmp[i]=='['){
            }
            else if((tmp[i]==']'||tmp[i]==',')&&tmp2!=""){
                buf.push_back(tmp2);
                tmp2="";
            }
            else{
                tmp2+=tmp[i];
            }
        }
        vector<int> buf2;
        buf2.clear();
        for(int i=0; i<buf.size(); i++){
            buf2.push_back(stoi(buf[i]));
        }

        for(int i=0; i<a; i++){
            dq.push_back(buf2[i]);
        }

        //1 front -1 back
        int status = 1;
        int chk=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='R'){
                if(dq.empty()){
                    //////여기에 break를 넣으면 어떡하니!!!!!!!!! 이건 끝이 아닐수도 있는데...
                    chk=1;
                }else{
                    status*=-1;
                }
            }else if(s[i]=='D'){
                if(dq.empty()){
                    chk=2;
                    break;
                }else{
                    if(status==1){
                        dq.pop_front();
                    }else{
                        dq.pop_back();
                    }
                }
            }            
        }
        if(chk==0){
            if(dq.empty()){
                cout<<"[]"<<endl;
            }else{
                cout<<"[";
                if(status==1){
                    while(true){
                        cout<<dq.front();
                        dq.pop_front();
                        if(dq.empty())break;
                        cout<<',';
                    }
                }else{
                    while(true){
                        cout<<dq.back();
                        dq.pop_back();
                        if(dq.empty())break;
                        cout<<',';
                    }
                }
                cout<<"]"<<endl;
            }
        }else if(chk==1){
            cout<<"[]"<<endl;
        }else if(chk==2){
            cout<<"error"<<endl;
        }
    }

    return 0;
}