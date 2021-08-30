#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int check_num[10000000] = {0};

bool ck(string cknum){
    bool tmp = true;
    int a = stoi(cknum);
    if(a<=1)tmp = false;
    for(int i=2; i<=int(sqrt(a)); i++){
        if(a%i==0)tmp = false;
    }

    return tmp;
}

void check_prime(string num, string num_arr, int l, int stopnum){
    if(l==stopnum)return;
    // cout<<num_arr<<endl;
    if(ck(num_arr)){
        // cout<<num_arr<<endl;
        check_num[stoi(num_arr)] = 1;
    }
    for(int i=0; i<num.size(); i++){
        string tmp = "";
        for(int j=0; j<num.size(); j++){
            if(j!=i)tmp+=num[j];
        }
        // cout<<tmp<<endl;
        check_prime(tmp, num[i]+num_arr, l+1, stopnum);
    }

    return;
}

int solution(string numbers) {
    int answer = 0;
    
    // cout<<numbers.size()<<endl;

    for(int i=0; i<numbers.size(); i++){
        string tmp = "";
        string ftmp = "";
        for(int j=0; j<numbers.size(); j++){
            if(j!=i)tmp+=numbers[j];
        }
        // cout<<tmp<<endl;
        ftmp = numbers[i];
        check_prime(tmp, ftmp, 0, numbers.size());
    }
    
    for(int i=0; i<10000000; i++)if(check_num[i]==1)answer+=1;
    // answer = check_num;

    return answer;
}

int main(){

    cout<<solution("1234567")<<endl;

    return 0;
}