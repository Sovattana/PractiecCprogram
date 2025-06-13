/*
 * Magrathea Training System - Stage 1 with Fitness Tracking Extension
 * 
 * Primary Goal:
 * This system manages Cody Enter's 8-stage trainee development program with integrated
 * physical fitness tracking for Milliways members, enforcing structured progression
 * through sequential training stages while collecting detailed fitness metrics.
 *
 * Core Functionality:
 * 1. Main Menu System:
 *    - Audition Management (placeholder)
 *    - Training Program (8 stages with progression rules)
 *    - Debut Management (placeholder)
 * 
 * 2. Training Stage Features:
 *    - Stages 1-2 must be completed sequentially
 *    - Stages 3-8 can be taken in any order after prerequisites
 *    - Stage evaluations recorded with Pass/Fail status
 * 
 * 3. Fitness Tracking System (Stage 1 Extension):
 *    - Member fitness profile management
 *    - 7 standardized physical tests with gender-specific metrics
 *    - Comprehensive data viewing options:
 *      * Full fitness reports
 *      * Member-specific results
 *      * Individual test analysis
 *
 * Expected Usage Flow:
 * 1. Trainees progress through locked stages sequentially
 * 2. Physical fitness baselines recorded in Stage 1
 * 3. Regular evaluations determine stage completion
 * 4. Post-stage-2, specialized training becomes available
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_MEMBERS 10
#define MAX_TESTS 7
#define NAME_LEN 50
#define NICKNAME_LEN 20

/* Structure to store member information */
typedef struct {
    char name[NAME_LEN];
    char nickname[NICKNAME_LEN];
    int gender; /* 0: male, 1: female */
} Member;

/* Global variables */
Member milliways_members[MAX_MEMBERS] = {
    {"Goeun", "G", 1},
    {"Woncheol", "W", 0},
    {"Youngjin", "Y", 0},
    {"Hyekyung", "H", 1}
};
int member_count = 4;

float health_scores[MAX_MEMBERS][MAX_TESTS] = {0};
int health_data_entered = 0;

/* Original training system variables */
char training_status[8] = {0}; /* 0=not attempted, 'P'=passed, 'F'=failed */
int current_stage = 0;

/* Function prototypes - original */
void main_menu(void);
void training_menu(void);
void debut_menu(void);
void handle_training_stage(int stage);

/* New function prototypes for fitness system */
void physical_strength_menu(void);
void enter_fitness_data(void);
void view_fitness_data(void);
void parse_fitness_data(char* input, float* scores);
void display_all_fitness_data(void);
void display_member_fitness(char* nickname);
void display_test_result(char* nickname, int test);

int main() {
    main_menu();
    return 0;
}

/* Original main menu function */
void main_menu(void) {
    while (1) {
        printf("\nMain Menu:\n");
        printf("I. Audition Management\n");
        printf("II. Training\n");
        printf("III. Debut\n");
        printf("Enter your choice (empty/0/Q/q to quit): ");
        
        char input[10];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        
        if (strlen(input) == 0 || strcmp(input, "0") == 0 || 
            tolower(input[0]) == 'q') {
            printf("Exiting program.\n");
            break;
        }
        
        if (strcasecmp(input, "I") == 0) {
            printf("Audition Management selected.\n");
        } 
        else if (strcasecmp(input, "II") == 0) {
            training_menu();
        } 
        else if (strcasecmp(input, "III") == 0) {
            debut_menu();
        } 
        else {
            printf("Invalid selection. Please try again.\n");
        }
    }
}

/* Updated training menu with fitness system integration */
void training_menu(void) {
    while (1) {
        printf("\nTraining Menu:\n");
        printf("1. Physical Strength & Knowledge\n");
        printf("2. Self-Management & Teamwork\n");
        printf("3. Language & Pronunciation\n");
        printf("4. Vocal\n");
        printf("5. Dance\n");
        printf("6. Visual & Image\n");
        printf("7. Acting & Stage Performance\n");
        printf("8. Fan Communication\n");
        printf("Enter your choice (empty/0/Q/q to return to main menu): ");
        
        char input[10];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        
        if (strlen(input) == 0 || strcmp(input, "0") == 0 || 
            tolower(input[0]) == 'q') {
            printf("Returning to main menu.\n");
            break;
        }
        
        int stage;
        if (sscanf(input, "%d", &stage) != 1 || stage < 1 || stage > 8) {
            printf("Invalid selection. Please enter a number 1-8.\n");
            continue;
        }
        
        /* Original stage progression rules */
        if (stage > 2) {
            if (training_status[0] != 'P' || training_status[1] != 'P') {
                printf("You must complete Stages 1 and 2 before accessing this stage.\n");
                continue;
            }
        } else if (stage == 2) {
            if (training_status[0] != 'P') {
                printf("You must complete Stage 1 before accessing Stage 2.\n");
                continue;
            }
        }
        
        if (training_status[stage-1] == 'P') {
            printf("This stage has already been completed.\n");
            continue;
        }
        
        /* Special handling for Stage 1 with new fitness system */
        if (stage == 1) {
            physical_strength_menu();
        } else {
            handle_training_stage(stage);
        }
    }
}

