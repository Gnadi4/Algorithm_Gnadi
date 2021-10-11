#include <iostream>
#include <string>

using namespace std;

struct node{
    string st;

    node* left;
    node* right;
};

void func(){

    return;
}

bool insert(string s, node* root){
    if(root->st == ""){
        root->st = s;
        return;
    }else{
        if(stoi(root->st)>stoi(s)){
            if(root->left->st==""){
                node* tmp = new node();
                root->left = tmp;
                insert(s, root->left);
            }else{
                insert(s, root->left);
            }
        }else{
            if(root->right->st==""){
                node* tmp = new node();
                root->right = tmp;
                insert(s, root->right);
            }else{
                insert(s, root->right);
            }
        }
    }
    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;

    for(int test=0; test<t; test++){
        int n;
        cin>>n;

        node* root = new node();

        for(int i=0; i<n; i++){
            string s;
            cin>>s;

            if(!insert(s, root)){
                
            }
        }

    }

    return 0;
}