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

float health_scores[MAX_MEMBERS][MAX_TESTS] = {0}; // 2D array to store fitness data
int health_data_entered = 0; // Flag to check if any data was entered

char training_status[8] = {0}; // Stage status: 0 = not attempted, 'P' = passed, 'F' = failed

/* Function Prototypes */
void main_menu(void);
void training_menu(void);
void debut_menu(void);
void handle_training_stage(int stage);

void physical_strength_menu(void);
void enter_fitness_data(void);
void view_fitness_data(void);
void parse_fitness_data(char* input, float* scores);
void display_all_fitness_data(void);
void display_member_fitness(char* nickname);
void display_test_result(char* nickname, int test);

/* Main function */
int main() {
    main_menu();
    return 0;
}

/* Main Menu System */
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
        
        if (strlen(input) == 0 || strcmp(input, "0") == 0 || tolower(input[0]) == 'q') {
            printf("Exiting program.\n");
            break;
        }
        
        if (strcasecmp(input, "I") == 0) {
            printf("Audition Management selected.\n");
        } else if (strcasecmp(input, "II") == 0) {
            training_menu();
        } else if (strcasecmp(input, "III") == 0) {
            debut_menu();
        } else {
            printf("Invalid selection. Please try again.\n");
        }
    }
}

/* Debut Menu Placeholder */
void debut_menu(void) {
    printf("Debut Management functionality coming soon.\n");
}

/* Training Menu with Stage Selection */
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

        if (strlen(input) == 0 || strcmp(input, "0") == 0 || tolower(input[0]) == 'q') {
            printf("Returning to main menu.\n");
            break;
        }

        int stage;
        if (sscanf(input, "%d", &stage) != 1 || stage < 1 || stage > 8) {
            printf("Invalid selection. Please enter a number 1-8.\n");
            continue;
        }

        // Enforce stage prerequisites
        if (stage > 2 && (training_status[0] != 'P' || training_status[1] != 'P')) {
            printf("You must complete Stages 1 and 2 before accessing this stage.\n");
            continue;
        }
        if (stage == 2 && training_status[0] != 'P') {
            printf("You must complete Stage 1 before accessing Stage 2.\n");
            continue;
        }

        if (training_status[stage - 1] == 'P') {
            printf("This stage has already been completed.\n");
            continue;
        }

        if (stage == 1) {
            physical_strength_menu();
        } else {
            handle_training_stage(stage);
        }
    }
}

/* Placeholder for regular stage completion */
void handle_training_stage(int stage) {
    printf("Evaluating Stage %d... Evaluation complete.\n", stage);
    printf("Marking Stage %d as Passed.\n", stage);
    training_status[stage - 1] = 'P';
}

/* Stage 1 Fitness System Sub-Menu */
void physical_strength_menu(void) {
    while (1) {
        printf("\nPhysical Strength & Knowledge:\n");
        printf("A. Enter Fitness Data\n");
        printf("B. View Fitness Data\n");
        printf("C. Complete Stage 1 and Return to Training Menu\n");
        printf("Enter your choice: ");

        char input[10];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) == 0) continue;

        switch (toupper(input[0])) {
            case 'A':
                enter_fitness_data();
                break;
            case 'B':
                view_fitness_data();
                break;
            case 'C':
                if (health_data_entered) {
                    training_status[0] = 'P';
                    printf("Stage 1 completed successfully!\n");
                } else {
                    printf("Error: You must enter fitness data before completing this stage.\n");
                    continue;
                }
                return;
            default:
                printf("Invalid selection. Please try again.\n");
        }
    }
}

/* Enter fitness data for a member */
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

/* Parse fitness data input string into score array */
void parse_fitness_data(char* input, float* scores) {
    char* token = strtok(input, ",");
    int i = 0;
    while (token != NULL && i < MAX_TESTS) {
        scores[i++] = atof(token);
        token = strtok(NULL, ",");
    }
}

/* View various fitness data reports */
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

        if (strlen(input) == 0) continue;

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
                while (getchar() != '\n'); // clear buffer

                display_test_result(nickname, test);
                break;
            }
            case '4':
                return;
            default:
                printf("Invalid selection.\n");
        }
    }
}

/* Show all members' fitness data */
void display_all_fitness_data(void) {
    printf("\nFull Fitness Report:\n");
    for (int i = 0; i < member_count; i++) {
        printf("%s (%s): ", milliways_members[i].name, milliways_members[i].nickname);
        for (int j = 0; j < MAX_TESTS; j++) {
            printf("%.2f ", health_scores[i][j]);
        }
        printf("\n");
    }
}

/* Show specific member's test results */
void display_member_fitness(char* nickname) {
    int index = -1;
    for (int i = 0; i < member_count; i++) {
        if (strcasecmp(nickname, milliways_members[i].nickname) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Member not found.\n");
        return;
    }

    printf("%s (%s) Fitness Results:\n", milliways_members[index].name, nickname);
    for (int i = 0; i < MAX_TESTS; i++) {
        printf("Test %d: %.2f\n", i + 1, health_scores[index][i]);
    }
}

/* Show specific test result for a member */
void display_test_result(char* nickname, int test) {
    if (test < 1 || test > MAX_TESTS) {
        printf("Invalid test number. Must be between 1 and 7.\n");
        return;
    }

    int index = -1;
    for (int i = 0; i < member_count; i++) {
        if (strcasecmp(nickname, milliways_members[i].nickname) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Member not found.\n");
        return;
    }

    printf("Result for %s on Test %d: %.2f\n", nickname, test, health_scores[index][test - 1]);
}
