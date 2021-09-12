#include <stdio.h>
#include <string.h>

int main(){

    char s[100] = "hello";
    int len = strlen(s);

    printf("%d\n", sizeof(s)/sizeof(char));    
    printf("%d\n",len);
}