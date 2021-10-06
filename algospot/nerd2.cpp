#include <iostream>
#include <map>
#include <utility>

using namespace std;

void func(map<int,int> m){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int c;
    cin>>c;

    for(int test=0; test<c; test++){
        int n;
        cin>>n;

        map<int,int> m;

        map<int,int>::iterator iter;

        int result=0;

        for(int i=0; i<n; i++){
            int a,b;
            cin>>a>>b;
            pair<int,int> p;

            for(iter=m.begin(); iter!=m.end();){
                if(iter->first<a&&iter->second<b){
                    m.erase(iter);
                }else{
                    ++iter;
                }
            }

            result+=m.size();
            p=make_pair(a,b);
            m.insert(p);
        }

        cout<<result<<"\n";

    }

    return 0;
}