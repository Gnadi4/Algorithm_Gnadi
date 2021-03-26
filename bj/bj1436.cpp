#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int i=1;
    int n;
    cin>>n;

    if(n==1){
        cout<<666<<endl;
        return 0;
    }

    long long result = 666;

    while(true){
        if(i==n)break;
        //bool check = true;
        result+=1;
        string s = to_string(result);
        int ck = 0;
        for(int i=0; i<s.size()-1; i++){
            if(s[i]=='6'&&s[i+1]=='6')ck+=1;
            else{ck=0;}
            if(ck==2)break;
        }

        if(ck>=2)i+=1;
    }

    cout<<result<<endl;

    return 0;
}