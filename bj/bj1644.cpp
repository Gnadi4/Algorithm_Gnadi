#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){

    int N;
    cin>>N;

    int prime_number[4000000] = {0,};
    prime_number[0]=1;
    prime_number[1]=1;

    for(int i=2; i<4000000; i++){
        if(prime_number[i]==0){
            for(int j=i*2; j<4000000; j+=i){
                prime_number[j]=1;
            }
        }
    }

    // for(int i=0; i<100; i++){
    //     if(prime_number[i]==0)cout<<i<<endl;
    // }
    vector<int> arr;
    for(int i=2; i<4000000; i++){
        if(prime_number[i]==0)arr.push_back(i);
    }
    queue<int> q;
    int total = 0;
    int i = 0;
    int count = 0;
    while(true){   
        if(total==N){
            count+=1;
            total+=arr[i];
            q.push(arr[i]);
            total-=q.front();
            q.pop();
            i+=1;
        }else if(total<N){
            total+=arr[i];
            q.push(arr[i]);
            i+=1;
        }else if(total>N){
            total-=q.front();
            q.pop();
        }

        if(i>=arr.size())break;
        if(arr[i]>N&&total<N)break;
    }
    
    cout<<count<<endl;

    return 0;
}