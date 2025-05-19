#include <stdio.h>
#define SIZE 10
int main(void){
    int prices[SIZE] = {28,81,60,83,67,10,66,97,37,94};
    int i,minimum;

    minimum = prices[0];
    for(i=1;i<SIZE;i++){
        if(prices[i]<minimum){
            minimum = prices[i];
        }
    }
    printf("The minimum value is %d .\n",minimum);
    return 0;
}