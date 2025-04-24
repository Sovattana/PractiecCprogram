#include <stdio.h>

int main (void){

    int i,j;

    for(j=1;j<=5;j++)
    {
        for(i=0;i<j;i++)
        {
            printf("*");
        } 
        printf("\n");
    }

}