/* New function for Physical Strength sub-menu */
void physical_strength_menu(void) {
    while (1) {
        printf("\nPhysical Strength & Knowledge:\n");
        printf("A. Enter Fitness Data\n");
        printf("B. View Fitness Data\n");
        printf("C. Complete Stage 1 and Return to Training Menu\n");  // Changed option text
        printf("Enter your choice: ");
        
        char input[10];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        
        if (strlen(input) == 0) {
            continue;
        }
        
        switch (toupper(input[0])) {
            case 'A':
                enter_fitness_data();
                break;
            case 'B':
                view_fitness_data();
                break;
            case 'C':
                if (health_data_entered) {
                    training_status[0] = 'P';  // Mark Stage 1 as passed
                    printf("Stage 1 completed successfully!\n");
                } else {
                    printf("Error: You must enter fitness data before completing this stage.\n");
                    continue;
                }
                printf("Returning to training menu.\n");
                return;
            default:
                printf("Invalid selection. Please try again.\n");
        }
    }
}

/* New function to handle fitness data entry */
void enter_fitness_data(void) {
    printf("\nAvailable Members:\n");
    for (int i = 0; i < member_count; i++) {
        printf("- %s (%s)\n", milliways_members[i].name, milliways_members[i].nickname);
    }
    
    printf("\nEnter member nickname: ");
    char nickname[NICKNAME_LEN];
    fgets(nickname, sizeof(nickname), stdin);
    nickname[strcspn(nickname, "\n")] = 0;
    
    int member_index = -1;
    for (int i = 0; i < member_count; i++) {
        if (strcasecmp(nickname, milliways_members[i].nickname) == 0) {
            member_index = i;
            break;
        }
    }
    
    if (member_index == -1) {
        printf("Member not found.\n");
        return;
    }
    
    printf("\nEnter fitness data as comma-separated values:\n");
    printf("1-Mile Run(min),100m Sprint(sec),30 Push-ups(min),50 Squats(min),50 Push-ups(min),400m Swim(min),Weightlifting\n");
    printf("Example: 8.5,14.2,2.1,3.5,4.2,6.8,1.5\n");
    
    char input[100];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    
    parse_fitness_data(input, health_scores[member_index]);
    health_data_entered = 1;
    
    printf("Fitness data recorded for %s.\n", milliways_members[member_index].name);
}

/* New helper function to parse fitness data */
void parse_fitness_data(char* input, float* scores) {
    char* token = strtok(input, ",");
    int i = 0;
    
    while (token != NULL && i < MAX_TESTS) {
        scores[i++] = atof(token);
        token = strtok(NULL, ",");
    }
}

/* New function to view fitness data */
void view_fitness_data(void) {
    if (!health_data_entered) {
        printf("No fitness data available.\n");
        return;
    }
    
    while (1) {
        printf("\nView Fitness Data Options:\n");
        printf("1. View all fitness data\n");
        printf("2. View specific member's data\n");
        printf("3. View specific test result\n");
        printf("4. Return to previous menu\n");
        printf("Enter your choice: ");
        
        char input[10];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        
        if (strlen(input) == 0) {
            continue;
        }
        
        switch (input[0]) {
            case '1':
                display_all_fitness_data();
                break;
            case '2': {
                printf("Enter member nickname: ");
                char nickname[NICKNAME_LEN];
                fgets(nickname, sizeof(nickname), stdin);
                nickname[strcspn(nickname, "\n")] = 0;
                display_member_fitness(nickname);
                break;
            }
            case '3': {
                printf("Enter member nickname: ");
                char nickname[NICKNAME_LEN];
                fgets(nickname, sizeof(nickname), stdin);
                nickname[strcspn(nickname, "\n")] = 0;
                
                printf("Enter test number (1-7): ");
                int test;
                scanf("%d", &test);
                while (getchar() != '\n'); /* Clear input buffer */
                
                if (test < 1 || test > 7) {
                    printf("Invalid test number.\n");
                    break;
                }
                
                display_test_result(nickname, test - 1);
                break;
            }
            case '4':
                return;
            default:
                printf("Invalid selection. Please try again.\n");
        }
    }
}

