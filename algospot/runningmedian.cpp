#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

int n,a,b;
int result = 0;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin>>T;

    for(int test = 0; test<T; test++){
        cin>>n>>a>>b;
        priority_queue<int, vector<int>, less<int> > pq; // ! maxHeap
        priority_queue<int, vector<int>, greater<int> > pq_tmp; // ! minHeap
        result = 0;
        int azero = 1983;
        for(int i=0; i<n; i++){
            if(i==0){
                // ! a[0] == 1983
                pq.push(1983);
                result = (result + pq.top())%20090711;
            }else{
                int tmp = (azero * ll(a) + b) % 20090711;
                azero = tmp;
                
                // cout<<"tmp :"<<tmp<<endl;

                if(i%2==1){
                    pq_tmp.push(tmp);
                }else{
                    pq.push(tmp);
                }
                
                if(pq.top()>pq_tmp.top()){
                    int k = pq.top();
                    int l = pq_tmp.top();
                    pq.pop();
                    pq_tmp.pop();
                    pq.push(l);
                    pq_tmp.push(k);
                }
                
                result = (result + pq.top())%20090711;
                
            }
        }
        
        cout<<result<<"\n";
    }

    return 0;
}