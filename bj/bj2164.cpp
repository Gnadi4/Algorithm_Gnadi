#include <iostream>
#include <queue>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    queue<int> q;

    for(int i=0; i<n; i++){
        q.push(i+1);
    }

    while(true){
        if(q.size()==1){
            cout<<q.front()<<endl;
            break;
        }else{
            q.pop();
            q.push(q.front());
            q.pop();
        }
    }

    return 0;
}