#include <iostream>
using namespace std;

int lab[8][8]={0,};
int tmp_lab[8][8]={0,};

int result = 0;

void paint(int sx, int sy, int n, int m){
    if(sx+1<n&&tmp_lab[sx+1][sy]==0){
        tmp_lab[sx+1][sy]=2;
        paint(sx+1,sy,n,m);
    }
    if(sy+1<m&&tmp_lab[sx][sy+1]==0){
        tmp_lab[sx][sy+1]=2;
        paint(sx,sy+1,n,m);
    }
    if(sx-1>=0&&tmp_lab[sx-1][sy]==0){
        tmp_lab[sx-1][sy]=2;
        paint(sx-1,sy,n,m);
    }
    if(sy-1>=0&&tmp_lab[sx][sy-1]==0){
        tmp_lab[sx][sy-1]=2;
        paint(sx,sy-1,n,m);
    }
    return;
}

void gna(int n, int m, int s, int sx, int sy){
    
    //base-case
    if(s==3){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                tmp_lab[i][j]=lab[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(lab[i][j]==2)paint(i,j,n,m);
            }
        }
        int co = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(tmp_lab[i][j]==0)co+=1;
            }
        }
        result = max(result,co);

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<tmp_lab[i][j]<<' ';
        //     }cout<<endl;
        // }cout<<endl;

        return;
    }

    //case
    for(int j=sy; j<m; j++){    
        for(int i=sx; i<n; i++){
            if(lab[i][j]==0){
                lab[i][j]=1;
                gna(n,m,s+1,0,0);
                lab[i][j]=0;
            }
        }
    }

    return;
}

int main(){

    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>lab[i][j];
        }
    }

    gna(n, m, 0, 0, 0);

    printf("%d\n",result);

    return 0;
}