/* New function to display all fitness data */
void display_all_fitness_data(void) {
    printf("\nAll Fitness Data:\n");
    printf("%-15s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", 
           "Name", "Nickname", "1-Mile", "Sprint", "30 Push", "50 Squat", "50 Push", "Swim", "Weight");
    
    for (int i = 0; i < member_count; i++) {
        printf("%-15s%-10s", milliways_members[i].name, milliways_members[i].nickname);
        for (int j = 0; j < MAX_TESTS; j++) {
            printf("%-10.2f", health_scores[i][j]);
        }
        printf("\n");
    }
}

/* New function to display member-specific fitness data */
void display_member_fitness(char* nickname) {
    int member_index = -1;
    for (int i = 0; i < member_count; i++) {
        if (strcasecmp(nickname, milliways_members[i].nickname) == 0) {
            member_index = i;
            break;
        }
    }
    
    if (member_index == -1) {
        printf("Member not found.\n");
        return;
    }
    
    printf("\nFitness Data for %s (%s):\n", 
           milliways_members[member_index].name, 
           milliways_members[member_index].nickname);
    printf("1-Mile Run: %.2f min\n", health_scores[member_index][0]);
    printf("100m Sprint: %.2f sec\n", health_scores[member_index][1]);
    printf("30 Push-ups: %.2f min\n", health_scores[member_index][2]);
    printf("50 Squats: %.2f min\n", health_scores[member_index][3]);
    printf("50 Push-ups: %.2f min\n", health_scores[member_index][4]);
    printf("400m Swim: %.2f min\n", health_scores[member_index][5]);
    printf("Weightlifting: %.2f x bodyweight\n", health_scores[member_index][6]);
}

/* New function to display specific test results */
void display_test_result(char* nickname, int test) {
    int member_index = -1;
    for (int i = 0; i < member_count; i++) {
        if (strcasecmp(nickname, milliways_members[i].nickname) == 0) {
            member_index = i;
            break;
        }
    }
    
    if (member_index == -1) {
        printf("Member not found.\n");
        return;
    }
    
    const char* test_names[] = {
        "1-Mile Run",
        "100m Sprint",
        "30 Push-ups",
        "50 Squats",
        "50 Push-ups",
        "400m Swim",
        "Weightlifting"
    };
    
    printf("\n%s's %s result: ", milliways_members[member_index].name, test_names[test]);
    printf("%.2f", health_scores[member_index][test]);
    
    switch (test) {
        case 0: case 2: case 3: case 4: case 5:
            printf(" minutes\n");
            break;
        case 1:
            printf(" seconds\n");
            break;
        case 6:
            printf(" x bodyweight\n");
            break;
    }
}

/* Original training stage handler */
void handle_training_stage(int stage) {
    printf("\nTraining Stage %d selected.\n", stage);
    
    while (1) {
        printf("Would you like to enter the evaluation result? (Y/N): ");
        char input[10];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        
        for (int i = 0; input[i]; i++) {
            input[i] = toupper(input[i]);
        }
        
        if (strcmp(input, "Y") == 0) {
            printf("Did you complete the training and pass the certification? (Y/N): ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;
            
            for (int i = 0; input[i]; i++) {
                input[i] = toupper(input[i]);
            }
            
            if (strcmp(input, "Y") == 0) {
                training_status[stage-1] = 'P';
                printf("Congratulations! Stage %d passed.\n", stage);
            } else {
                training_status[stage-1] = 'F';
                printf("Stage %d marked as failed. You can retry later.\n", stage);
            }
            break;
        } 
        else if (strcmp(input, "N") == 0) {
            printf("Returning to training menu.\n");
            break;
        } 
        else {
            printf("Invalid input. Please enter Y or N.\n");
        }
    }
}

/* Original debut menu function */
void debut_menu(void) {
    printf("\nDebut Menu selected.\n");
}