#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

#define MI 2100000000

int result = MI;

void func(list<int> l, list<int> q, int co){

    if(q.size()==0){
        result = min(result,co);
        return;
    }

    list<int> l_tmp;

    list<int>::iterator iter;
    for(iter=l.begin(); iter!=l.end(); iter++){
        l_tmp.push_back(*iter);
    }

    //left
    int left_co = 0;
    while(true){
        if(l_tmp.front()==q.front()){
            l_tmp.pop_front();
            int tmp = q.front();
            q.pop_front();
            func(l_tmp,q,co+left_co);
            q.push_front(tmp);
            break;
        }else{
            int tmp = l_tmp.front();
            l_tmp.pop_front();
            l_tmp.push_back(tmp);
            left_co+=1;
        }
    }

    // list<int> l_tmp2;

    // for(iter=l.begin(); iter!=l.end(); iter++){
    //     l_tmp2.push_back(*iter);
    // }

    //right
    int right_co = 0;
    while(true){
        if(l.front()==q.front()){
            l.pop_front();
            int tmp = q.front();
            q.pop_front();
            func(l,q,co+right_co);
            q.push_front(tmp);
            break;
        }else{
            int tmp = l.back();
            l.pop_back();
            l.push_front(tmp);
            right_co+=1;
        }
    }

    return;
}

int main(){

    list<int> l;
    list<int> q;

    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++)l.push_back(i+1);

    for(int i=0; i<m; i++){
        int a;
        cin>>a;

        q.push_back(a);
    }

    func(l,q,0);

    cout<<result<<endl;

    return 0;
}