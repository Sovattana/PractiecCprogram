#include <stdio.h>
struct student
{
    /* data */
    int number;
    char name[20];
    double grade;
};
int main(void){
    struct student s = {1,"Hong Gil-dong",4.3};
    struct student *p;

    p = &s;

    printf("Student number=%d Name=%s Grade=%f\n",s.number,s.name,s.grade);
    printf("Student number=%d Name=%s Grade=%f\n",(*p).number,(*p).name,(*p).grade);
    printf("Student number=%d Name=%s Grade=%f\n",p->number,p->name,p->grade);
    
    
}