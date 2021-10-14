#include <iostream>

using namespace std;

typedef int KeyType;

struct Node{
    KeyType key;
    int priority, size;
    Node *left, *right;
    Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL){
    }
    void setLeft(Node* newLeft){left = newLeft; calcSize();}
    void setRight(Node* newRight){ right = newRight; calcSize();}

    void calcSize(){
        size = 1;
        if(left) size += left->size;
        if(right) size += right->size;
    }
};

typedef pair<Node*, Node*> NodePair;

NodePair split(Node* root, KeyType key){
    if(root == NULL) return NodePair(NULL, NULL);
    if(root->key < key){
        NodePair rs = split(root->right, key);
        root->setRight(rs.first);
        return NodePair(root, rs.second);
    }

    NodePair ls = split(root->left, key);
    root->setLeft(ls.second);
    return NodePair(ls.first, root);
}

Node* insert(Node* root, Node* node){
    if(root == NULL) return node;

    if(root->priority < node -> priority){
        NodePair splitted = split(root, node->key);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
        return node;
    }
    else if(node->key < root->key)root->setLeft(insert(root->left, node));
    else root->setRight(insert(root->right, node));
    
    return root;
}

int main(){

    

    return 0;
}