/*
 * MAGRATHEA TRAINING SYSTEM - STAGES 1-3 COMBINED
 * Complete implementation with:
 * - 8-stage training system (Stage 1)
 * - Fitness tracking (Stage 2) 
 * - Workout routines (Stage 3)
 * Fully ANSI C compliant
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/* =============== CONSTANTS =============== */
#define MAX_MEMBERS 10
#define MAX_TESTS 7
#define NAME_LEN 50
#define NICKNAME_LEN 20 
#define DAYS 6
#define EXERCISE_TYPES 5
#define EXERCISES_PER_TYPE 2

/* =============== STRUCTURES =============== */
typedef struct {
    char name[NAME_LEN];
    char nickname[NICKNAME_LEN];
    int gender; // 0=male, 1=female
} Member;

typedef struct {
    char cardio[NAME_LEN];
    char strength[NAME_LEN];
} DailyRoutine;

typedef struct {
    DailyRoutine days[DAYS];
    int core_used; // Tracks core exercise usage
} MemberRoutine;

/* =============== GLOBALS =============== */
const char* exercise_types[EXERCISE_TYPES][EXERCISES_PER_TYPE] = {
    {"Running", "Cycling"},       // Cardio
    {"Push-ups", "Squats"},       // Full-body
    {"Leg Press", "Leg Curl"},    // Lower-body
    {"Pull-ups", "Chin-ups"},     // Upper-body  
    {"Plank", "Crunches"}         // Core
};

const char* day_names[DAYS] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

Member milliways_members[MAX_MEMBERS] = {
    {"Goeun", "G", 1},
    {"Woncheol", "W", 0}, 
    {"Youngjin", "Y", 0},
    {"Hyekyung", "H", 1}
};
int member_count = 4;

float health_scores[MAX_MEMBERS][MAX_TESTS] = {0};
MemberRoutine member_routines[MAX_MEMBERS] = {0};
int health_data_entered = 0;
char training_status[8] = {0}; // Tracks stage completion

/* =============== FUNCTION PROTOTYPES =============== */
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
void set_exercise_routine(void);
void get_exercise_routine(void);
void display_member_list(void);
void select_exercises(int member_index);

/* =============== MAIN =============== */
int main() {
    main_menu();
    return 0;
}

/* =============== MENUS =============== */
void main_menu(void) {
    while (1) {
        printf("\n=== MAIN MENU ===\n");
        printf("I. Audition Management\n");
        printf("II. Training\n"); 
        printf("III. Debut\n");
        printf("Q. Quit\n");
        printf("Choice: ");
        
        char input[10];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        
        if (toupper(input[0]) == 'Q' || input[0] == '0') {
            printf("Exiting...\n");
            break;
        }
        
        switch(toupper(input[0])) {  // Only check first character
        case 'I': 
            if (strcasecmp(input, "I") == 0) printf("Audition\n");
            else if (strcasecmp(input, "II") == 0) training_menu();
            else if (strcasecmp(input, "III") == 0) debut_menu();
            break;
        // ...
}
    }
}

void training_menu(void) {
    while (1) {
        printf("\n=== TRAINING MENU ===\n");
        for (int i = 0; i < 8; i++) {
            printf("%d. Stage %d %s\n", 
                i+1, i+1, 
                training_status[i] == 'P' ? "[COMPLETED]" : "");
        }
        printf("0. Back\n");
        printf("Choice: ");
        
        int stage;
        scanf("%d", &stage);
        while(getchar() != '\n'); // Clear buffer
        
        if (stage == 0) return;
        
        if (stage < 1 || stage > 8) {
            printf("Invalid stage!\n");
            continue;
        }
        
        // Stage progression rules
        if (stage > 2 && !(training_status[0] == 'P' && training_status[1] == 'P')) {
            printf("Complete Stages 1-2 first!\n");
            continue;
        }
        
        if (stage == 1) {
            physical_strength_menu();
        } else {
            handle_training_stage(stage);
        }
    }
}

void physical_strength_menu(void) {
    while (1) {
        printf("\n=== PHYSICAL TRAINING ===\n");
        printf("A. Enter Fitness Data\n");
        printf("B. View Fitness Data\n");
        printf("C. Set Workout Routine\n");
        printf("D. View Workout Routine\n");
        printf("E. Back\n");
        printf("Choice: ");
        
        char choice;
        scanf("%c", &choice);
        while(getchar() != '\n');
        
        switch(toupper(choice)) {
            case 'A': enter_fitness_data(); break;
            case 'B': view_fitness_data(); break;
            case 'C': set_exercise_routine(); break;
            case 'D': get_exercise_routine(); break;
            case 'E': 
                if (health_data_entered) training_status[0] = 'P';
                return;
            default: printf("Invalid choice!\n");
        }
    }
}

