#include <iostream>
#include <list>
#include <string>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    list<char> l;

    string s;
    cin>>s;

    l.push_back('S');

    for(int i=0; i<s.length(); i++){
        l.push_back(s[i]);
    }

    l.push_front('E');

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        char c;
        cin>>c;
        if(c=='P'){
            char tmp;
            cin>>tmp;
            l.push_back(tmp);
        }else if(c=='B'&&l.back()!='S'){
            l.pop_back();
        }else if(c=='L'&&l.back()!='S'){
            l.push_front(l.back());
            l.pop_back();
        }else if(c=='D'&&l.front()!='E'){
            l.push_back(l.front());
            l.pop_front();
        }
    }

    for(int i=0; i<l.size(); i++){
        if(l.front()=='S'){
            break;
        }else{
            l.push_back(l.front());
            l.pop_front();
        }
    }

    l.pop_front();
    l.pop_back();

    list<char>::iterator iter;
    for(iter=l.begin(); iter!=l.end(); iter++){
        cout<<*iter;
    }cout<<endl;

    return 0;
}