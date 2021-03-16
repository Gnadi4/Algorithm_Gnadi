#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){

    string c,d;
    vector <int> result;

    cin>>c>>d;

    int a[c.size()];
    int b[d.size()];

    //reverse integer-str
    for(int i=0; i<c.size(); i++){
        a[i]=c[c.size()-i-1]-'0';        
    }
    for(int i=0; i<d.size(); i++){
        b[i]=d[d.size()-i-1]-'0';
    }

    if(sizeof(a)/sizeof(int)>=sizeof(b)/sizeof(int)){
        int up = 0;
        for(int i=0; i<(sizeof(a)/sizeof(int)); i++){
            if(i<sizeof(b)/sizeof(int)){
                int tmp = (a[i]+b[i]+up)%10;
                if(a[i]+b[i]+up>=10){
                    up = 1;
                }else{
                    up = 0;
                }

                result.push_back(tmp);
            }else{
                result.push_back((a[i]+up)%10);
                if(a[i]+up>=10){
                    up = 1;
                }else{
                    up = 0;
                }
            }
        }
        if(up == 1){
            result.push_back(1);
        }
    }else{
        int up = 0;
        for(int i=0; i<(sizeof(b)/sizeof(int)); i++){
            if(i<sizeof(a)/sizeof(int)){
                int tmp = (a[i]+b[i]+up)%10;
                if(a[i]+b[i]+up>=10){
                    up = 1;
                }else{
                    up = 0;
                }

                result.push_back(tmp);
            }else{
                result.push_back((b[i]+up)%10);
                if(b[i]+up>=10){
                    up = 1;
                }else{
                    up = 0;
                }
            }
        }
        if(up == 1){
            result.push_back(1);
        }
    }

    //vector <int>::iterator iter;
    
    // for(int i=0; i<sizeof(a)/sizeof(int); i++){
    //     cout<<a[i]<<' ';
    // }cout<<endl;
    
    // for(int i=0; i<sizeof(b)/sizeof(int); i++){
    //     cout<<b[i]<<' ';
    // }cout<<endl;
    //cout<<a<<" "<<b<<endl;
    //cout<<result.size()<<endl;
    for(int i=result.size()-1; i>=0; i--){
        cout<<result[i];
    }cout<<endl;

    return 0;
}