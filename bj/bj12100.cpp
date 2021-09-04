#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int result = 0;
int arr[20][20] = {0,};

void run_program(int co, int size_n){
    if(co==5){
        for(int i=0; i<size_n; i++){
            for(int j=0; j<size_n; j++){
                result = max(result, arr[i][j]);
            }
        }
        return;
    }
    
    //위
    cout<<111111<<endl;
    int up[20][20]={0,};
    for(int i=0; i<size_n; i++){
        for(int j=0; j<size_n; j++){
            up[i][j] = arr[i][j];
        }
    }
    queue<int> tmp;
    queue<int> re;
    for(int i=0; i<size_n; i++){
        for(int j=0; j<size_n; j++){
            if(arr[i][j]!=0)tmp.push(arr[i][j]);
            arr[i][j]=0;
        }
        while(true){
            if(!tmp.empty()){
                int value_tmp=0;
                value_tmp=tmp.front();
                //if(tmp.front()==0)cout<<"WTF!!!"<<endl;
                tmp.pop();
                cout<<value_tmp<<endl;
                if(value_tmp==tmp.front()){
                    re.push(value_tmp*2);
                    tmp.pop();
                }else{
                    re.push(value_tmp);
                }
            }else{
                cout<<"out!!!!!!!!!!"<<endl;
                break;
            }
        }
        int j=0;
        while(true){
            if(re.empty()){
                break;
            }else{
                cout<<33333<<endl;
                arr[i][j]=re.front();
                re.pop();
                j++;
            }
        }
    }
    run_program(co+1, size_n);
    for(int i=0; i<size_n; i++){
        for(int j=0; j<size_n; j++){
            arr[i][j]=up[i][j];
        }
    }
    cout<<44444<<endl;

    //아래
    int down[20][20]={0,};
    for(int i=0; i<size_n; i++){
        for(int j=0; j<size_n; j++){
            down[i][j] = arr[i][j];
        }
    }
    queue<int> tmp2;
    queue<int> re2;
    for(int i=0; i<size_n; i++){
        for(int j=size_n-1; j>=0; j--){
            if(arr[i][j]!=0)tmp2.push(arr[i][j]);
            arr[i][j]=0;
        }
        while(true){
            if(!tmp2.empty()){
                int value_tmp=0;
                value_tmp=tmp2.front();
                if(tmp2.front()==0)cout<<"WTF!!!"<<endl;
                tmp2.pop();
                // cout<<"here222"<<tmp.size()<<endl;
                if(value_tmp==tmp2.front()){
                    re2.push(value_tmp*2);
                    tmp2.pop();
                }else{
                    re2.push(value_tmp);
                }
            }else{
                cout<<"out!!!!!!!!!!"<<endl;
                break;
            }
        }
        int j=size_n-1;
        while(true){
            if(re2.empty()){
                break;
            }else{
                arr[i][j]=re2.front();
                re2.pop();
                j--;
            }
        }
    }
    run_program(co+1, size_n);
    for(int i=0; i<size_n; i++){
        for(int j=0; j<size_n; j++){
            arr[i][j]=down[i][j];
        }
    }

    //오른쪽
    int right[20][20]={0,};
    for(int i=0; i<size_n; i++){
        for(int j=0; j<size_n; j++){
            right[i][j] = arr[i][j];
        }
    }
    queue<int> tmp3;
    queue<int> re3;
    for(int i=0; i<size_n; i++){
        for(int j=0; j<size_n; j++){
            if(arr[j][i]!=0)tmp3.push(arr[j][i]);
            arr[j][i]=0;
        }
        while(true){
            if(!tmp.empty()){
                int value_tmp=0;
                value_tmp=tmp3.front();
                tmp3.pop();
                cout<<tmp3.size()<<endl;
                if(value_tmp==tmp3.front()){
                    re3.push(value_tmp*2);
                    tmp3.pop();
                }else{
                    re3.push(value_tmp);
                }
            }else{
                cout<<"out!!!!!!!!!!"<<endl;
                break;
            }
        }
        int j=0;
        while(true){
            if(re3.empty()){
                break;
            }else{
                arr[j][i]=re3.front();
                re3.pop();
                j++;
            }
        }
    }
    run_program(co+1, size_n);
    for(int i=0; i<size_n; i++){
        for(int j=0; j<size_n; j++){
            arr[i][j]=up[i][j];
        }
    }

    //왼쪽
    int left[20][20]={0,};
    for(int i=0; i<size_n; i++){
        for(int j=0; j<size_n; j++){
            left[i][j] = arr[i][j];
        }
    }
    queue<int> tmp4;
    queue<int> re4;
    for(int i=0; i<size_n; i++){
        for(int j=size_n-1; j>=0; j--){
            if(arr[j][i]!=0)tmp4.push(arr[j][i]);
            arr[j][i]=0;
        }
        while(true){
            if(!tmp4.empty()){
                int value_tmp=0;
                value_tmp=tmp4.front();
                tmp4.pop();
                cout<<tmp4.size()<<endl;
                if(value_tmp==tmp4.front()){
                    re4.push(value_tmp*2);
                    tmp4.pop();
                }else{
                    re4.push(value_tmp);
                }
            }else{
                cout<<"out!!!!!!!!!!"<<endl;
                break;
            }
        }
        int j=size_n-1;
        while(true){
            if(re4.empty()){
                break;
            }else{
                arr[j][i]=re4.front();
                re4.pop();
                j--;
            }
        }
    }
    run_program(co+1, size_n);
    for(int i=0; i<size_n; i++){
        for(int j=0; j<size_n; j++){
            arr[i][j]=up[i][j];
        }
    }
    return;

}

int main(){

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    run_program(0, n);

    cout<<result<<endl;

    return 0;
}