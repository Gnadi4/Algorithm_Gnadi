#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;

    long long aa=pow(2,32);

    for(int test=0; test<t; test++){
        int k,n;
        cin>>k>>n;

        long long sum=0;
        long long co=0;
        long long a=1983;

        queue<int> q;

        for(int i=0; i<n; i++){
            // cout<<a%10000+1<<endl;
            q.push(a%10000+1);
            sum+=(a%10000+1);
            // cout<<sum<<endl;

            if(sum==k){
                co+=1;
            }else if(sum<k){

            }else if(sum>k){
                while(sum>k){
                    sum-=q.front();
                    q.pop();
                    if(sum==k)co+=1;
                }
            }

            a = (a*214013+2531011)%aa;
        }

        cout<<co<<endl;

    }

    return 0;
}