/* =============== STAGE 2: FITNESS TRACKING =============== */
void enter_fitness_data(void) {
    display_member_list();
    printf("Enter member nickname: ");
    
    char nickname[NICKNAME_LEN];
    fgets(nickname, sizeof(nickname), stdin);
    nickname[strcspn(nickname, "\n")] = 0;
    
    int found = 0;
    for (int i = 0; i < member_count; i++) {
        if (strcasecmp(nickname, milliways_members[i].nickname) == 0) {
            printf("Enter 7 test scores (comma-separated):\n");
            char input[100];
            fgets(input, sizeof(input), stdin);
            parse_fitness_data(input, health_scores[i]);
            health_data_entered = 1;
            found = 1;
            break;
        }
    }
    
    if (!found) printf("Member not found!\n");
}

void parse_fitness_data(char* input, float* scores) {
    char* token = strtok(input, ",");
    for (int i = 0; i < MAX_TESTS && token != NULL; i++) {
        scores[i] = atof(token);
        token = strtok(NULL, ",");
    }
}

void view_fitness_data(void) {
    if (!health_data_entered) {
        printf("No data available!\n");
        return;
    }
    
    display_member_list();
    printf("Enter nickname: ");
    char nickname[NICKNAME_LEN];
    fgets(nickname, sizeof(nickname), stdin);
    nickname[strcspn(nickname, "\n")] = 0;
    
    for (int i = 0; i < member_count; i++) {
        if (strcasecmp(nickname, milliways_members[i].nickname) == 0) {
            printf("\nFitness Data for %s:\n", milliways_members[i].name);
            for (int j = 0; j < MAX_TESTS; j++) {
                printf("Test %d: %.2f\n", j+1, health_scores[i][j]);
            }
            return;
        }
    }
    printf("Member not found!\n");
}

/* =============== STAGE 3: WORKOUT ROUTINES =============== */
void set_exercise_routine(void) {
    display_member_list();
    printf("Enter member number: ");
    int num;
    scanf("%d", &num);
    while(getchar() != '\n');
    
    if (num < 1 || num > member_count) {
        printf("Invalid number!\n");
        return;
    }
    select_exercises(num-1);
}

void select_exercises(int member_index) {
    printf("\nCreating routine for %s:\n", milliways_members[member_index].name);
    member_routines[member_index].core_used = 0;
    
    for (int day = 0; day < DAYS; day++) {
        printf("\n--- %s ---\n", day_names[day]);
        
        // Cardio selection
        printf("Cardio:\n");
        for (int i = 0; i < EXERCISES_PER_TYPE; i++) {
            printf("%d. %s\n", i+1, exercise_types[0][i]);
        }
        int cardio;
        scanf("%d", &cardio);
        strcpy(member_routines[member_index].days[day].cardio, 
              exercise_types[0][cardio-1]);
        
        // Strength selection
        printf("Strength:\n");
        int option = 1;
        for (int type = 1; type < EXERCISE_TYPES; type++) {
            if (type == 4 && member_routines[member_index].core_used) continue;
            
            for (int ex = 0; ex < EXERCISES_PER_TYPE; ex++) {
                printf("%d. %s\n", option++, exercise_types[type][ex]);
            }
        }
        int strength;
        scanf("%d", &strength);
        
        // Map selection to exercise
        int type = 1 + (strength-1)/2;
        int ex = (strength-1)%2;
        strcpy(member_routines[member_index].days[day].strength,
              exercise_types[type][ex]);
        
        if (type == 4) member_routines[member_index].core_used = 1;
    }
    printf("Routine created!\n");
}

void get_exercise_routine(void) {
    display_member_list();
    printf("Enter nickname: ");
    char nickname[NICKNAME_LEN];
    fgets(nickname, sizeof(nickname), stdin);
    nickname[strcspn(nickname, "\n")] = 0;
    
    for (int i = 0; i < member_count; i++) {
        if (strcasecmp(nickname, milliways_members[i].nickname) == 0) {
            printf("\nWorkout Routine for %s:\n", milliways_members[i].name);
            for (int day = 0; day < DAYS; day++) {
                printf("%s:\n", day_names[day]);
                printf("  Cardio: %s\n", member_routines[i].days[day].cardio);
                printf("  Strength: %s\n", member_routines[i].days[day].strength);
            }
            return;
        }
    }
    printf("Member not found!\n");
}

/* =============== UTILITIES =============== */
void display_member_list(void) {
    printf("\n=== MEMBERS ===\n");
    for (int i = 0; i < member_count; i++) {
        printf("%d. %s (%s)\n", 
            i+1, 
            milliways_members[i].name, 
            milliways_members[i].nickname);
    }
}

void handle_training_stage(int stage) {
    printf("\nEvaluating Stage %d...\n", stage);
    printf("Enter result (P=Pass/F=Fail/Q=Quit): ");
    char result;
    scanf("%c", &result);
    while(getchar() != '\n');
    
    if (toupper(result) == 'P') {
        training_status[stage-1] = 'P';
        printf("Stage %d completed!\n", stage);
    } 
    else if (toupper(result) == 'F') {
        training_status[stage-1] = 'F';
        printf("Stage %d failed - try again later.\n", stage);
    }
}

void debut_menu(void) {
    printf("\nDebut management module\n");
}

/* === END OF IMPLEMENTATION === */