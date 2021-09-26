#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int arr[1001]={0,};
    int n;
    cin>>n;

    int i_max = 0;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr[a]=b;
        i_max = max(a,i_max);
    }

    stack<int> l;
    stack<int> r;

    for(int i=0; i<=i_max; i++){
        if(arr[i]==0){
            if(!l.empty()){
                l.push(l.top());
            }
        }else{
            if(l.empty()){
                l.push(arr[i]);
            }else{
                if(l.top()>=arr[i]){
                    l.push(l.top());
                }else{
                    l.push(arr[i]);
                }
            }
        }
        if(arr[i_max-i]==0){
            if(!r.empty()){
                r.push(r.top());
            }
        }else{
            if(r.empty()){
                r.push(arr[i_max-i]);
            }else{
                if(r.top()>=arr[i_max-i]){
                    r.push(r.top());
                }else{
                    r.push(arr[i_max-i]);
                }
            }
        }
    }

    stack<int> result;
    stack<int> tmp;

    while(!r.empty()){
        tmp.push(r.top());
        r.pop();
    }

    while(!l.empty()){
        if(l.top()==tmp.top()){
            result.push(l.top());
            l.pop();
            tmp.pop();
        }else{
            result.push(min(l.top(),tmp.top()));
            l.pop();
            tmp.pop();
        }
    }

    int result_sum=0;
    
    while(!result.empty()){
        result_sum+=result.top();
        result.pop();
    }

    cout<<result_sum<<endl;

    return 0;
}