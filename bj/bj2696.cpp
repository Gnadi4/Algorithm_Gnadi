    #include <iostream>
#include <queue>
#include <vector>

using namespace std;

//중앙값은 pq 두개 운용

int t,m;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>t;

    for(int test=0; test<t; test++){

        cin>>m;

        priority_queue<int, vector<int>, less<int> >maxpq;
        priority_queue<int, vector<int>, greater<int> >minpq;
        cout<<m/2+1<<'\n';
        for(int i=0; i<m; i++){
            int a;
            cin>>a;

            maxpq.push(a);
            if(!minpq.empty()){
                if(maxpq.top()>minpq.top()){
                    int b,c;
                    b=maxpq.top();
                    c=minpq.top();
                    maxpq.pop();minpq.pop();

                    minpq.push(b);
                    maxpq.push(c);
                }
            } 
            
            if(i%2==1){
                minpq.push(maxpq.top());
                maxpq.pop();
            }else{
                if(i!=0&&i%20==0)cout<<'\n';
                cout<<maxpq.top()<<' ';
            }
        }
    }

    return 0;
}