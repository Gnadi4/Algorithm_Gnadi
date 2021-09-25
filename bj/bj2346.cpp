#include <iostream>
#include <list>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    list<int> l;
    int arr[1000];

    for(int i=0; i<n; i++){
        l.push_back(i+1);
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        int a=0;

        cout<<l.front()<<' ';
        a=arr[l.front()-1];
        l.pop_front();

        if(a>0){
            for(int j=0; j<a-1; j++){
                l.push_back(l.front());
                l.pop_front();
            }
        }else if(a<0){
            l.push_front(l.back());
            l.pop_back();
            for(int j=0; j<(-1)*(a+1); j++){
                l.push_front(l.back());
                l.pop_back();
            }
        }
    }

    return 0;
}