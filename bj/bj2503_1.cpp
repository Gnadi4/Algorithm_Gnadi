#include <iostream>
#include <vector>
using namespace std;

int main(){

    //like elimination

    int tmp[1000]={0,};
    for(int i =0; i<1000; i++){
        if(i<=111)tmp[i]=1;
        else{
            int a,b,c;
            a = i/100;
            b = (i%100)/10;
            c = (i%10);
            if(a==b||a==c||b==c)tmp[i]=1;
            if(a==0||b==0||c==0)tmp[i]=1;
        }
    }

    vector<int> arr;

    for(int i=0; i<1000; i++){
        //if(tmp[i]==0)cout<<i<<endl;
        if(tmp[i]==0)arr.push_back(i);
    }

    //cout<<arr.size()<<endl;

    int N;
    cin>>N;

    int check_arr[510]={0,};

    for(int test=0; test<N; test++){
        int num,st,ba;
        cin>>num>>st>>ba;

        int a,b,c;
        a = num/100;
        b = (num%100)/10;
        c = (num%10);

        for(int i=0; i<arr.size(); i++){
            int aa,bb,cc;
            aa = arr[i]/100;
            bb = (arr[i]%100)/10;
            cc = arr[i]%10;

            int st_tmp = 0;
            int ba_tmp = 0;
            if(st==0&&ba==0){
                if(a!=aa&&a!=bb&&a!=cc&&b!=aa&&b!=bb&&b!=cc&&c!=aa&&c!=bb&&c!=cc){
                    check_arr[i]+=1;
                }
            }else{
                if(a==aa)st_tmp+=1;
                if(a==bb)ba_tmp+=1;
                if(a==cc)ba_tmp+=1;
                if(b==bb)st_tmp+=1;
                if(b==aa)ba_tmp+=1;
                if(b==cc)ba_tmp+=1;
                if(c==cc)st_tmp+=1;
                if(c==aa)ba_tmp+=1;
                if(c==bb)ba_tmp+=1;

                if(st==st_tmp&&ba==ba_tmp){
                    //cout<<arr[i]<<endl;
                    check_arr[i]+=1;
                }
            }
        }
    }

    int result = 0;

    for(int i=0; i<510; i++){
        //if(check_arr[i]==N)cout<<arr[i]<<endl;
        if(check_arr[i]==N)result+=1;
    }

    cout<<result<<endl;

    return 0;
}