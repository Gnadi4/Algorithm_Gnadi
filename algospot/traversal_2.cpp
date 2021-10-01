#include <iostream>
#include <vector>
using namespace std;

struct node{
    int val;
    node* left=NULL;
    node* right=NULL;
};

node tmp[100];

void p_tree(node* root){
    // cout<<"print side"<<endl;
    if(root->left!=NULL){
        // cout<<1<<endl;
        p_tree(root->left);
    }
    if(root->right!=NULL){
        // cout<<2<<endl;
        p_tree(root->right);
    }
    cout<<root->val<<' ';

    return;
}

void func(vector<int> pre, vector<int> in, node* root){
    // cout<<"presize :"<<pre.size()<<endl;

    root->val=pre[0];

    //base case
    if(pre.size()==1){
        return;
    }

    int pos = 0;
    for(int i=0; i<pre.size(); i++){
        if(pre[0]==in[i]){
            pos=i;
            break;
        }
    }

    // cout<<pos<<endl;

    //left go
    vector<int> pre_l;
    vector<int> in_l;
    pre_l.clear();
    in_l.clear();


    for(int i=0; i<pos; i++){
        pre_l.push_back(pre[i+1]);
        in_l.push_back(in[i]);
    }

    if(pre_l.size()>0){
        node* leftn=new node();
        root->left=leftn;
        func(pre_l,in_l,leftn);
    }

    //right go

    pre_l.clear();
    in_l.clear();

    for(int i=pos+1; i<pre.size(); i++){
        pre_l.push_back(pre[i]);
        in_l.push_back(in[i]);
    }

    if(pre_l.size()>0){
        node* rightn=new node();
        root->right=rightn;
        func(pre_l,in_l,rightn);
    }

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int test;
    cin>>test;

    for(int testcase=0; testcase<test; testcase++){
        int n;
        cin>>n;

        vector<int> pre;
        pre.clear();

        for(int i=0; i<n; i++){
            int a;
            cin>>a;

            pre.push_back(a);
        }

        vector<int> in;
        in.clear();

        for(int i=0; i<n; i++){
            int a;
            cin>>a;

            in.push_back(a);
        }

        node* root=new node();

        func(pre,in,root);

        p_tree(root);
        cout<<endl;
    }

    return 0;
}