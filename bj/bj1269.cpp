#include <iostream>
#include <map>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    map<int, int> ma;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;

        pair<int, int> pa;

        pa=make_pair(a,a);
        ma.insert(pa);
    }

    map<int,int>::iterator iter;

    int co = 0;

    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        iter=ma.lower_bound(a);

        if(iter==ma.end()){

        }else if(iter->first==a){
            co+=1;
        }
    }

    cout<<n+m-2*co<<endl;

    return 0;
}


/*
3 5
1 2 4
2 3 4 5 6
*/