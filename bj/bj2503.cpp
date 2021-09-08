#include <iostream>
using namespace std;

int main(){

    //숫자 야구
    //소거법으로 접근 해보자
    //서로 다른 숫자
    int arr[1000]={0,};
    for(int i =0; i<1000; i++){
        if(i<=111)arr[i]=1;
        else{
            int a,b,c;
            a = i/100;
            b = (i%100)/10;
            c = (i%10);

            if(a==b||a==c||b==c)arr[i]=1;
            if(a==0||b==0||c==0)arr[i]=1;
        }
    }

    int N;
    cin>>N;
    for(int testcase=0; testcase<N; testcase++){
        int num,s,ba;
        cin>>num>>s>>ba;

        int a,b,c;
        a = num/100;
        b = (num%100)/10;
        c = (num%10);
        
        if(s==3){
            cout<<1<<endl;
            return 0;
        }else if(s==2){
            for(int i=112; i<1000; i++){
                int f,s,t;
                f = i/100;
                s = (i%100)/10;
                t = (i%10);
                if((a==f&&b==s&&c!=t)||(a==f&&b!=s&&c==t)||(a!=f&&b==s&&c==t)){

                }else{
                    arr[i]=1;
                }
            }
        }else if(s==1){
            if(ba==2){
                for(int i=112; i<1000; i++){
                    int f,s,t;
                    f = i/100;
                    s = (i%100)/10;
                    t = (i%10);
                    if((a==f&&b==t&&c==s)||(a==t&&b==s&&c==f)||(a==s&&b==f&&c==t)){

                    }else{
                        arr[i]=1;
                    }
                }
            }else if(ba==1){
                for(int i=112; i<1000; i++){
                    int f,s,t;
                    f = i/100;
                    s = (i%100)/10;
                    t = (i%10);
                    if((a==f&&b==t&&c!=s)||(a==f&&b!=t&&c==s)||(a!=t&&b==s&&c==f)||(a==t&&b==s&&c!=f)||(a==s&&b!=f&&c==t)||(a!=s&&b==f&&c==t)){

                    }else{
                        arr[i]=1;
                    }
                }
            }else{
                for(int i=112; i<1000; i++){
                    int f,s,t;
                    f = i/100;
                    s = (i%100)/10;
                    t = (i%10);
                    if(((a==f&&b!=s&&c!=t)&&(a==f&&b!=t&&c!=s))||((a!=t&&b==s&&c!=f)&&(a!=f&&b==s&&c!=t))||((a!=f&&b!=s&&c==t)&&(a!=s&&b!=f&&c==t))){

                    }else{
                        arr[i]=1;
                    }
                }
            }
        }else if(s==0){
            if(ba==3){
                for(int i=112; i<1000; i++){
                    int f,s,t;
                    f = i/100;
                    s = (i%100)/10;
                    t = (i%10);
                    if((a==s&&b==f&&c==s)||(a==t&&b==t&&c==f)){

                    }else{
                        arr[i]=1;
                    }
                }
            }else if(ba==2){
                for(int i=112; i<1000; i++){
                    int f,s,t;
                    f = i/100;
                    s = (i%100)/10;
                    t = (i%10);
                    if(a==s){
                        if(b==f){
                            if(c!=t){

                            }else{
                                arr[i]=1;
                            }
                        }else if(b==t){
                            if(c!=f){

                            }else{
                                arr[i]=1;
                            }
                        }else if(c==f){
                            if(b!=t){

                            }else{
                                arr[i]=1;
                            }
                        }else{
                            arr[i]=1;
                        }
                    }else if(a==t){
                        if(b==f){
                            if(c!=s){

                            }else{
                                arr[i]=1;
                            }
                        }else if(c==f){
                            if(b!=s){

                            }else{
                                arr[i]=1;
                            }
                        }else if(c==s){
                            if(b!=f){

                            }else{
                                arr[i]=1;
                            }
                        }else{
                            arr[i]=1;
                        }
                    }else if()
                }
            }else if(ba==1){

            }
        }
    }
    
    int count = 0;

    for(int i=112; i<1000; i++){
        if(arr[i]==0){
            cout<<i<<endl;
            count+=1;
        }
    }

    cout<<count<<endl;
    
    return 0;
}