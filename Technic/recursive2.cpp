#include <iostream>
#include <vector>
using namespace std;

void mk(vector <int> temp, vector <int> cont){

    if(cont.size()==4){
        for(int i=0; i<cont.size(); i++)cout<<cont[i]<<" ";
        cout<<endl;
        return;
    }else{
        vector <int>::iterator iter;
        for(iter=temp.begin(); iter!=temp.end(); iter++){
            cont.push_back(*iter);
            temp.erase(iter);
            iter--;
            mk(temp,cont);
            cont.pop_back();
        }
    }
    return;
}

int main(){

    vector <int> temp;
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);
    temp.push_back(4);
    temp.push_back(5);
    temp.push_back(6);
    temp.push_back(7);

    vector <int> cont;

    mk(temp,cont);

    return 0;
}