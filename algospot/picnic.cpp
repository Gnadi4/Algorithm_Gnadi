#include <iostream>
using namespace std;

int check[10] = {0,};
int student[2][45] = {0,};
int result = 0;

void mk_f(int n, int m, int t, int co){

    if(t >= m && co < n){
        return;
    }else if(co == n){
        result+=1;
        return;
    }

    for(int i=t; i<m; i++){
        if(check[student[0][i]]==0 && check[student[1][i]]==0){
            check[student[0][i]]=1;
            check[student[1][i]]=1;
            mk_f(n, m, i+1, co+2);
            check[student[0][i]]=0;
            check[student[1][i]]=0;
        }
    }
}

int main(){

    int T;
    cin>>T;

    for(int test = T; test>0; test--){
        int n,m;
        cin>>n>>m;

        for(int i = 0; i<m; i++){
            cin>>student[0][i]>>student[1][i];
        }

        //make friend
        mk_f(n,m,0,0);
        cout<<result<<endl;
        result = 0;

    }

    return 0;
}