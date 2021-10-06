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

        //x로 정렬 되는데 x가 작으면 당연히 y 가 크겠지

        for(int i=0; i<n; i++){
            int a,b;
            scanf("%d%d",&a,&b);
            pair<int,int> p;

            bool chk = true;
            for(iter=m.begin(); iter!=m.end(); iter++){
                if(iter->first>a&&iter->second>b){
                    chk=false;
                    break;
                }
            }

            if(chk){
                for(iter=m.begin(); iter!=m.end();iter++){
                    if(iter->first<a&&iter->second<b){
                        map<int,int>::iterator m1;
                        m1=iter;
                        m1--;
                        m.erase(iter);
                        iter=m1;
                    }
                }
            }

            if(chk){
                p=make_pair(a,b);
                m.insert(p);
            }
            // cout<<m.size()<<endl;
            result+=m.size();
        }

        cout<<result<<"\n";

    }

    return 0;
}