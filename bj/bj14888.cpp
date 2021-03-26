#include <iostream>
using namespace std;

int oper[4] = {0,};
int val[11] = {0,};
int result_big = -1000000001;
int result_small = 1000000001;

int cal(int tmp, int eval, int s){
    if(tmp == 0){
        return eval+s;
    }else if(tmp == 1){
        return eval-s;
    }else if(tmp == 2){
        return eval*s;
    }else{
        if(eval<0&&s>0){
            return (-1)*((-1*eval)/s);
        }else{
            return (eval)/(s);
        }
    }
}

void gna(int n, int s, int eval){
    if(n==s){
        //cout<<eval<<endl;
        result_big = max(result_big, eval);
        result_small = min(result_small, eval);
    }
    for(int i=0; i<4; i++){
        if(oper[i]!=0){
            int eval_tmp = cal(i, eval, val[s]);
            oper[i]-=1;
            gna(n, s+1, eval_tmp);
            oper[i]+=1; 
        }
    }
    return;
}

int main(){

    int n;
    cin>>n;

    for(int i=0; i<n; i++)cin>>val[i];

    for(int i=0; i<4; i++)cin>>oper[i];

    gna(n, 1, val[0]);

    cout<<result_big<<endl;
    cout<<result_small<<endl;

    return 0;
}