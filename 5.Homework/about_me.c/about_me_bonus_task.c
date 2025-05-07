#include <stdio.h>
#include <ctype.h>
int main(void) {
    // Introduction message
    printf("[Magrathea] ❤❤ Project Member Introduction ❤❤\n");

    // Define the details of each member and print them
    const char* Name[] = {"Arthur Dent", "Kim Youngjin", "Im Woncheol", "Yoo Goeun", "Seo Hyekyung"};
    const char* Gender[] = {"Male", "Male", "Male", "Female", "Female"};
    const char* Major[] = {"Mechanical Engineering", "Computer Engineering", "Electronic Engineering", 
                           "Management Information Systems", "Political Science & International Relations"};
    const char* Experience[] = {"15 Years", "2 years", "1 year", "1 year", "0 years","0 years"};
    const char* Role[] = {"Architect", "Developer", "DBA", "Cloud Engineer", "Developer"};
    const char* Skills[] = {
        "C/C++, Java, Spring, Python, Machine Learning/Deep Learning",
        "C#, Python, JavaScript, React, Kotlin, Recently",
        "Java, PHP, MongoDB, MS SQL, MySQL",
        "Java, PowerShell, Azure, AWS, GCP",
        "Python, Swift, Kotlin, Node.js, Figma"
    };
    const char* Introduction[] = {
        "I built my career working on various projects in SNS, fintech, HR, and media in Silicon Valley. Through successes and failures, I have gained insights I want to share with you.",
        "I found immense passion for software development through a personal asset management project using the MAUI framework. Solving real-world problems with my code is incredible! Successfully developing Magrathea has now become one of my bucket list goals.",
        "I believe that applications are ultimately about how they handle data. While studying Big Data courses in university, I developed a deep interest in data platforms. I think the success of this project depends on data. Just thinking about the data we’ll manage in Magrathea already excites me!",
        "I worked on a project with Kim Youngjin, where I was responsible for implementing cloud architecture. During my school years, I became fascinated with cloud computing, particularly Microsoft Azure. As I delved deeper, I found that understanding other public cloud platforms became much easier. I am determined to complete Magrathea's cloud architecture with my own hands!",
        "While I have worked on many projects as academic assignments, this is my first real-world project where a company's success is at stake. I am both excited and nervous about whether I can perform well. When I first heard about the Magrathea project, something inside me told me that this was a project worth dedicating myself to. Having already heard of Arthur’s reputation through LinkedIn, I feel honored to be part of this journey."
    };
    char binaryStrings[5][33];

    int size = sizeof(Experience) / sizeof(Experience[0]);
    int years;
    for (int i = 0; i < size ; i++){
        const char* exp = Experience[i];
        years = 0;
        for (int j=0 ; exp[j] != '\0' ; j++){
            if (isdigit(exp[j])){
                years = years * 10 + (exp[j] - '0');
            }else{
                break;
            }
        }
        int temp = years;
        int index=31;
        while (index >= 0) {
            if (temp % 2 == 0)
                binaryStrings[i][index] = '0';
            else
                binaryStrings[i][index] = '1';
            temp /= 2;
            index--;
        }
        binaryStrings[i][32]='\0';
        
    } 
    // Loop through each member's details and print them
    for (int i = 0; i < 5; i++) {
        printf("-------------------------------------------------\n");
        printf("Name         | %s\t\t", Name[i]);
        printf("Gender       | %s\n", Gender[i]);
        printf("Major        | %s\t", Major[i]);
        printf("Experience   | %s\n", Experience[i]);
        printf("Role         | %s\t\t", Role[i]);
        printf("Skills       | %s\n", Skills[i]);
        printf("Introduction | ");

        // Loop through the Introduction string and handle period (.) for line breaks
        for (int j = 0; Introduction[i][j] != '\0'; j++) {
            char c = Introduction[i][j];  // Character from the Introduction string

            if (c == '.') {
                printf(".");
                printf("\n");  // Print newline after period
                for (int k = 0; k < 14; k++)  // Indent the next line
                    printf(" ");
            } else {
                printf("%c", c);  // Print the character
            }

        }
        printf("\nExperience in 32-bit binary: %s\n", binaryStrings[i]);
    }
    //pause to keep terminal open
    printf("Press Enter to exit...\n");
    getchar();  // Wait for user input
    return 0;
}
// [Magrathea] ❤❤ Project Member Introduction ❤❤
// =====================================================================
// Name         | Arthur Dent                Gender     | Male
// Major        | Mechanical Engineering     Experience | 15 years
// Role         | Architect                  Skills | C/C++, Java, Spring, Python, Machine Learning/Deep Learning
// ---------------------------------------------------------------------
// Introduction | I built my career working on various projects in SNS, fintech, HR, and media in Silicon Valley. 
//                Through successes and failures, I have gained insights I want to share with you.
// =====================================================================
// Name         | Kim Youngjin               Gender       | Male
// ......(continued)........