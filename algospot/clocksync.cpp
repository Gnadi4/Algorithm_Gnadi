#include <iostream>
using namespace std;

//몇번 돌렸는지 확인 각 스위치별 3번까지 가능
int check[10]={0,};

//시계 상황
int clock[16]={0,};

const int sw[10][5]={{0,1,2,-1,-1},{3,7,9,11,-1},{4,10,14,15,-1},{0,4,5,6,7},{6,7,8,10,12},{0, 2, 14, 15,-1},{3, 14, 15,-1,-1},{4, 5, 7, 14, 15},{1, 2, 3, 4, 5},{3, 4, 5, 9, 13}};

int result = 444;

void proc(int n, int s){
    bool check_tmp = true;
    // int result_t = 0;
    // for(int i=0; i<10; i++){
    //     result_t+=check[i];
    // }
    if(result<=n)return;
    for(int i=0; i<16; i++){
        if(clock[i]!=12){
            check_tmp = false;
            break;
        }
    }
    if(check_tmp){
        // int result_tmp = 0;
        // for(int i=0; i<10; i++){
        //     if(check[i]==4)n-=4;
        // }
        result = min(result,n);
        return;
    }
    // for(int i=0; i<10; i++){
    //     if(check[i]<4){
    //         for(int j=0; j<5; j++){
    //             if(sw[i][j]!=-1){
    //                 if(clock[sw[i][j]]==9)clock[sw[i][j]]=12;
    //                 else{clock[sw[i][j]]=(clock[sw[i][j]]+3)%12;}
    //             }
    //         }
    //         check[i]+=1;
    //         proc(n+1);
    //         check[i]-=1;
    //         for(int j=0; j<5; j++){
    //             if(sw[i][j]!=-1){
    //                 if(clock[sw[i][j]]==3)clock[sw[i][j]]=12;
    //                 else{clock[sw[i][j]]-=3;}
    //             }
    //         }
    //     }
    // }
    if(s==10)return;
    for(int i=0; i<4; i++){
        if(i==0)proc(n,s+1);
        else{
            int a[5]={0,};
            for(int j=0; j<5; j++){
                if(sw[s][j]!=-1){
                    a[j]=clock[sw[s][j]];
                    clock[sw[s][j]]=(clock[sw[s][j]]+3*i)%12;
                    if(clock[sw[s][j]]==0)clock[sw[s][j]]=12;
                }
                // if(sw[s][j]!=-1){
                //     if(clock[sw[s][j]]==9)clock[sw[s][j]]=12;
                //     else{clock[sw[s][j]]=(clock[sw[s][j]]+3)%12;}
                // }
            }
            //check[s]+=1;
            proc(n+1,s+1);
            //check[s]-=1;
            // for(int j=0; j<5; j++){
            //     if(sw[s][j]!=-1){
            //         if(clock[sw[s][j]]==3)clock[sw[s][j]]=12;
            //         else{clock[sw[s][j]]-=3;}
            //     }
            // }
            for(int j=0; j<5; j++){
                if(a[j]!=0)clock[sw[s][j]]=a[j];
            }
        }
    }

    return;
}

int main(){

    int T;
    cin>>T;

    for(int test=0; test<T; test++){
        for(int i=0; i<16; i++){
            cin>>clock[i];
        }

        proc(0,0);

        if(result==444)cout<<-1<<endl;
        else{cout<<result<<endl;}
        result = 444;

        //for(int i=0; i<10; i++)check[i] = 0;
    }

    return 0;
}