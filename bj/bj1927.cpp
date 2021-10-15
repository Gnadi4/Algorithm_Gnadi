#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;

        if(a==0){
            if(!pq.empty()){
                cout<<pq.top()<<"\n";
                pq.pop();
            }else{
                cout<<0<<"\n";
            }
        }else{
            pq.push(a);
        }
    }

    return 0;
}