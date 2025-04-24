#include <stdio.h>

int main (void){
    int i,n,sum;

    printf("Enter interger: ");
    scanf("%d",&n);

    sum = 0;

    for (i=0;i <= n;i++){
        sum += i;
    }
    
    printf("sum of interger from 1 to 10 = %d\n",sum);
};