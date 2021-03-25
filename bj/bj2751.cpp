#include <iostream>
#include <vector>
using namespace std;

void MG(vector <int> &val, int s, int e){

    if((e-s+1)==1)return;

    int tmp = e-s+1;

    vector <int> val_tmp;

    if(tmp%2==1){
        MG(val, s, s+(tmp/2));
        MG(val, s+(tmp/2)+1, e);
        int s1 = s;
        int s2 = s+(tmp/2)+1;
        while(true){
            if(s1>s+(tmp/2)){
                for(s2; s2<=e; s2++)val_tmp.push_back(val[s2]);
                break;
            }else if(s2>e){
                for(s1; s1<=s+(tmp/2); s1++)val_tmp.push_back(val[s1]);
                break;
            }
            if(val[s1]>val[s2]){
                val_tmp.push_back(val[s2]);
                s2+=1;
            }else{
                val_tmp.push_back((val[s1]));
                s1+=1;
            }
        }

        for(int i = s; i<=e; i++)val[i]=val_tmp[i-s];
    
    }else{
        MG(val, s, s+(tmp/2)-1);
        MG(val, s+(tmp/2), e);
        int s1 = s;
        int s2 = s+(tmp/2);
        while(true){
            if(s1>s+(tmp/2)-1){
                for(s2; s2<=e; s2++)val_tmp.push_back(val[s2]);
                break;
            }else if(s2>e){
                for(s1; s1<=s+(tmp/2)-1; s1++)val_tmp.push_back(val[s1]);
                break;
            }
            if(val[s1]>val[s2]){
                val_tmp.push_back(val[s2]);
                s2+=1;
            }else{
                val_tmp.push_back((val[s1]));
                s1+=1;
            }
        }

        for(int i = s; i<=e; i++)val[i]=val_tmp[i-s];

    }

    return;
}

int main(){

    int n;
    cin>>n;

    vector<int> val;

    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        val.push_back(tmp);
    }

    MG(val, 0, n-1);

    for(int i=0; i<n; i++)cout<<val[i]<<"\n";

    return 0;
}