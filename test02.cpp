#include <iostream>
using namespace std;

int main(){

    string s;
    cin>>s;

    cout<<int(s[0])-int('0')<<endl;
    cout<<s[1]<<endl;
    cout<<s[2]<<endl;

    // for(char i:s){
    //     cout<<int(i)<<endl;
    // }

    return 0;
}