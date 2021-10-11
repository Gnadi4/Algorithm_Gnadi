#include <iostream>
#include <vector>

using namespace std;

long long arr[4000001]={0,};
vector<int> ve;
int result = 0;
int n;


//n guess, pos position, tsum total_sum
void func(long long front,long long back, long long tsum){

    while(true){
        // cout<<tsum<<endl;
        if(tsum>n){
            tsum-=ve[front];
            front+=1;
        }else if(tsum<=n){
            if(back>=ve.size())break;
            tsum+=ve[back];
            back+=1;
        }
        if(tsum==n){
            result+=1;
        }
    }

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;

    arr[0] = 1;
    arr[1] = 1;

    for(int i=2; i<=4000000; i++){
        // cout<<i<<endl;
        if(arr[i]==0){
            for(int j=i*2; j<=4000000; j+=i){
                arr[j]=1;
            }
        }
    }

    for(int i=2; i<=4000000; i++){
        if(arr[i]==0){
            if(i>n)break;
            // cout<<i<<endl;
            ve.push_back(i);
        }
    }

    if(n==1){
        cout<<0<<"\n";
        return 0;
    }

    // for(int i=0; i<ve.size(); i++)cout<<ve[i]<<endl;

    func(0, 0, 0);

    cout<<result<<"\n";

    return 0;
}