#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
int result=0;

struct node{
    int x,y,r;
    vector<node*> child;
};

bool cmp(int a, int b){
    return a>b;
}

int find_max(node* root){
    if(root->child.size()==0)return 1;
    
    vector<int> arr;

    for(int i=0; i<root->child.size(); i++){
        arr.push_back(find_max(root->child[i]));
    }

    if(arr.size()==1){
        result=max(result,arr[0]);
    }else{
        sort(arr.begin(),arr.end(),cmp);
        int tmp_result=arr[0]+arr[1];
        result=max(result,tmp_result);
    }

    return *max_element(arr.begin(), arr.end())+1;
}

void print_pre(node* root){
    cout<<root->r<<' ';
    if(root->child.size()>0){
        for(int i=0; i<root->child.size(); i++){
            print_pre(root->child[i]);
        }
    }
}

int chk(vector<int>a, vector<int>b){
    if(pow(a[0]-b[0],2)+pow(a[1]-b[1],2)>pow(a[2]+b[2],2)){
        //외부
        return 1;
    }else{
        //내부
        return -1;
    }
}

void input_tr(vector<int>wall, node* root){
    for(int i=0; i<root->child.size(); i++){
        vector<int> tmp;
        tmp.push_back(root->child[i]->x);
        tmp.push_back(root->child[i]->y);
        tmp.push_back(root->child[i]->r);

        if(chk(tmp,wall)<0){
            input_tr(wall, root->child[i]);
            return;
        }
    }
    node* tempnode=new node();
    tempnode->x=wall[0];
    tempnode->y=wall[1];
    tempnode->r=wall[2];
    root->child.push_back(tempnode);

    return;
}

bool compare(vector<int> a, vector<int> b){
    return a[2]>b[2];
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int c;
    cin>>c;
    for(int test=0; test<c; test++){
        int n;
        cin>>n;

        int a,b,c;
        cin>>a>>b>>c;
        node* root=new node();
        root->x=a;
        root->y=b;
        root->r=c;

        vector< vector<int> >wall;
        vector<int> wall_val;

        for(int i=0; i<n-1; i++){
            wall_val.clear();
            int a,b,c;
            cin>>a>>b>>c;

            wall_val.push_back(a);
            wall_val.push_back(b);
            wall_val.push_back(c);

            wall.push_back(wall_val);
        }

        sort(wall.begin(),wall.end(),compare);

        //sort 확인용 출력
        // for(int i=0; i<wall.size(); i++){
        //     cout<<wall[i][2]<<endl;
        // }
        for(int i=0; i<n-1; i++){
            input_tr(wall[i],root);
        }
        
        // print_pre(root);

        find_max(root);
        cout<<result<<endl;
        result=0;
    }

    return 0;
}