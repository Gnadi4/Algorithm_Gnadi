#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool second_sort(const vector<int>& v1, const vector<int>& v2){
    return v1[1] < v2[1];
}

int main(){

    int n;
    cin>>n;

    vector< vector<int> > arr;
    vector<int> tmp(2,0);

    for(int i=0; i<n; i++){
        int s,e;
        cin>>s>>e;

        tmp[0] = s;
        tmp[1] = e;

        arr.push_back(tmp);
    }

    sort(arr.begin(),arr.end());

    sort(arr.begin(),arr.end(),second_sort);

    vector<int> result;

    result.push_back(arr[0][1]);

    for(int i=1; i<n; i++){
        int k = -1;
        int point = -1;
        for(int j=0; j<result.size(); j++){
            if(k==-1){
                if(arr[i][0]-result[j]>=0){
                    k = arr[i][0]-result[j];
                    point = j;
                }
            }else{
                if(arr[i][0]-result[j]>=0){
                    if(k>arr[i][0]-result[j]){
                        k = arr[i][0]-result[j];
                        point = j;
                    }
                }
            }
        }
        if(k==-1)result.push_back(arr[i][1]);
        else{result[point]=arr[i][1];}
    }

    cout<<result.size()<<endl;
    
    return 0;
}