#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Data storage: 6 candidates, 13 fields per candidate, 50 chars per field
    char candidates[6][13][50]; 
    
    // Field names with increased size to 100 chars (though only 'Introduction' needs it)
    char member_info[13][100] = {
        "Name", "Year of Birth", "Month of Birth", "Day of Birth",
        "Gender", "Email", "Nationality", "BMI",
        "Primary Skill", "Secondary Skill", "Korean Level", "MBTI", "Introduction"
    };

    printf("####################################\n\tAudition Candidate Data Entry\n####################################\n");
    
    int num_candidates = 6;    
    for (int i = 0; i < num_candidates; i++) {
        // Candidate number prompt
        switch(i) {
            case 0: printf("Entering information for the first candidate.\n"); break;
            case 1: printf("Entering information for the second candidate.\n"); break;
            case 2: printf("Entering information for the third candidate.\n"); break;
            case 3: printf("Entering information for the fourth candidate.\n"); break;
            case 4: printf("Entering information for the fifth candidate.\n"); break;
            case 5: printf("Entering information for the sixth candidate.\n"); break;
        }
        
        printf("---------------------------------\n");
        
        // 1. Name input
        printf("1. Name: ");
        fgets(candidates[i][0], 50, stdin);
        candidates[i][0][strcspn(candidates[i][0], "\n")] = '\0'; // Remove newline

        // 2. Date of Birth (split into 3 fields)
        printf("2. Date of Birth (YYYY/MM/DD): ");
        char date_input[50];
        fgets(date_input, 50, stdin);
        char *token = strtok(date_input, "/\n");
        if (token) strcpy(candidates[i][1], token); // Year
        token = strtok(NULL, "/\n");
        if (token) strcpy(candidates[i][2], token); // Month
        token = strtok(NULL, "/\n");
        if (token) strcpy(candidates[i][3], token); // Day

        // 3. Remaining fields (Gender to Introduction)
        const int field_offset = 4;
        for (int j = field_offset; j < 13; j++) {
            printf("%d. %s: ", j - 1, member_info[j]);
            
            // Special handling for Introduction (needs larger buffer)
            if (j == 12) { // Introduction field
                fgets(candidates[i][12], 100, stdin); // Use 100 chars for Introduction
                candidates[i][12][strcspn(candidates[i][12], "\n")] = '\0';
                
                // Clear input buffer if Introduction was too long
                if (strlen(candidates[i][12]) == 99) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                }
            } else {
                fgets(candidates[i][j], 50, stdin);
                candidates[i][j][strcspn(candidates[i][j], "\n")] = '\0';
            }
        }
        printf("=================================\n");
    }

    // Output all candidates
    printf("####################################\n\tAudition Candidate Data Review\n####################################\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("===============================================================================================================\n");
        printf("Name          | DOB        | Gender | Email                | Nationality | BMI  | Primary Skill | Secondary Skill | TOPIK | MBTI |\n");
        printf("===============================================================================================================\n");
        
        // Main data row
        printf("%-14s| %s/%s/%s | %-7s| %-21s| %-12s| %-5s| %-15s| %-17s| %-6s| %-5s|\n",
            candidates[i][0], candidates[i][1], candidates[i][2], candidates[i][3],
            candidates[i][4], candidates[i][5], candidates[i][6], candidates[i][7],
            candidates[i][8], candidates[i][9], candidates[i][10], candidates[i][11]
        );
        
        // Introduction (special formatting)
        printf("---------------------------------------------------------------------------------------------------------------------\n");
        printf(" %-100s|\n", candidates[i][12]); // Fixed: Removed '|' for better readability
        printf("---------------------------------------------------------------------------------------------------------------------\n");
    }
    
    return 0;
}