#include <iostream>
using namespace std;

int main(){

    int N;
    cin>>N;

    for(int testCase = 0; testCase<N; testCase++){
        int num = 0;
        cin>>num;
        int fence[20000];
        for(int i=0; i<num; i++){
            cin>>fence[i];
        }
        int result = 0;
        for(int i=0; i<num; i++){
            int total_count = 1;
            if(i==0 || fence[i]!=fence[i-1]){
                for(int j=i+1; j<num; j++){
                    if(fence[i]>fence[j]){
                        break;
                    }else{total_count+=1;}
                }
                for(int j=i-1; j>=0; j--){
                    if(fence[i]>fence[j]){
                        break;
                    }else{total_count+=1;}
                }
                result = max(result, total_count*fence[i]);
            }
        }
        cout<<result<<endl;
    }

    return 0;
}