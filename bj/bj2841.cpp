#include <iostream>
#include <stack>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    stack<int> l1;
    stack<int> l2;
    stack<int> l3;
    stack<int> l4;
    stack<int> l5;
    stack<int> l6;

    int n,p;
    cin>>n>>p;

    int result = 0;

    for(int test=0; test<n; test++){
        int a,b;
        cin>>a>>b;

        if(a==1){
            while(true){
                if(l1.empty()){
                    l1.push(b);
                    result+=1;
                    break;
                }else{
                    if(l1.top()<b){
                        l1.push(b);
                        result+=1;
                        break;
                    }else if(l1.top()==b){
                        break;
                    }else{
                        l1.pop();
                        result+=1;
                    }
                }
            }
        }else if(a==2){
            while(true){
                if(l2.empty()){
                    l2.push(b);
                    result+=1;
                    break;
                }else{
                    if(l2.top()<b){
                        l2.push(b);
                        result+=1;
                        break;
                    }else if(l2.top()==b){
                        break;
                    }else{
                        l2.pop();
                        result+=1;
                    }
                }
            }
        }else if(a==3){
            while(true){
                if(l3.empty()){
                    l3.push(b);
                    result+=1;
                    break;
                }else{
                    if(l3.top()<b){
                        l3.push(b);
                        result+=1;
                        break;
                    }else if(l3.top()==b){
                        break;
                    }else{
                        l3.pop();
                        result+=1;
                    }
                }
            }
        }else if(a==4){
            while(true){
                if(l4.empty()){
                    l4.push(b);
                    result+=1;
                    break;
                }else{
                    if(l4.top()<b){
                        l4.push(b);
                        result+=1;
                        break;
                    }else if(l4.top()==b){
                        break;
                    }else{
                        l4.pop();
                        result+=1;
                    }
                }
            }
        }else if(a==5){
            while(true){
                if(l5.empty()){
                    l5.push(b);
                    result+=1;
                    break;
                }else{
                    if(l5.top()<b){
                        l5.push(b);
                        result+=1;
                        break;
                    }else if(l5.top()==b){
                        break;
                    }else{
                        l5.pop();
                        result+=1;
                    }
                }
            }
        }else{
            while(true){
                if(l6.empty()){
                    l6.push(b);
                    result+=1;
                    break;
                }else{
                    if(l6.top()<b){
                        l6.push(b);
                        result+=1;
                        break;
                    }else if(l6.top()==b){
                        break;
                    }else{
                        l6.pop();
                        result+=1;
                    }
                }
            }
        }
    }

    cout<<result<<endl;

    return 0;
}