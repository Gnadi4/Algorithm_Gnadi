#include <iostream>
#include <vector>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
};

void print_preorder(){

}

void print_inorder(){

}

void print_postorder(){

}

void func(node* root){
    node* tmp = new node();
    root->left=tmp;
    tmp->val=2;
    // root.right->val=3;
    return;
}

int main(){

    node* root=new node;

    root->val=1;

    func(root);

    cout<<root->val<<endl;
    cout<<root->left->val<<endl;
    // cout<<root->right->val<<endl;

    return 0;
}