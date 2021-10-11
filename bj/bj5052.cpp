#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
using ll = long long;

vector<string> ve;
map<int, string> ma;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int testcase;
    cin>>testcase;
    for(int te=0; te<testcase; te++){
        int n;
        cin>>n;

        ma.clear();

        for(int i=0; i<n; i++){
            string a;
            cin>>a;
            pair<int,string> pa;
            pa = make_pair(a.size(),a);
            ma.insert(pa);
        }

        map<int, string>::iterator iter1;
        map<int, string>::iterator iter2;
        bool chk = true;
        for(iter1 = ma.begin(); iter1!=ma.end(); iter1++){
            // cout<<iter1->second<<endl;
            for(iter2 = iter1; iter2!=ma.end(); iter2++){
                // cout<<iter2->second<<endl;
                if(iter1->second==iter2->second){

                }else{
                    bool chk_small = false;
                    for(int i=0; i<iter1->second.size(); i++){
                        if(iter1->second[i]!=iter2->second[i]){
                            chk_small = true;
                        }
                    }
                    chk = chk_small;
                }
                if(!chk)break;
            }
            if(!chk)break;
        }

        if(chk){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}

/*
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
*/