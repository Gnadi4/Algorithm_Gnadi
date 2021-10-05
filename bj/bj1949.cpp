#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int result=0;

struct node{
    int val;
    vector<node*> child;
};

node tmp[10000];

//chk 1 이전 꺼 선택됨 , -1 선택 안됨, -2두번 연속 안됨
int func(node* root, int chk){
    int r_tmp=0;
    if(root->child.size()==0){
        if(chk==1){
            return 0;
        }else if(chk==-1){
            return root->val;
        }else if(chk==-2){
            // cout<<root->val<<endl;
            return root->val;
        }
    }

    int ret=0;

    if(chk==1){
        for(int i=0; i<root->child.size();i++){
            r_tmp=max(r_tmp,func(root->child[i],-1));
            ret+=r_tmp;
        }
    }else if(chk==-1){
        //분기점 연산 어떻게 해야할까...
        if(root->child.size()==1){
            for(int i=0; i<root->child.size();i++){
                r_tmp=max(r_tmp,func(root->child[i],1)+root->val);
                r_tmp=max(r_tmp,func(root->child[i],-2));
                ret+=r_tmp;
            }
        }else{
            int tmp_ret=0;
            for(int i=0; i<root->child.size();i++){
                ret=0;
                for(int j=0; j<root->child.size();j++){
                    if(i!=j){
                        r_tmp=max(r_tmp,func(root->child[i],1)+root->val);
                        r_tmp=max(r_tmp,func(root->child[i],-1));
                        ret+=r_tmp;
                    }else{
                        r_tmp=max(r_tmp,func(root->child[i],-2));
                        ret+=r_tmp;
                    }
                }
                tmp_ret=max(tmp_ret,ret);
            }
            ret=tmp_ret;
        }
    }else if(chk==-2){
        for(int i=0; i<root->child.size();i++){
            r_tmp=max(r_tmp,func(root->child[i],1)+root->val);
            ret+=r_tmp;
        }
    }

    return ret;
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

// void print_pre(node* root){
//     cout<<root->val<<' ';
//     if(root->child.size()!=0){
//         for(int i=0; i<root->child.size(); i++){
//             print_pre(root->child[i]);
//         }
//     }
// }

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

    result=max(result,func(&tmp[0],1));
    result=max(result,func(&tmp[0],-2));

    // print_pre(&tmp[0]);

    cout<<result<<endl;

    return 0;
}