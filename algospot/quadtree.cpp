#include <iostream>
#include <string.h>
using namespace std;

string result = "";

//여기서 3 4 1 2 로 바꿔야 함
string cal(string s,int start, int end){
    string c1,c2,c3,c4;
    int check_sum = 0;
    for(int i = start; i<end; i++){
        if(s[i]=='x'){
            check_sum = 1;
            break;
        }
    }

    if(check_sum==0){
        return s;
    }

    int count_num[4];
    int tmp_count = 0;
    int target_count = 1;
    int j = 0;
    for(int i = start+1; i<end; i++){
        if(s[i]=='x'){
            target_count+=4;
            tmp_count+=1;
        }else{
            tmp_count+=1;
        }
        if(tmp_count==target_count){
            count_num[j] = i;
            tmp_count=0;
            target_count=1;
            j+=1;
        }
    }

    // cout<<count_num[0]<<count_num[1]<<count_num[2]<<count_num[3]<<endl;

    for(int i=start+1; i<=count_num[0]; i++)c1+=s[i];
    for(int i=count_num[0]+1; i<=count_num[1]; i++)c2+=s[i];
    for(int i=count_num[1]+1; i<=count_num[2]; i++)c3+=s[i];
    for(int i=count_num[2]+1; i<end; i++)c4+=s[i];

    // cout<<c1<<' '<<c2<<' '<<c3<<' '<<c4<<endl;

    c1 = cal(c1,0,c1.size());
    c2 = cal(c2,0,c2.size());
    c3 = cal(c3,0,c3.size());
    c4 = cal(c4,0,c4.size());

    return 'x'+c3+c4+c1+c2;
}

int main(){

    int N;
    cin>>N;
    
    for(int testcase = 0; testcase<N; testcase++){
        string s;
        cin>>s;

        if(s.size()==1){
            cout<<s<<endl;
        }else{
            result = cal(s,0,s.size());
            cout<<result<<endl;
        }
    }

    return 0;
}