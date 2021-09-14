#include <stdio.h>

typedef float num[2];

int main(){

    struct{float x,y;}pos;
    pos.x = 1;
    pos.y = 0;

    printf("%f %f\n",pos.x,pos.y);

    return 0;
}