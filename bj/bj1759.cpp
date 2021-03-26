#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char vow[5] = {'a','e','i','o','u'};

char l[15];

void gna(vector <char> val, int n, int m, int ja, int mo, int s){
    if(val.size()==n){
        if(ja>=2&&mo>=1){
            for(int i=0; i<n; i++)cout<<val[i];
            cout<<endl;
            return;
        }else{
            return;
        }
    }

    for(int i=s; i<m; i++){
        val.push_back(l[i]);
        bool ck = false;
        for(int j=0; j<5; j++){
            if(vow[j]==l[i])ck=true;
        }
        if(ck)mo+=1;
        else{ja+=1;}

        gna(val, n, m, ja, mo, i+1);

        if(ck)mo-=1;
        else{ja-=1;}
        val.pop_back();
    }

    return;
}

int main(){

    int n,m;

    cin>>n>>m;

    for(int i=0; i<m; i++)cin>>l[i];

    sort(l,l+m);

    vector <char> val;
    
    gna(val, n, m, 0, 0, 0);

    return 0;
}