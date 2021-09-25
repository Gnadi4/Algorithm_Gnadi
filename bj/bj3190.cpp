#include <iostream>
#include <list>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int arr[100][100] = {0,};

    int n,k;
    cin>>n>>k;

    for(int i=0; i<k; i++){
        int x,y;
        cin>>x>>y;

        arr[x-1][y-1]=1;
    }

    int l;
    cin>>l;

    int mov[l];
    char mov_c[l];

    for(int i=0; i<l; i++){
        cin>>mov[i];
        cin>>mov_c[i];
    }

    list<int> pos_x;
    list<int> pos_y;
    pos_x.push_back(0);
    pos_y.push_back(0);

    int co = 0;

    int j=0;
    //0 right 1 down 2 left 3 up
    int status = 1;

    while(true){
        //cout<<pos_x.front()<<' '<<pos_y.front()<<endl;

        if(mov[j]==co){
            if(mov_c[j]=='D'){
                status+=1;
                status%=4;
            }else{
                status-=1;
                if(status==-1){
                    status=3;
                }
            }
            j+=1;
        }

        if(status==2){
            if(pos_x.front()+1>=n){
                co+=1;
                break;
            }
            if(arr[pos_x.front()+1][pos_y.front()]==1){
                arr[pos_x.front()+1][pos_y.front()]=0;
                pos_x.push_front(pos_x.front()+1);
                pos_y.push_front(pos_y.front());
            }else{
                pos_x.push_front(pos_x.front()+1);
                pos_y.push_front(pos_y.front());
                pos_x.pop_back();
                pos_y.pop_back();
            }
        }else if(status==1){
            if(pos_y.front()+1>=n){
                co+=1;
                break;
            }
            if(arr[pos_x.front()][pos_y.front()+1]==1){
                arr[pos_x.front()][pos_y.front()+1]=0;
                pos_x.push_front(pos_x.front());
                pos_y.push_front(pos_y.front()+1);
            }else{
                pos_x.push_front(pos_x.front());
                pos_y.push_front(pos_y.front()+1);
                pos_x.pop_back();
                pos_y.pop_back();
            }
        }else if(status==0){
            if(pos_x.front()-1<0){
                co+=1;
                break;
            }
            if(arr[pos_x.front()-1][pos_y.front()]==1){
                arr[pos_x.front()-1][pos_y.front()]=0;
                pos_x.push_front(pos_x.front()-1);
                pos_y.push_front(pos_y.front());
            }else{
                pos_x.push_front(pos_x.front()-1);
                pos_y.push_front(pos_y.front());
                pos_x.pop_back();
                pos_y.pop_back();
            }
        }else{
            if(pos_y.front()-1<0){
                co+=1;
                break;
            }
            if(arr[pos_x.front()][pos_y.front()-1]==1){
                arr[pos_x.front()][pos_y.front()-1]=0;
                pos_x.push_front(pos_x.front());
                pos_y.push_front(pos_y.front()-1);
            }else{
                pos_x.push_front(pos_x.front());
                pos_y.push_front(pos_y.front()-1);
                pos_x.pop_back();
                pos_y.pop_back();
            }
        }

        //cout<<"this is pos_x size:"<<pos_x.size()<<endl;
        cout<<endl;
        if(pos_x.size()>=4){
            list<int>::iterator iterx=pos_x.begin();
            list<int>::iterator itery=pos_y.begin();
            iterx++,itery++;
            for(;iterx!=pos_x.end();iterx++,itery++){
                cout<<*iterx<<' '<<*itery<<' '<<pos_x.front()<<' '<<pos_y.front()<<endl;
                if(*iterx==pos_x.front() && *itery==pos_y.front()){
                    co+=1;
                    break;
                }
            }
        }

        co+=1;
    }

    cout<<co<<endl;

    return 0;
}