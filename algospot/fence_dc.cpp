#include <iostream>
using namespace std;

int fence[20000];

int fence_max(int start, int end){
    
    if(end-start==1)return fence[start];
    
    int divide_point = (start+end)/2;

    int left_value = fence_max(start,divide_point);

    int right_value = fence_max(divide_point,end);

    int ret_val = max(left_value,right_value);

    int mid_val = min(fence[divide_point-1],fence[divide_point]);

    int check_val = 0;

    int left_point = divide_point-1;
    int right_point = divide_point;
    int gap = 0;
    while(left_point>=start-1||right_point<=end){
        if(left_point<start&&right_point<=end-1){
            if(gap<=fence[right_point]){
                check_val+=1;
                right_point+=1;
            }else{
                check_val+=1;
                gap = fence[right_point];
                right_point+=1;
            }
        }else if(right_point>end-1&&left_point>=start){
            if(gap<=fence[left_point]){
                check_val+=1;
                left_point-=1;
            }else{
                check_val+=1;
                gap = fence[left_point];
                left_point-=1;
            }
        }else{
            if(fence[left_point]==fence[right_point]){
                check_val+=2;
                gap = fence[left_point];
                left_point-=1;
                right_point+=1;
            }else if(fence[left_point]<fence[right_point]){
                check_val+=1;
                right_point+=1;
                gap = fence[left_point];
            }else{
                check_val+=1;
                left_point-=1;
                gap = fence[right_point];
            }
        }
        // cout<<gap<<check_val<<endl;
        ret_val = max(ret_val, gap*check_val);
    }

    return ret_val;

}

int main(){

    int N;
    cin>>N;

    for (int testCase = 0; testCase<N; testCase++){
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>fence[i];
        }

        int result = fence_max(0,n);
        cout<<result<<endl;
    }

    return 0;
}