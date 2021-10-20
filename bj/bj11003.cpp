#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> result;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    // priority_queue<int, vector<int>, less<int> > ma;
    priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > mi;

    int n,l;
    cin>>n>>l;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;

        if(i+1<=l){
            pair<int, int> p = make_pair(a,i);
            mi.push(p);
            result.push_back(mi.top().first);
        }else{
            pair<int, int> p = make_pair(a,i);
            mi.push(p);
            while(true){
                if(mi.top().second>=(i-l+1)){
                    result.push_back(mi.top().first);
                    break;
                }else{
                    mi.pop();
                }
            }
        }
    }

    for(int i=0; i<result.size(); i++)cout<<result[i]<<' ';

    return 0;
}