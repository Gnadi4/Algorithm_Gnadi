#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int arr[25][25] = {0,};
vector<int> apt_num;
int N;
int co = 0;

void check(int x, int y){
    if(x<N-1&&arr[x+1][y]==1){
        arr[x+1][y]=0;
        co+=1;
        check(x+1,y);
    }
    if(x>0&&arr[x-1][y]==1){
        arr[x-1][y]=0;
        co+=1;
        check(x-1,y);
    }
    if(y<N-1&&arr[x][y+1]==1){
        arr[x][y+1]=0;
        co+=1;
        check(x,y+1);
    }
    if(y>0&&arr[x][y-1]==1){
        arr[x][y-1]=0;
        co+=1;
        check(x,y-1);
    }
    return;
}

void find(int x, int y){
    if(co==0){
        for(int i=x; i<N; i++){
            for(int j=y; j<N; j++){
                if(arr[i][j]==1){
                    co=1;
                    arr[i][j]=0;
                    find(i,j);
                }
            }
        }
    }else{
        check(x,y);
        apt_num.push_back(co);
        co=0;
    }

    return;
}

int main(){

    //input N is matrix x,y size
    cin>>N;

    for(int i=0; i<N; i++){
        string s;
        cin>>s;
        for(int j=0; j<N; j++)arr[i][j]=int(s[j])-int('0');
    }

    find(0,0);

    cout<<apt_num.size()<<endl;

    sort(apt_num.begin(),apt_num.end());

    for(int i:apt_num){
        cout<<i<<endl;
    }

    return 0;
}