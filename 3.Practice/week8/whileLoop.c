#include <stdio.h>

int main (void)
{
    int i, n, sum ;
    printf("Enter interger : ");
    scanf("%d",&n);
        i = 1 ;
        sum = 0 ;
        while (i<=n)
        {
            sum += i;
            i++;
        }
        printf("The sum from 1 to %d is %d \n",n,sum);  
        return 0;
}