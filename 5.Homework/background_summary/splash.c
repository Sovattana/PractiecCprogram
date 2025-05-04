#include <stdio.h>
#include <stdlib.h>
int main(void){
    int year,month,day;
    char name[100];
    printf("[Please e1nter the current date in the ""yyyy-mm-dd"" format]: ");
    scanf("%d-%d-%d",&year,&month,&day);
    getchar();
    printf("[Please enter your name]: ");
    scanf("%s",name);
    int isNameCorrect = 1;
    char character[]="Arthur Dent";
    for (int i ;character[i] != '\0' && name[i] != '\0' ; i++){
        if (name[i] != character[i]){
            isNameCorrect = 0;
            break;
        }
    };

    if (isNameCorrect && year == 2023 && month == 8 && day == 20 ){
        //check if the two input value is incorrect
        printf("**The input has been processed successfully.**\n");
        //wait for 3 seconds
        system("timeout /t 3 >nul");
        //After 3s clear the screen
        system("cls") ;
        //Print the backgoround Summary
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t\t  [Magrathea ver 0.1]\n");
        printf("\t\tMagrathea, where a shining planet is created in a wasteland with no grass,\n");
        printf("\ta place where unseen potential is discovered and gems are polished by the hands of experts,\n");
        printf("\t\t\t\t\t  Welcome to Magrathea.\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("[User]: %s\t\t\t\t\t\t [Execite Time]: %d-%d-%d\n",name,year,month,day);
        printf("=============================================================================================================");
    }else {
        //Incase the two input value is incorrect
        printf("**The input is invalid.**");

    }
    return 0;

};