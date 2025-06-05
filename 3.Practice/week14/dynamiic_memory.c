#include <stdio.h>
#include <stdlib.h>
int main(void){
    int *list;
    list = (int*) malloc (3 * sizeof (int));
    if(list == NULL){
        // The return Value is NULL cognition check
        printf("Dynamic memory allocatioon error \n");
        exit(1);
    }
    list[0] = 10;
    list[1] = 20;
    list[2] = 30;
    printf("Number of students : 3\n");
    for(int i= 1;i <= 3;i++){
        
        printf("Student #%d Grade : %d\n",i,list[i-1]);

    }
    free(list);
    return 0;
}