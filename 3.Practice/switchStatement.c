#include <stdio.h>

int main(void){
    char op;
    int x,y,result;

    printf("Enter a fomula (e.g 2 + 5)>> ");
    scanf("%d %c %d",&x,&op,&y);

    switch(op){
        case '+':
            result = x + y; break ; 
        case '-':
            result = x - y; break ; 
        case '*':
            result = x * y; break ; 
        case '/':
            result = x / y; break ; 
        case '%':
            result = x + y; break ; 
        default :
            printf("Unsupported Operator");

    }
    printf("%d %c %d = %d \n",x,op,y,result);
    return 0;
}