#include <iostream>
#include <string.h>
using namespace std;

int main(){

    int a=0;
    // cin>>a;
    // cout<<a<<endl;
    // cout<<"inwon"<<endl;

    a = 9999;
    string s = to_string(a);

    for(int i=0; i<s.size(); i++)cout<<s[i]<<endl;



    return 0;
}