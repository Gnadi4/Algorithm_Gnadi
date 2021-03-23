#include <iostream>
using namespace std;

int board[20][20];
int n,m;
int result = 0;

void mk(int sx, int sy){
    
    if(board[sx][sy]==0){
        if(sx<n-1&&sy<m-1){
            if(board[sx+1][sy]==0&&board[sx][sy+1]==0){
                board[sx][sy]=board[sx+1][sy]=board[sx][sy+1]=1;
                if(sx+1==n-1)mk(0,sy+1);
                else{mk(sx+1,sy);}
                board[sx][sy]=board[sx+1][sy]=board[sx][sy+1]=0;
            }
            if(board[sx+1][sy]==0&&board[sx+1][sy+1]==0){
                board[sx][sy]=board[sx+1][sy]=board[sx+1][sy+1]=1;
                if(sx+1==n-1)mk(0,sy+1);
                else{mk(sx+1,sy);}
                board[sx][sy]=board[sx+1][sy]=board[sx+1][sy+1]=0;
            }
            if(board[sx][sy+1]==0&&board[sx+1][sy+1]==0){
                board[sx][sy]=board[sx][sy+1]=board[sx+1][sy+1]=1;
                if(sx+1==n-1)mk(0,sy+1);
                else{mk(sx+1,sy);}
                board[sx][sy]=board[sx][sy+1]=board[sx+1][sy+1]=0;
            }
        }
        if(sx>0&&sy<m-1){
            if(board[sx][sy+1]==0&&board[sx-1][sy+1]==0){
                board[sx][sy]=board[sx][sy+1]=board[sx-1][sy+1]=1;
                if(sx==n-1)mk(0,sy+1);
                else{mk(sx+1,sy);}
                board[sx][sy]=board[sx][sy+1]=board[sx-1][sy+1]=0;
            }
        }
        if(sy==m-1)return;
    }else{
        if(sx==n-1&&sy==m-1)result+=1;
        else if(sx==n-1)mk(0,sy+1);
        else{mk(sx+1,sy);}
        return;
    }
    return;
}

int main(){

    int T;
    cin>>T;

    for(int test=0; test<T; test++){
        
        cin>>n>>m;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char tmp;
                cin>>tmp;

                if(tmp == '#')board[i][j]=1;
                else{board[i][j]=0;}
            }
        }

        mk(0,0);
        cout<<result<<endl;
        result = 0;
    }

    return 0;
}