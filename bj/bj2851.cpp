#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){

    vector<int> arr;
    int n;

    for(int i=0; i<10; i++){
        cin>>n;
        arr.push_back(n);
    }

    int total = 0;

    for(int i=0; i<10; i++){
        if(abs(100-total)==abs(100-total-arr[i])){
            cout<<(total+arr[i])<<endl;
            return 0;
        }else if(abs(100-total)<abs(100-total-arr[i])){
            cout<<total<<endl;
            return 0;
        }else{
            total+=arr[i];
        }
    }
    cout<<total<<endl;

    return 0;
}