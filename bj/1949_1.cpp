#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int result=0;

struct node{
    int val;
    int ch=0;
    vector<node*> child;
};

node tmp[10000];

bool func_check(node* root){
    
}

//chk 1 이전 꺼 선택됨 , -1 선택 안됨, -2두번 연속 안됨
int func(node* root, node* n){
    
    if(n->child.size()==0){
        if(func_check(root)){

        }
    }

    if(root->ch==0){

    }
}

/*
6
10 1 1 1 10 10
1 2
2 3
3 4
4 5
3 6

ans : 30
*/

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        tmp[i].val=a;
    }

    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;

        tmp[min(a,b)-1].child.push_back(&tmp[max(a,b)-1]);
    }

    func(&tmp[0], &tmp[0]);

    // print_pre(&tmp[0]);

    cout<<result<<endl;

    return 0;
}