#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int arr[11] = {0,};
    int ver[11] = {0,};

    for(int test=0; test<11; test++){
        int d,v;
        cin>>d>>v;
        arr[test]=d;
        ver[test]=v;
    }

    sort(arr, arr+11);

    int tmp = 0;
    int result = 0;

    for(int i=0; i<11; i++){
        tmp += arr[i];
        result += tmp;
    }

    for(int i=0; i<11; i++){
        result += (20*ver[i]);
    }

    cout<<result<<endl;

    return 0;
}