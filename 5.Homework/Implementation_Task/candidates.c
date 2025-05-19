#include <stdio.h>
#include <stdlib.h>
int main(void){
    char candidate01[13][50];
    char candidate02[13][50];
    char candidate03[13][50];
    char candidate04[13][50];
    char candidate05[13][50];
    char candidate06[13][50];

    char member_info[13][30] = {
        "Name",
        "Year of Birth",
        "Month of Birth",
        "Day of Birth",
        "Gender",
        "Email",
        "Nationality",
        "BMI",
        "Primary Skill",
        "Secondary Skill",
        "Korean Level",
        "MBTI",
        "Itroduction"
    };
    int candidates = 0;
    printf("####################################\n\tAudition Candidate Data Entry\n####################################\n");
    while(candidates < 1){
        if (candidates == 0) strcpy(candidate01[candidates], member_info[candidates]);
            else if (candidates == 1) strcpy(candidate02[candidates], &member_info[candidates]);
            else if (candidates == 2) strcpy(candidate03[candidates], &member_info[candidates]);
            else if (candidates == 3) strcpy(candidate04[candidates], &member_info[candidates]);
            else if (candidates == 4) strcpy(candidate05[candidates], &member_info[candidates]);
        else strcpy(candidate06[candidates], &member_info[candidates]);
        printf("1. Name: ");
        scanf("%s",&member_info[candidates][0]);
        getchar();
        printf("2. Date of Birth: (YYYY/MM/DD format): ");
        scanf("%s/%s/%s",
            &member_info[candidates][1],
            &member_info[candidates][2],
            &member_info[candidates][3]);
        getchar();
        printf("3. Gender: ");
        scanf("%c",&member_info[candidates][4]);
        getchar();
        printf("4. Email: ");
        scanf("%s",&member_info[candidates][5]);
        getchar();
        printf("5. Nationality: "); 
        scanf("%s",&member_info[candidates][6]);
        getchar();
        printf("6. BMI: ");
        scanf("%s",&member_info[candidates][7]);
        getchar();
        printf("7. Primary Skill: ");
        scanf("%s",&member_info[candidates][8]);
        getchar();
        printf("8. Secondary Skill: ");
        scanf("%s",&member_info[candidates][9]);
        getchar();
        printf("9. Korean Proficiency Level (TOPIK): ");
        scanf("%s",&member_info[candidates][10]);
        getchar();
        printf("10. MBTI: ");
        scanf("%s",&member_info[candidates][11] );
        getchar();
        printf("11. Introduction: ");
        scanf("%s",&member_info[candidates][12]);
        getchar();
        candidates++;
    }
    for (int i = 0; i < 1; i++) {
        // printf("\nCandidate %d:\n", i + 1);
        printf("Name: %s\n", member_info[i][0]);
        printf("Date of Birth: %s/%s/%s\n", member_info[i][1], member_info[i][2], member_info[i][3]);
        printf("Gender: %s\n", member_info[i][4]);
        printf("Email: %s\n", member_info[i][5]);
        printf("Nationality: %s\n", member_info[i][6]);
        printf("BMI: %s\n", member_info[i][7]);
        printf("Primary Skill: %s\n", member_info[i][8]);
        printf("Secondary Skill: %s\n", member_info[i][9]);
        printf("Korean Proficiency Level: %s\n", member_info[i][10]);
        printf("MBTI: %s\n", member_info[i][11]);
        printf("Introduction: %s\n", member_info[i][12]);
    }
};