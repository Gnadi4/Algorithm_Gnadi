#include <iostream>
#include <vector>
using namespace std;

int ck[8] = {0,};

void gna(int n, int s, vector<int>tmp){
    if(s==n){
        for(int i=0; i<n; i++)printf("%d ",tmp[i]);
        printf("\n");
        return;
    }

    for(int i=0; i<n; i++){
        if(ck[i]==0){
            ck[i] = 1;
            tmp.push_back(i+1);
            gna(n,s+1,tmp);
            tmp.pop_back();
            ck[i] = 0;
        }
    }
    return;

}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    vector<int>tmp;

    gna(n,0,tmp);

    return 0;
}