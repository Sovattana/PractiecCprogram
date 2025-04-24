#include <stdio.h>

int main(void){
    int i = 0;
    do{
        printf("1---new\n");
        printf("2---Open File\n");
        printf("3---Open File\n");
        printf("Choose File\n");
        scanf("%d",&i);
    }
    while (i<1||i>3);

    printf("Selected Menu = %d\n",i);
    return 0;

}