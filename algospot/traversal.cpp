#include <iostream>
#include <vector>

using namespace std;

struct node{
    int val;
    node* parent;
    node* left;
    node* right;
};

node * func(vector<int>pre, vector<int>in){

    vector<int> l;
    vector<int> l_tmp;
    vector<int> r;
    vector<int> r_tmp;

    node * tmp;
    tmp->val=pre.front();
    int chk=1;

    for(int i=0; i<pre.size(); i++){
            if(in[i]==pre.front()){
                chk*=-1;
            }else if(chk==1){
                l.push_back(in[i]);
                if(i<pre.size()-1)l_tmp.push_back(pre[i+1]);
                if(!l.empty())tmp->left=func(l_tmp,l);
            }else if(chk==-1){
                r.push_back(in[i]);
                if(i<pre.size()-1)r_tmp.push_back(pre[i+1]);
                if(!r.empty())tmp->right=func(r_tmp,r);
            }
        }

    return tmp;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin>>t;

    vector<int> pre;
    vector<int> in;

    for(int test=0; test<t; test++){
        int n;
        cin>>n;
        pre.clear();
        in.clear();

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

        vector<int> l;
        vector<int> l_tmp;
        vector<int> r;
        vector<int> r_tmp;

        node * tr;
        tr->val=pre.front();
        int chk=1;
        for(int i=0; i<n; i++){
            if(in[i]==pre.front()){
                chk*=-1;
            }else if(chk==1){
                l.push_back(in[i]);
                if(i<n-1)l_tmp.push_back(pre[i+1]);
                tr->left=func(l_tmp,l);
            }else if(chk==-1){
                r.push_back(in[i]);
                if(i<n-1)r_tmp.push_back(pre[i+1]);
                tr->right=func(r_tmp,r);
            }
        }
    }

    return 0;
}