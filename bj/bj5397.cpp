#include <iostream>
#include <list>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int test=0; test<n; test++){
        string s;
        cin>>s;

        list<char> l;
        //e
        l.push_back(']');
        //s
        l.push_back('[');

        for(int i=0; i<s.size(); i++){
            if(s[i]=='<'&&l.back()!='['){
                l.push_front(l.back());
                l.pop_back();
            }else if(s[i]=='>'&&l.front()!=']'){
                l.push_back(l.front());
                l.pop_front();
            }else if(s[i]=='-'&&l.back()!='['){
                l.pop_back();
            }else if(s[i]!='<'&&s[i]!='>'&&s[i]!='-'){
                l.push_back(s[i]);
            }
        }

        for(int i=0; i<l.size(); i++){
            if(l.front()=='[')break;
            else{
                l.push_back(l.front());
                l.pop_front();
            }
        }
        l.pop_front();
        l.pop_back();

        list<char>::iterator iter;
        for(iter=l.begin(); iter!=l.end();iter++){
            cout<<*iter;
        }cout<<endl;
    }

    return 0;
}