#include <stdio.h>

int max(int x,int y){
    if (x>y){
        return x;
    } else {
        return y;
    }
}
int main(void){
    int x,y,larger;

    printf("Enter two interger: ");
    scanf("%d %d",&x,&y);

    larger = max(x,y);
    //receive interger from the function above 
    printf(" The larger the value is %d . \n ",larger);
    return 0;

}