#include <iostream>
using namespace std;

int val[100][100]={0,};
int pa[100][100]={0,};
int ck = 0;

void gna(int n, int sx, int sy){

    if(sx+1<n&&pa[sx+1][sy]==0){
        pa[sx+1][sy]=1;
        gna(n,sx+1,sy);
    }
    if(sy+1<n&&pa[sx][sy+1]==0){
        pa[sx][sy+1]=1;
        gna(n,sx,sy+1);
    }
    if(sx-1>=0&&pa[sx-1][sy]==0){
        pa[sx-1][sy]=1;
        gna(n,sx-1,sy);
    }
    if(sy-1>=0&&pa[sx][sy-1]==0){
        pa[sx][sy-1]=1;
        gna(n,sx,sy-1);
    }

    return;
}

int main(){

    //최대값, 높이 저장 배열, 색칠 배열

    int n;
    cin>>n;
    int mh = 0;
    int result = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>val[i][j];
            mh = max(mh, val[i][j]);
        }
    }

    for(int i=0; i<mh; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(val[j][k]<=i)pa[j][k]=2;
            }
        }

        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(pa[j][k]==0){
                    pa[j][k]=1;
                    gna(n,j,k);
                    ck+=1;
                }
            }
        }
        //gna(n,0,0);

        //cout<<ck<<endl;

        result = max(result,ck);
        ck = 0;

        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                pa[j][k]=0;
            }
        }

    }

    cout<<result<<endl;

    return 0;
}