#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    //많은 숫자를 덜 사용 하도록 고르는게 좋을듯 고로 오름차순 정렬 필요

    priority_queue<int, vector<int>, greater<int> > pq;

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;

        pq.push(a);
    }

    long long result = 0;

    int a1, a2;
    a1 = 0;
    a2 = 0;

    if(n==1){
        cout<<0<<"\n";
        return 0;
    }

    while(true){
        if(pq.size()==1)break;

        a1 = pq.top();
        pq.pop();
        a2 = pq.top();
        pq.pop();

        pq.push(a1+a2);
        result+=(a1+a2);
    }

    // cout<<pq.top()<<"\n";

    cout<<result<<"\n";

    return 0;
}