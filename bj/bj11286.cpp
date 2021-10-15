#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

int main(){


    cin.tie(0);
    ios::sync_with_stdio(false);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        pair<int, int> pa;
        int a;
        cin>>a;

        pa=make_pair(abs(a),a);

        if(a==0){
            if(pq.empty()){
                cout<<0<<"\n";
            }else{
                cout<<pq.top().second<<"\n";
                pq.pop();
            }
        }else{
            pq.push(pa);
        }
    }

    return 0;
}