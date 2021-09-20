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
                int aa,bb,cc;
                aa = i/100;
                bb = (i%100)/10;
                cc = (i%10);
                if((a==aa&&b==bb&&c!=cc)||(a==aa&&b!=bb&&c==cc)||(a!=aa&&b==bb&&c==cc)){

                }else{
                    arr[i]=1;
                }
            }
        }else if(s==1){
            if(ba==2){
                for(int i=112; i<1000; i++){
                    int aa,bb,cc;
                    aa = i/100;
                    bb = (i%100)/10;
                    cc = (i%10);
                    if((a==aa&&b==cc&&c==bb)||(a==cc&&b==bb&&c==aa)||(a==bb&&b==aa&&c==cc)){

                    }else{
                        arr[i]=1;
                    }
                }
            }else if(ba==1){
                for(int i=112; i<1000; i++){
                    int aa,bb,cc;
                    aa = i/100;
                    bb = (i%100)/10;
                    cc = (i%10);
                    if((a==aa&&b==cc&&c!=bb)||(a==aa&&b!=cc&&c==bb)||(a!=cc&&b==bb&&c==aa)||(a==cc&&b==bb&&c!=aa)||(a==bb&&b!=aa&&c==cc)||(a!=bb&&b==aa&&c==cc)){

                    }else{
                        arr[i]=1;
                    }
                }
            }else{
                for(int i=112; i<1000; i++){
                    int aa,bb,cc;
                    aa = i/100;
                    bb = (i%100)/10;
                    cc = (i%10);
                    if(((a==aa&&b!=bb&&c!=cc&&b!=cc&&c!=bb))||((a!=cc&&b==bb&&c!=aa&&a!=aa&&c!=cc))||((a!=aa&&b!=bb&&a!=bb&&b!=aa&&c==cc))){

                    }else{
                        arr[i]=1;
                    }
                }
            }
        }else if(s==0){
            if(ba==3){
                for(int i=112; i<1000; i++){
                    int aa,bb,cc;
                    aa = i/100;
                    bb = (i%100)/10;
                    cc = (i%10);
                    if((a==cc&&b==aa&&c==bb)||(a==bb&&b==cc&&c==aa)){

                    }else{
                        arr[i]=1;
                    }
                }
            }else if(ba==2){
                for(int i=112; i<1000; i++){
                    int aa,bb,cc;
                    aa = i/100;
                    bb = (i%100)/10;
                    cc = (i%10);
                    if(a==bb){
                        if(b==aa){
                            if(c!=cc){

                            }else{
                                arr[i]=1;
                            }
                        }else if(b==cc){
                            if(c!=aa){

                            }else{
                                arr[i]=1;
                            }
                        }else if(c==aa){
                            if(b!=cc){

                            }else{
                                arr[i]=1;
                            }
                        }else{
                            arr[i]=1;
                        }
                    }else if(a==cc){
                        if(b==aa){
                            if(c!=bb){

                            }else{
                                arr[i]=1;
                            }
                        }else if(c==aa){
                            if(b!=bb){

                            }else{
                                arr[i]=1;
                            }
                        }else if(c==bb){
                            if(b!=aa){

                            }else{
                                arr[i]=1;
                            }
                        }else{
                            arr[i]=1;
                        }
                    }else if(b==aa){
                        if(a==bb){
                            if(c!=cc){

                            }else{
                                arr[i]=1;
                            }
                        }else if(a==cc){
                            if(c!=bb){

                            }else{
                                arr[i]=1;
                            }
                        }else if(c==bb){
                            if(a!=cc){

                            }else{
                                arr[i]=1;
                            }
                        }
                    }else if(b==cc){
                        if(a==bb){
                            if(c!=aa){

                            }else{
                                arr[i]=1;
                            }
                        }else if(c==aa){
                            if(a!=bb){

                            }else{
                                arr[i]=1;
                            }
                        }else if(c==bb){
                            if(a!=aa){

                            }else{
                                arr[i]=1;
                            }
                        }
                    }else if(c==aa){
                        if(b==cc){
                            if(a!=bb){

                            }else{
                                arr[i]=1;
                            }
                        }else if(a==bb){
                            if(b!=cc){

                            }else{
                                arr[i]=1;
                            }
                        }else if(a==cc){
                            if(b!=bb){

                            }else{
                                arr[i]=1;
                            }
                        }
                    }else if(c==bb){
                        if(b==cc){
                            if(a!=aa){

                            }else{
                                arr[i]=1;
                            }
                        }else if(b==aa){
                            if(a!=cc){

                            }else{
                                arr[i]=1;
                            }
                        }else if(a==cc){
                            if(b!=aa){

                            }else{
                                arr[i]=1;
                            }
                        }
                    }
                }
            }else if(ba==1){
                for(int i=112; i<1000; i++){
                    int aa,bb,cc;
                    aa = i/100;
                    bb = (i%100)/10;
                    cc = (i%10);

                    if((a==bb&&b!=aa&&b!=cc&&c!=aa&&c!=cc)||(a==cc&&b!=aa&&b!=bb&&c!=aa&&c!=bb)||(b==aa&&a!=bb&&a!=cc&&c!=bb&&c!=cc)||(b==cc&&a!=aa&&a!=bb&&c!=aa&&c!=bb)||(c==aa&&a!=bb&&a!=cc&&b!=bb&&b!=cc)||(c==bb&&a!=aa&&a!=cc&&b!=aa&&b!=cc)){

                    }else{
                        arr[i]=1;
                    }

                }
            }else if(ba==0){
                for(int i=112; i<1000; i++){
                    int aa,bb,cc;
                    aa = i/100;
                    bb = (i%100)/10;
                    cc = (i%10);

                    if((a!=aa&&a!=bb&&a!=cc&&b!=aa&&b!=bb&&b!=cc&&c!=aa&&c!=bb&&c!=cc)){

                    }else{
                        arr[i]=1;
                    }

                }
            }
        }
    }
    
    int count = 0;

    for(int i=112; i<1000; i++){
        if(arr[i]==0){
            // cout<<i<<endl;
            count+=1;
        }
    }

    cout<<count<<endl;
    
    return 0;
}