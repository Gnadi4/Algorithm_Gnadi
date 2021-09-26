#include <iostream>
#include <stack>
#include <string>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    while(true){
        string s;
        getline(cin,s);
        if(s=="#")break;
        stack<char> l;

        bool chk=false;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='<'){
                l.push(s[i]);
                chk=true;
            }else if(s[i]=='>'){
                if(s[i-1]=='/'){
                    l.push(s[i-1]);
                }
                l.push(s[i]);
                chk=false;
            }else{
                if(s[i]==' ')chk=false;
                if(chk==true)l.push(s[i]);
            }
        }

        // stack<char> tmp;
        // int k = l.size();
        // for(int i=0; i<k; i++){
        //     cout<<l.top()<<endl;
        //     tmp.push(l.top());
        //     l.pop();
        // }

        string a = "";
        stack<string> l1;

        while(!l.empty()){
            //cout<<1<<endl;
            if(l.top()=='>'){
                l.pop();
                if(l.top()=='/'){
                    while(l.top()!='<'){
                        l.pop();
                    }
                    l.pop();
                }else{
                    while(l.top()!='<'){
                        a=l.top()+a;
                        l.pop();
                    }
                    l.pop();
                }
            }
            if(a==""){

            }else{
                if(l1.empty()){
                    l1.push(a);
                    a="";
                }else{
                    //cout<<l1.top()<<' '<<a<<endl;
                    if(!(l1.top()).compare(('/'+a)))l1.pop();
                    else{l1.push(a);}
                    a="";
                }
            }
            
            //cout<<l1.size()<<endl;
        }

        // stack<string> tmp;
        // int k = l1.size();
        // for(int i=0; i<k; i++){
        //     cout<<l1.top()<<endl;
        //     tmp.push(l1.top());
        //     l1.pop();
        // }

        if(l1.empty())cout<<"legal"<<endl;
        else{cout<<"illegal"<<endl;}

    }

    return 0;
}