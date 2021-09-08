#include <iostream>
#include <math.h>
using namespace std;

int arr[10000] = {0,};
int check[10000] = {0,};
int result = 1000000;

void func(int n, int m, int count){
    if(n==m){
        result=min(result,count);
        return;
    }
    // check[n]=1;
    int tmp = n;
    cout<<tmp<<endl;
    tmp=tmp%1000;
    for(int i=1; i<=9; i++){
        tmp+=1000*i;
        if(arr[tmp]==0&&tmp!=n){
            check[tmp]=min(check[tmp],count);
            func(tmp,m,check[tmp]+1);
        }
        tmp-=1000*i;
    }
    tmp = n;
    tmp-=((tmp%1000)/100)*100;
    for(int i=0; i<=9; i++){
        tmp+=100*i;
        if(arr[tmp]==0&&tmp!=n){
            check[tmp]=min(check[tmp],count);
            func(tmp,m,check[tmp]+1);
        }
        tmp-=100*i;
    }
    tmp = n;
    tmp-=((tmp%100)/10)*10;
    for(int i=0; i<=9; i++){
        tmp+=10*i;
        if(arr[tmp]==0&&tmp!=n){
            check[tmp]=min(check[tmp],count);
            func(tmp,m,check[tmp]+1);
        }
        tmp-=10*i;
    }
    tmp = n;
    tmp-=(tmp%10);
    for(int i=0; i<=9; i++){
        tmp+=1*i;
        if(arr[tmp]==0&&tmp!=n){
            check[tmp]=min(check[tmp],count);
            func(tmp,m,check[tmp]+1);
        }
        tmp-=1*i;
    }

    return;
}

int main(){
    arr[0]=1;
    arr[1]=1;
    for(int i=2; i<10000; i++){
        if(arr[i]==0){
            for(int j=i+i; j<10000; j+=i){
                arr[j]=1;
            }
        }
    }

    int test;
    cin>>test;
    for(int i=0; i<test; i++){
        int n,m;
        cin>>n>>m;
        int count = 0;
        func(n,m,count);
    }

    cout<<result<<endl;

    return 0;
}