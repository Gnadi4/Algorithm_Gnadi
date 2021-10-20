#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    priority_queue<int, vector<int>, less<int> > ma;
    priority_queue<int, vector<int>, greater<int> > mi;

    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        int a;
        cin>>a;

        ma.push(a);
        if(!mi.empty()){
            if(mi.top()<ma.top()){
                int b,c;

                b = ma.top();
                c = mi.top();

                ma.pop();
                mi.pop();

                ma.push(c);
                mi.push(b);
            }
        }

        if(i%2==0){
            mi.push(ma.top());
            ma.pop();
            cout<<ma.top()<<"\n";
        }else{
            cout<<ma.top()<<"\n";
        }
    }

    return 0;
}