#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct node{
    int val;
    node* left;
    node* right;
};

void func(vector<int> pre, vector<int> in, node* root){
    if(pre.size()==1){
        root->val=pre[0];
        return;
    }

    root->val=pre[0];

    int pos=0;

    for(int i=0; i<pre.size(); i++){
        if(pre[0]==in[i]){
            pos=i;
            break;
        }
    }

    vector<int> pre_tmp;
    vector<int> in_tmp;

    for(int i=0; i<pos; i++){
        pre_tmp.push_back(pre[i+1]);
        in_tmp.push_back(in[i]);
    }
    if(pre_tmp.size()>0){
        node* tmp=new node();
        root->left=tmp;
        func(pre_tmp,in_tmp,tmp);
    }

    pre_tmp.clear();
    in_tmp.clear();

    for(int i=pos+1; i<pre.size(); i++){
        pre_tmp.push_back(pre[i]);
        in_tmp.push_back(in[i]);
    }
    if(pre_tmp.size()>0){
        node* tmp_right=new node();
        root->right=tmp_right;
        func(pre_tmp,in_tmp,tmp_right);
    }

    return;
}

void print_post(node* root){
    if(root->left!=NULL){
        print_post(root->left);
    }
    if(root->right!=NULL){
        print_post(root->right);
    }
    cout<<root->val<<' ';
    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int test;
    scanf("%d",&test);

    for(int te=0; te<test; te++){

        int n;
        scanf("%d",&n);

        vector<int> pre;
        vector<int> in;

        for(int i=0; i<n; i++){
            int a;
            scanf("%d",&a);
            pre.push_back(a);
        }
        for(int i=0; i<n; i++){
            int a;
            scanf("%d",&a);
            in.push_back(a);
        }

        node* root=new node();

        func(pre,in,root);

        print_post(root);
        cout<<'\n';
    }

    return 0;
}