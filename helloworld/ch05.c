#include <stdio.h>
#include <string.h>

int main(){

    // char s[100] = "hello";
    // int len = strlen(s);

    // printf("%d\n", sizeof(s)/sizeof(char));    
    // printf("%d\n",len);

    // char s1[] = "sample";
    // char s2[] = "simple";

    // if(strcmp(s1,s2)<0){
    //     printf("%s는 사전순으로 %s 보다 빠름",s1,s2);
    // }

    // int a = 10;
    // int *ptr_a;
    // ptr_a = &a;

    // printf("%d\n", a);
    // printf("%d\n",&a);

    // int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    // int (*ptr)[10] = &arr;

    // for(int i=0; i<10; i++){
    //     printf("%d\n",(*ptr)[i]);
    // }

    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    int (*ptr)[4] = arr;

    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++)printf("%d ",ptr[i][j]);
        printf("\n");
    }

}