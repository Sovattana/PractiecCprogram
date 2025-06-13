#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* 
 * Global Variables:
 * training_status - Array to track completion status of each training stage
 *   (0 = not attempted, 'P' = passed, 'F' = failed)
 * current_stage - Tracks which stage the user is currently working on
 */
char training_status[8] = {0};
int current_stage = 0;

// Function prototypes - forward declarations of all functions
void main_menu();
void training_menu();
void debut_menu();
void handle_training_stage(int stage);

/*
 * Main Function:
 * Entry point of the program, simply calls the main menu to start the interface
 */
int main() {
    main_menu();
    return 0;
}

/*
 * Main Menu Function:
 * Displays the top-level menu and handles user navigation
 */
void main_menu() {
    // Infinite loop keeps menu running until user chooses to exit
    while (1) {
        // Display main menu options
        printf("\nMain Menu:\n");
        printf("I. Audition Management\n");
        printf("II. Training\n");
        printf("III. Debut\n");
        printf("Enter your choice (empty/0/Q/q to quit): ");
        
        // Get user input
        char input[10];
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;
        
        /* 
         * Exit Conditions:
         * - Empty input
         * - "0" input
         * - Q or q (case insensitive)
         */
        if (strlen(input) == 0 || strcmp(input, "0") == 0 || 
            tolower(input[0]) == 'q') {
            printf("Exiting program.\n");
            break;
        }
        
        /*
         * Menu Selection Handling:
         * - I/i: Audition Management
         * - II/ii: Training Menu
         * - III/iii: Debut Menu
         * Case insensitive comparison
         */
        if (strcasecmp(input, "I") == 0) {
            printf("Audition Management selected.\n");
            // Actual implementation would go here
        } 
        else if (strcasecmp(input, "II") == 0) {
            training_menu(); // Enter training sub-menu
        } 
        else if (strcasecmp(input, "III") == 0) {
            debut_menu(); // Enter debut sub-menu
        } 
        else {
            printf("Invalid selection. Please try again.\n");
        }
    }
}

/*
 * Training Menu Function:
 * Displays and manages the 8 training stages with access rules
 */
void training_menu() {
    // Infinite loop keeps menu running until user chooses to return
    while (1) {
        // Display all training stage options
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
        
        // Get user input
        char input[10];
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;
        
        /*
         * Exit Conditions:
         * - Empty input
         * - "0" input
         * - Q or q (case insensitive)
         * Returns to main menu
         */
        if (strlen(input) == 0 || strcmp(input, "0") == 0 || 
            tolower(input[0]) == 'q') {
            printf("Returning to main menu.\n");
            break;
        }
        
        /*
         * Input Validation:
         * - Must be a number between 1-8
         * - Converts string input to integer stage number
         */
        int stage;
        if (sscanf(input, "%d", &stage) != 1 || stage < 1 || stage > 8) {
            printf("Invalid selection. Please enter a number 1-8.\n");
            continue;
        }
        
        /*
         * Stage Access Rules:
         * - Stages 3-8 require stages 1 and 2 to be passed first
         * - Stage 2 requires stage 1 to be passed first
         */
        if (stage > 2) {
            // Check if prerequisite stages are completed
            if (training_status[0] != 'P' || training_status[1] != 'P') {
                printf("You must complete Stages 1 and 2 before accessing this stage.\n");
                continue;
            }
        } else if (stage == 2) {
            // Check if stage 1 is completed
            if (training_status[0] != 'P') {
                printf("You must complete Stage 1 before accessing Stage 2.\n");
                continue;
            }
        }
        
        // Check if stage is already completed
        if (training_status[stage-1] == 'P') {
            printf("This stage has already been completed.\n");
            continue;
        }
        
        // Process the selected training stage
        handle_training_stage(stage);
    }
}

/*
 * Handle Training Stage Function:
 * Manages the evaluation process for a specific training stage
 * @param stage: The training stage number (1-8) to handle
 */
void handle_training_stage(int stage) {
    printf("\nTraining Stage %d selected.\n", stage);
    
    // Loop until user provides valid evaluation input
    while (1) {
        printf("Would you like to enter the evaluation result? (Y/N): ");
        char input[10];
        fgets(input, sizeof(input), stdin);
        
        // Clean and standardize input
        input[strcspn(input, "\n")] = 0;
        for (int i = 0; input[i]; i++) {
            input[i] = toupper(input[i]);
        }
        
        // Process evaluation choice
        if (strcmp(input, "Y") == 0) {
            // User wants to enter evaluation result
            printf("Did you complete the training and pass the certification? (Y/N): ");
            fgets(input, sizeof(input), stdin);
            
            // Clean and standardize input
            input[strcspn(input, "\n")] = 0;
            for (int i = 0; input[i]; i++) {
                input[i] = toupper(input[i]);
            }
            
            // Record pass/fail status
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
            // User declines to enter evaluation
            printf("Returning to training menu.\n");
            break;
        } 
        else {
            // Invalid input
            printf("Invalid input. Please enter Y or N.\n");
        }
    }
}

/*
 * Debut Menu Function:
 * Placeholder for debut management functionality
 */
void debut_menu() {
    printf("\nDebut Menu selected.\n");
    // Actual implementation would go here
}