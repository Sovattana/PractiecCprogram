#include <stdio.h>
#define SIZE 3
struct student
{
    /* data */
    int number;
    char name[20];
    double grade;
};
int main(void){
    struct student List[SIZE];
    int i;
    for (i=0;i<SIZE;i++){
        printf("Student number Enter : ");
        scanf("%d",&List[i].number);
        printf("name Enter : ");
        scanf(" %[^\n]s",List[i].name);
        printf("Credit Enter (Error): ");
        scanf("%lf",&List[i].grade);

    }
    for(i=0;i<SIZE;i++){
        printf("Student number : %d, Name : %s, Grade : %f\n",
        List[i].number,List[i].name,List[i].grade);
    };
    return 0;
    
}
