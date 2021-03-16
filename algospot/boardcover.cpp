#include <iostream>
using namespace std;

int result = 0;

void mk(int game[20][20], int h, int w){
    bool to_check = true;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            //cout<<game[i][j]<<' ';
            if(game[i][j]==0)to_check=false;
        }
        //cout<<endl;
    }

    if(to_check){
        result+=1;
        return;
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(game[i][j]==0){
                // if(i<h-1){
                //     // if(j<w-1&&game[i+1][j]==0&&game[i+1][j+1]==0){
                //     //     game[i][j]=game[i+1][j]=game[i+1][j+1]=1;
                //     //     mk(game,h,w,i+1,j+1);
                //     //     game[i][j]=game[i+1][j]=game[i+1][j+1]=0;
                //     // }
                //     if(j>0&&game[i+1][j]==0&&game[i+1][j-1]==0){
                //         game[i][j]=game[i+1][j]=game[i+1][j-1]=1;
                //         mk(game,h,w);
                //         game[i][j]=game[i+1][j]=game[i+1][j-1]=0;
                //     }
                // }
                if(i>0){
                    if(j<w-1){
                        if(game[i-1][j]==0&&game[i-1][j+1]==0){
                            game[i][j]=game[i-1][j]=game[i-1][j+1]=1;
                            mk(game,h,w);
                            game[i][j]=game[i-1][j]=game[i-1][j+1]=0;
                        }
                        if(game[i][j+1]==0&&game[i-1][j+1]==0){
                            game[i][j]=game[i][j+1]=game[i-1][j+1]=1;
                            mk(game,h,w);
                            game[i][j]=game[i][j+1]=game[i-1][j+1]=0;
                        }       
                    }
                    if(j>0){
                        if(game[i-1][j]==0&&game[i-1][j-1]==0){
                            game[i][j]=game[i-1][j]=game[i-1][j-1]=1;
                            mk(game,h,w);
                            game[i][j]=game[i-1][j]=game[i-1][j-1]=0;
                        }
                        if(game[i][j-1]==0&&game[i-1][j-1]==0){
                            game[i][j]=game[i][j-1]=game[i-1][j-1]=1;
                            mk(game,h,w);
                            game[i][j]=game[i][j-1]=game[i-1][j-1]=0;
                        }
                    }
                }
                // if(j<w-1){
                //     // if(i<h-1&&game[i][j+1]==0&&game[i+1][j+1]==0){
                //     //     game[i][j]=game[i][j+1]=game[i+1][j+1]=1;
                //     //     mk(game,h,w);
                //     //     game[i][j]=game[i][j+1]=game[i+1][j+1]=0;
                //     // }
                    
                // }
                // if(j>0){
                //     // if(i<h-1&&game[i][j-1]==0&&game[i+1][j-1]==0){
                //     //     game[i][j]=game[i][j-1]=game[i+1][j-1]=1;
                //     //     mk(game,h,w);
                //     //     game[i][j]=game[i][j-1]=game[i+1][j-1]=0;
                //     // }
                    
                // }
            }
        }
    }
    return;
}

int main(){

    int T;
    cin>>T;

    for(int test = 0; test<T; test++){
        int h,w;
        cin>>h>>w;

        int game[20][20];

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                char tmp;
                cin>>tmp;

                //1 is # , 0 is .
                if(tmp=='#'){
                    game[i][j]=1;
                }else{
                    game[i][j]=0;
                }
            }
        }

        // for(int i=0; i<h; i++){
        //     for(int j=0; j<w; j++){
        //         cout<<game[i][j]<<' ';
        //     }cout<<endl;
        // }

        mk(game, h, w);

        cout<<result<<endl;
        result = 0;
    }

    return 0; 
}