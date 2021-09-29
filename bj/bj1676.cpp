#include <iostream>
#include <algorithm>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    int five = 0;
    int two = 0;

    for(int i=n; i>=1; i--){
        int tmp = i;
        while(true){
            if(tmp%5==0){
                tmp/=5;
                five+=1;
            }else if(tmp%2==0){
                tmp/=2;
                two+=1;
            }else{
                break;
            }
        }
    }

    int result = 0;
    result = min(five,two);
    cout<<result<<endl;

    return 0;
}