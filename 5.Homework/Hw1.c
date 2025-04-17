#include <stdio.h>

void printMember(
    const char* Name, const char* Gender, const char* Major, const char* Experience, 
    const char* Role, const char* Skills, const char* Introduction
){
    printf("-------------------------------------------------\n");
    printf("Name         | %s\n",Name);
    printf("Gender       | %s\n",Gender);
    printf("Major        | %s\n",Major);
    printf("Experience   | %s\n",Experience);
    printf("Role         | %s\n",Role);
    printf("Skills       | %s\n",Skills);
    printf("Introduction | %s\n",Introduction);
    printf("-------------------------------------------------\n");
}
int main(void){
    printf("[Magrathea] ❤❤ Project Member Introduction ❤❤\n");

    printMember(
        "Arthur Dent","Male", "Mechanical Engineering","15 Years","Architect",
        "C/C++, Java, Spring, Python, Machine Learning/Deep Learning",
        "I built my career working on various projects in SNS, fintech, HR, and media in Silicon Valley.\n Through successes and failures, I have gained insights I want to share with you."
    );


}






// [Magrathea] ❤❤ Project Member Introduction ❤❤
// -------------------------------------------------
// Name         | Arthur Dent  
// Gender       | Male  
// Major        | Mechanical Engineering  
// Experience   | 15 years  
// Role         | Architect  
// Skills       | C/C++, Java, Spring, Python, Machine Learning/Deep Learning  
// Introduction | I built my career working on various projects in SNS, fintech, HR, and media in Silicon Valley.  
//               Through successes and failures, I have gained insights I want to share with you.  
// --------------------------------------------------
// Name         | Kim Youngjin  
// Gender       | Male
// ......(continued)........