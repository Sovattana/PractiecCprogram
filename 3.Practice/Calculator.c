#include <stdio.h>

int main(void){
    char op;
    int x,y,result;

    printf("Enter a fomula (e.g 2 + 5)>> ");
    scanf("%d %c %d",&x,&op,&y);

    if(op == '+')
        result = x + y;
    else if (op == '-')
        result = x - y;
    else if (op == '*')
        result = x * y;
    else if (op == '/')
        result = x / y;
    else if (op == '%')
        result = x % y;
    else
        printf("Unsupported Operator .");

    printf("%d %c %d = %d\n",x,op,y,result);
    return 0;
}