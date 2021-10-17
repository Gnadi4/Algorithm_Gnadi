#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;
int k,n;
vector<int> arr;
priority_queue<int, vector<int>, greater<int> > pq;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>k>>n;

    for(int i=0; i<k; i++){
        int a;
        cin>>a;

        arr.push_back(a);
        pq.push(a);
    }
    
    int co = 0;
    while(true){
        int to = pq.top();
        pq.pop();
        if(pq.empty()){
            co+=1;

            if(co==n){
                cout<<to<<"\n";
                break;
            }

            if(ll(to)*ll(arr[0])<INT_MAX)pq.push(to*arr[0]);
        }else if(to!=pq.top()){
            co+=1;

            if(co==n){
                cout<<to<<"\n";
                break;
            }

            for(int j=0; j<k; j++){
                if(ll(to)*ll(arr[j])<INT_MAX)pq.push(to*arr[j]);
            }
        }
    }

    return 0;
}