#include <iostream>
using namespace std;

int chess[15][15]={0,};
int result = 0;

void paint(int n, int sx, int sy){
    //가로 세로
    for(int i=0; i<n; i++){
        chess[sx][i]+=1;
        chess[i][sy]+=1;
    }
    //대각선
    int xtmp = sx;
    int ytmp = sy;
    while(true){
        if(xtmp+1<n&&ytmp+1<n)chess[++xtmp][++ytmp]+=1;
        else{break;}
    }
    // xtmp = sx;
    // ytmp = sy;
    // while(true){
    //     if(xtmp+1<n&&ytmp-1>=0)chess[++xtmp][--ytmp]+=1;
    //     else{break;}
    // }
    // xtmp = sx;
    // ytmp = sy;
    // while(true){
    //     if(xtmp-1>=0&&ytmp-1>=0)chess[--xtmp][--ytmp]+=1;
    //     else{break;}
    // }
    xtmp = sx;
    ytmp = sy;
    while(true){
        if(xtmp-1>=0&&ytmp+1<n)chess[--xtmp][++ytmp]+=1;
        else{break;}
    }
}

void depaint(int n, int sx, int sy){
    //가로 세로
    for(int i=0; i<n; i++){
        chess[sx][i]-=1;
        chess[i][sy]-=1;
    }
    //대각선
    int xtmp = sx;
    int ytmp = sy;
    while(true){
        if(xtmp+1<n&&ytmp+1<n)chess[++xtmp][++ytmp]-=1;
        else{break;}
    }
    // xtmp = sx;
    // ytmp = sy;
    // while(true){
    //     if(xtmp+1<n&&ytmp-1>=0)chess[++xtmp][--ytmp]-=1;
    //     else{break;}
    // }
    // xtmp = sx;
    // ytmp = sy;
    // while(true){
    //     if(xtmp-1>=0&&ytmp-1>=0)chess[--xtmp][--ytmp]-=1;
    //     else{break;}
    // }
    xtmp = sx;
    ytmp = sy;
    while(true){
        if(xtmp-1>=0&&ytmp+1<n)chess[--xtmp][++ytmp]-=1;
        else{break;}
    }
}

void mk(int n, int c, int sy){

    //base-case
    if(c==n){result+=1;return;}
    if(sy==n)return;
    //cout<<c<<endl;
    
    for(int i=0; i<n; i++){
    //for(int j=sy; j<n; j++){
        if(chess[i][sy]==0){
            //chess[i][sy]+=1;
            paint(n,i,sy);
            mk(n, c+1, sy+1);
            //chess[i][sy]-=1;
            depaint(n,i,sy);
        }
    }
    

    return;
}

int main(){

    int n;
    cin>>n;

    mk(n, 0, 0);

    cout<<result<<endl;

    return 0;
}