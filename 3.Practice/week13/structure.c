#include <stdio.h>
#include <string.h>

struct student{
    int number;
    char name[100];
    double grade;

};

int main(void){
    struct student s;

    s.number = 200000;
    s.number = 20230001;
    strcpy (s.name, " Hong Gil-dong " );
    s.grade = 4.3 ;
    printf ( "Student number : %d\n" , s.number );
    printf ( "Name : %s\n" , s.name);
    printf ( "Grade : % .2f \n" , s.grade ) ;
    return 0;
}