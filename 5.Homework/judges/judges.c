#include <stdio.h>
#include <stdlib.h>
void remove_usless_stuff(char *str){
    char *src = str; // Pointer to read from str
    char *dst = str; // pointer to write to 
    while (*src)
    {
        if(*src != '"'&& *src != ','){
            *dst = *src; // Copy valid character
            dst++;
        }else if (*src == ',') {
        *dst = '\n';  // Replace comma with newline
        dst++;
    }
        src++;
    }
    *dst='\0'; // null terminate the string
};
int main(void){
    char  judges_array[1000]={0};
    int total_judges=0;
    int selected_members=0;
    printf("####################################\n#      Judge List Data Entry      #\n####################################\n");
    printf("Participating Project: Millieways\n");
    printf("Total number of judges: ");
    scanf("%d",&total_judges);
    printf("Number of Selected Members: ");
    scanf("%d", &selected_members);
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("Stated to input information for %d judges.\n",total_judges);
    printf("++++++++++++++++++++++++++++++++++++\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    int offsets[1000]; // store start index of each judge's info in judges_array
    int pos = 0;  // current position in judges_array

    for (int i = 0; i < total_judges; i++) {
        printf("Judge %d: ", i + 1);
        
        // Read one line of input from user and store it starting at judges_array[pos].
        if (fgets(&judges_array[pos], 1000 - pos, stdin) == NULL) {
            printf("Input error.\n");
            break;  // stop if input fails
        }

        // I want to remove the newline character fgets stores at the end of the string.
        int len = 0;
        while (judges_array[pos + len] != '\0') {  // loop through the characters
            if (judges_array[pos + len] == '\n') {  // if newline found
                judges_array[pos + len] = '\0';    // replace newline with null terminator
                break;
            }
            len++;
        }

        // Store the start position of this judge's string for later use
        offsets[i] = pos;

        // Remove unwanted characters (quotes and commas) inside this judge's string in-place
        remove_usless_stuff(&judges_array[pos]);

        // Move pos forward by the length of the string (without newline)
        pos += len;

        // Stop if no space left to prevent overflow
        if (pos >= 999) break;
    }
    // for (int i=0;i<total_judges;i++){
    //     printf("Judges %d: ",i+1);
    //     fgets(judges_array,1000,stdin);
    // };
    printf("++++++++++++++++++++++++++++++++++++\nJudge information entry is complete.\n++++++++++++++++++++++++++++++++++++\n");
    char yes_no;
    remove_usless_stuff(judges_array);
    printf("[PROJECT] Should we check the judge information? Y/N\n");
    scanf("%c",&yes_no);
    if(yes_no == 'Y'){
        printf("####################################\n#        Display Judge Data        #\n####################################\n");
        for(int i=0;i<total_judges;i++){
            printf("Judge %d\n",i+1);
            printf("%s\n",&judges_array[offsets[i]]);
            
            printf("-----------------------------------\n");
        };
        return 0;
    }else {
        return 0;
    }
    // printf(judges_array);




}