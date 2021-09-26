#include <iostream>
#include <stack>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    stack<int> l[6];

    int n,p;
    cin>>n>>p;

    int result = 0;

    for(int test=0; test<n; test++){
        int a,b;
        cin>>a>>b;

        while(true){
            if(l[a-1].empty()){
                l[a-1].push(b);
                result+=1;
                break;
            }else{
                if(l[a-1].top()<b){
                    l[a-1].push(b);
                    result+=1;
                    break;
                }else if(l[a-1].top()==b){
                    break;
                }else{
                    l[a-1].pop();
                    result+=1;
                }
            }
        }
    }

    cout<<result<<endl;

    return 0;
}