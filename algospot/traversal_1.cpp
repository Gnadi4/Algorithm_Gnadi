#include <iostream>
#include <vector>

using namespace std;

struct node{
    int val;
    node* parent;
    node* left=NULL;
    node* right=NULL;
};

void print_tree(node* root){
    cout<<root->val<<endl;
    if(root->left!=NULL){
        print_tree(root->left);
    }
    if(root->right!=NULL){
        print_tree(root->right);
    }
    return;
}

void func(vector<int> pre, vector<int> in, node* root){
    // cout<<pre.size()<<endl;
    if(pre.size()==0)return;
    if(pre.size()==1){
        root->val=pre[0];
        return;
    }

    root->val=pre[0];

    vector<int>pre_tmp;
    vector<int>in_tmp;
    cout<<0<<endl;

    int pos=0;
    for(int i=0; i<in.size(); i++){
        if(in[i]==pre[0]){
            pos==i;
            break;
        }
    }
    cout<<1<<endl;
    for(int i=1; i<=pos; i++){
        pre_tmp.push_back(pre[i]);
        in_tmp.push_back(in[i-1]);
    }
    cout<<2<<endl;
    // node* left_tmp;
    // root.left=left_tmp;
    // left_tmp->parent=&root;
    func(pre_tmp,in_tmp,root->left);

    pre_tmp.clear();
    in_tmp.clear();
    cout<<3<<endl;
    for(int i=pos+1; i<in.size(); i++){
        pre_tmp.push_back(pre[i]);
        in_tmp.push_back(in[i]);
    }
    cout<<4<<endl;
    // node* right_tmp;
    // root.right=right_tmp;
    // right_tmp->parent=&root;
    func(pre_tmp,in_tmp,root->right);
    cout<<5<<endl;
    return;
}

int main(){

    int t;
    cin>>t;

    for(int test=0; test<t; test++){
        int n;
        cin>>n;

        vector<int> pre;
        vector<int> in;

        for(int i=0; i<n; i++){
            int a;
            cin>>a;
            pre.push_back(a);
        }
        for(int i=0; i<n; i++){
            int a;
            cin>>a;
            in.push_back(a);
        }

        node* root;

        func(pre,in,root);

        // cout<<root.val<<endl;
        print_tree(root);
    }

    return 0;
}