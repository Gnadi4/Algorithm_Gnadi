#include <iostream>
#include <list>
using namespace std;

int result = 0;

int main(){

    list<int> l;

    int arr[50] = {0,};

    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++)l.push_back(i+1);

    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        arr[i]=a;
    }

    for(int i=0; i<m; i++){
        int a=0;
        a=arr[i];

        int b = 0;
        int sum_b = 0;
        list<int>::iterator iter;
        for(iter=l.begin(); iter!=l.end(); iter++){
            if(*iter == a)break;
            b++;
        }
        // cout<<l.size()<<endl;
        if(l.size()-b>=b){
            for(int j=0; j<b; j++){
                l.push_back(l.front());
                l.pop_front();
            }
            sum_b = b;
        }else if(b>l.size()-b){
            for(int j=0; j<l.size()-b; j++){
                l.push_front(l.back());
                l.pop_back();
            }
            sum_b = l.size()-b;
        }

        result+=sum_b;
        l.pop_front();
    }

    cout<<result<<endl;

    return 0;
}