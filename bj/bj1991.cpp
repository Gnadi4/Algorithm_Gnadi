#include <iostream>
#include <string>

using namespace std;

void func(){

    return;
}

struct node{
    char al;
    node* left;
    node* right;
};

node tmp[26];

void print_pre(node root){
    cout<<root.al;
    if(root.left!=NULL){
        print_pre(*(root.left));
    }
    if(root.right!=NULL){
        print_pre(*(root.right));
    }
}

void print_in(node root){
    if(root.left!=NULL){
        print_in(*(root.left));
    }
    cout<<root.al;
    if(root.right!=NULL){
        print_in(*(root.right));
    }
}

void print_post(node root){
    if(root.left!=NULL){
        print_post(*(root.left));
    }
    if(root.right!=NULL){
        print_post(*(root.right));
    }
    cout<<root.al;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    node* root=new node();

    for(int i=0; i<n; i++){
        char a,b,c;
        cin>>a>>b>>c;

        tmp[int(a)-int('A')].al=a;
        
        if(b!='.'){
            tmp[int(a)-int('A')].left=&tmp[int(b)-int('A')];
        }
        if(c!='.'){
            tmp[int(a)-int('A')].right=&tmp[int(c)-int('A')];
        }
    }

    print_pre(tmp[0]);
    cout<<endl;
    print_in(tmp[0]);
    cout<<endl;
    print_post(tmp[0]);
    cout<<endl;
    return 0;
}