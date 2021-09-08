#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    int total = 0;
    vector<int> arr;

    for(int i=0; i<9; i++){
        cin>>n;
        arr.push_back(n);
        total+=n;
    }

    total = total-100;
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if(total==(arr[i]+arr[j])){
                for(int k=0; k<9; k++){
                    if(k!=i&&k!=j){
                        cout<<arr[k]<<endl;
                    }
                }
                return 0;
            }
        }
    }

    return 0;
}