#include <iostream>
using namespace std;

struct node{
    int val;
    node *prev, *next;
};

int main(){

    node n1,n2,n3;
    n1.val = 10;
    n2.val = 11;
    n3.val = 12;

    n1.next = &n2;
    n2.next = &n3;
    n2.prev = &n1;
    n3.prev = &n2;

    cout<<n1.val<<endl;
    cout<<n3.prev->val<<endl;

    return 0;
}