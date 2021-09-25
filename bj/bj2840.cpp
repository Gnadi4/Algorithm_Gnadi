#include <iostream>
#include <list>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    list<char> l;
    for(int i=0; i<n; i++)l.push_back('a');

    for(int i=0; i<m; i++){
        int p;
        char q;
        cin>>p>>q;

        for(int j=0; j<p; j++){
            l.push_front(l.back());
            l.pop_back();
        }

        if(l.front()=='a'){
            l.pop_front();
            l.push_front(q);
        }else if(l.front()!='a'&&l.front()!=q){
            cout<<'!'<<endl;
            return 0;
        }
    }

    list<char>::iterator iter;

    char arr[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    for(int i=0; i<sizeof(arr)/sizeof(char); i++){
        int co = 0;
        for(iter=l.begin();iter!=l.end();iter++){
            if(arr[i]==*iter)co+=1;
        }

        if(co>=2){
            cout<<'!'<<endl;
            return 0;
        }
    }

    for(iter=l.begin(); iter!=l.end(); iter++){
        if(*iter=='a'){
            cout<<'?';
        }else{
            cout<<*iter;
        }
    }
    cout<<endl;

    return 0;
}