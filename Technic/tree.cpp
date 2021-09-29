#include <iostream>
#include <vector>
using namespace std;

struct node{
    int val=-1;
    node* parent;
    node* child;
};

void func(node* root){
    node* a;
    (*root).child = a;
    a->val=3;
    // a->val=2;
    // cout<<3<<endl;
    // cout<<a->val<<endl;
    // root->child=a;
}

int main(){

    node* root;
    root->val=1;
    // node a;

    // root.child.push_back(&a);
    // cout<<root.child[0]->val<<endl;;

    func(root);

    cout<<root->val<<endl;
    cout<<root->child->val<<endl;

    return 0;
}