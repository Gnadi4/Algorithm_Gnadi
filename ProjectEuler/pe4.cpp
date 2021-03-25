#include <iostream>
using namespace std;

int main(){

    //palindrome
    int result = 0;
    for(int i=999; i>=100; i--){
        for(int j=i; j>=100; j--){
            //if(i==999&&j==999){
            bool check = true;
            int tmp_r = i*j;
            int tmp = i*j;
            //cout<<tmp<<endl;
            if(tmp<1000000&&tmp>=100000){
                if(tmp/100000!=tmp%10)check=false;
                // cout<<tmp/100000<<endl;
                // cout<<tmp%10<<endl;
                tmp-=(tmp/100000)*100000;
                tmp/=10;
                if(tmp/1000!=tmp%10)check=false;
                // cout<<tmp/100<<endl;
                // cout<<tmp%10<<endl;
                tmp-=(tmp/1000)*1000;
                tmp/=10;
                if(tmp/10!=tmp%10)check=false;
            }else if(tmp<100000&&tmp>=10000){
                if(tmp/10000!=tmp%10)check=false;
                tmp-=(tmp/10000)*10000;
                tmp/=10;
                if(tmp/100!=tmp%10)check=false;
            }
            //cout<<check<<endl;
            if(check){
                result = max(result,tmp_r);
            }
            //}
        }
    }
    cout<<result<<endl;

    return 0;
}