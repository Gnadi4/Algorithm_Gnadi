#include <iostream>
#include <list>
using namespace std;

int main(){

    int testcase;
    cin>>testcase;
    
    for(int test=0; test<testcase; test++){
        int n,k;
        cin>>n>>k;

        list<int> l1;

        for(int i=0; i<n; i++){
            l1.push_back(i+1);
        }

        list<int>::iterator iter;
        iter = l1.begin();

        while(true){
            if(l1.size()==2)break;
            iter = l1.erase(iter);

            if(iter==l1.end()){
                iter = l1.begin();
            }

            for(int i=0; i<k-1; i++){

                iter++;

                if(iter==l1.end()){
                    iter = l1.begin();
                }
            }
        }
        
        cout<<l1.front()<<' '<<l1.back()<<endl;
    }

    return 0;
}