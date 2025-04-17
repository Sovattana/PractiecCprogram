#include <stdio.h>

int main(void){
    int score;

    pintf("Enter your score : ");
    scanf("%d",&score);

    if (score>=90)
        printf("Passed : Grade A \n");
    else if (score >= 80)
        printf("Passed : Grade B \n");
    else if (score >= 70)
        printf("Passed : Grade C \n");
    else if (score >= 60)
        printf("Passed : Grade D \n");
    else
        printf("Failed : Grade F");
        return 0;
}