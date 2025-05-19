#include <stdio.h>

//Execute function after being called by x,y
int get_interger(){
    int value;
    printf("Enter an interger: ");
    scanf("%d",&value);
    //return the Value to the parameter of the function
    return value;

}
// Take the parameter from the Function and execute sum code block
int add(int x,int y){
    return x + y;
}

int main(void){
    // Called interger for user input
    int x = get_interger();
    int y = get_interger();
    
    int sum = add(x,y);
    printf("The sum of two numbers is %d .\n",sum );
    return 0;
}

