#include <stdio.h>
void swap(int *x,int *y);




int main(void){
    int a =100,b=200;
    printf("a=%db=%d\n",a,b);
    
    swap(&a,&b);
    
    printf("a=%db=%d\n",a,b);
    return 0;
}
void swap(int *px,int *py){
        int tmp;
        tmp = *px;
        *px = *py;
        *py = tmp;
}