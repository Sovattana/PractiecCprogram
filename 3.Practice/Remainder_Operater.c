#include <stdio.h>
#define SEC_PER_MINUTE 60

int main(void){
    int input,minute,second;
    printf("Enter seconds: ");
    scanf("%d",&input);

    minute = input / SEC_PER_MINUTE;
    second = input % SEC_PER_MINUTE;

    printf("%d seconds is %d minutes\nand %d seconds. ", input,minute,second);
    return(0);
}