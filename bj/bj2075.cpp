#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    priority_queue<int, vector<int>, greater<int> > pq;

    int n;
    cin>>n;
    for(int i=0; i<n*n; i++){
        int a;
        cin>>a;
        pq.push(a);
        if(pq.size()>n)pq.pop();
    }

    cout<<pq.top()<<"\n";

    return 0;
}