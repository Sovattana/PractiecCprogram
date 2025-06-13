#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MEMBERS 10
#define MAX_TESTS 7
#define MAX_TRAUMA MAX_MEMBERS
#define MAX_RESPONSES (MAX_TRAUMA * 3)
#define NAME_LEN 50
#define NICKNAME_LEN 20
#define MAX_TRAUMA_DESC 200
#define MAX_RESP_LEN 100

/* Member info */
typedef struct {
    char name[NAME_LEN];
    char nickname[NICKNAME_LEN];
    int gender; /* 0: male, 1: female */
} Member;

/* Trauma record */
typedef struct {
    char nickname[NICKNAME_LEN];
    int age;
    char trauma[MAX_TRAUMA_DESC];
    int hasTrauma;
} TraumaRecord;

/* Counseling question */
typedef struct {
    int id;
    const char *q;
} Question;

/* Counseling response */
typedef struct {
    char nickname[NICKNAME_LEN];
    int qID;
    char resp[MAX_RESP_LEN + 1];
} CounselingResponse;

/* Easter egg struct */
typedef struct {
    char keyword[9]; /* "specter" */
    char message[512];
} EasterEgg;

/* Globals */
Member milliways_members[MAX_MEMBERS] = {
    {"Goeun","G",1}, {"Woncheol","W",0},
    {"Youngjin","Y",0}, {"Hyekyung","H",1}
};
int member_count = 4;

float health_scores[MAX_MEMBERS][MAX_TESTS] = {{0}};
int health_data_entered = 0;
char training_status[8] = {0};

TraumaRecord traumaList[MAX_TRAUMA] = {{0}};
int traumaCount = 0;

Question questionList[5] = {
    {1,"In what situations have you experienced this trauma?"},
    {2,"How has this situation affected your daily life and emotions?"},
    {3,"How have you tried to overcome this trauma?"},
    {4,"What emotions do you associate with this trauma?"},
    {5,"What kind of support do you think is necessary to overcome this trauma?"}
};

CounselingResponse responses[MAX_RESPONSES] = {{0}};
int respCount = 0;

EasterEgg arthurEgg = {
    "specter",
    "I confess. After graduating from university, I was blinded by the arrogance of starting a startup "
    "and recklessly blocked my friends' paths. I painfully learned that when I am the only one convinced "
    "by my idea, it leads to disastrous results. The past Arthur was a ghost of dogmatism and stubbornness."
};

/* Function prototypes */
/* Main menu */
void main_menu(void);
/* Training & Debut */
void training_menu(void);
void debut_menu(void);
/* Fitness Stage 1 */
void physical_strength_menu(void);
void enter_fitness_data(void);
void view_fitness_data(void);
void parse_fitness_data(char*, float*);
void display_all_fitness_data(void);
void display_member_fitness(char*);
void display_test_result(char*, int);
/* Training other stages */
void handle_training_stage(int);
/* Trauma management */
void overcomeTrauma(void);
void trauma_input_menu(void);
void counseling_session_menu(void);
void view_completed_sessions(void);
int find_member_index(const char*);
int find_trauma_index(const char*);
/* Easter egg */
void find_easter_egg(void);
void scramble_show(void);
void toBinaryReversed(char, char*);
int isRightChar(char, char);
int isEasterEgg(const char*);

int main(void) {
    srand((unsigned)time(NULL));
    main_menu();
    return 0;
}

/* Main menu */
void main_menu(void) {
    while (1) {
        printf("\nMain Menu:\nI. Audition\nII. Training\nIII. Debut\nChoice (Q to quit): ");
        char input[16];
        fgets(input, sizeof(input), stdin);
        if (tolower(input[0]) == 'q') {
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
            printf("Invalid selection.\n");
        }
    }
}

/* Debut placeholder */
void debut_menu(void) {
    printf("\nDebut Management functionality coming soon.\n");
}

/* Training menu */
void training_menu(void) {
    while (1) {
        printf("\nTraining Menu:\n1. Physical Strength & Knowledge\n");
        printf("2. Self-Management & Teamwork\nQ. Return\nChoice: ");
        char input[16];
        fgets(input, sizeof(input), stdin);
        if (tolower(input[0]) == 'q') break;
        if (input[0] == '1') {
            physical_strength_menu();
        } else if (input[0] == '2') {
            while (1) {
                printf("\n2. Self-Management & Teamwork:\n");
                printf("A. Mentoring (not implemented)\n");
                printf("B. Trauma Management\n");
                printf("Type \"Arthur\" for Easter Egg\nR. Return\nChoice: ");
                char cmd[32];
                fgets(cmd, sizeof(cmd), stdin);
                cmd[strcspn(cmd, "\n")] = 0;
                if (strcasecmp(cmd, "Arthur") == 0) {
                    find_easter_egg();
                } else if (tolower(cmd[0]) == 'b') {
                    overcomeTrauma();
                } else if (tolower(cmd[0]) == 'r') {
                    break;
                } else {
                    printf("Invalid selection.\n");
                }
            }
        } else {
            printf("Invalid selection.\n");
        }
    }
}

/* Fitness Stage 1 submenu */
void physical_strength_menu(void) {
    while (1) {
        printf("\nPhysical Strength & Knowledge:\n");
        printf("A. Enter Fitness Data\nB. View Fitness Data\n");
        printf("C. Complete Stage 1 and Return\nChoice: ");
        char in[10];
        fgets(in, sizeof(in), stdin);
        char cmd = toupper(in[0]);
        if (cmd == 'A') enter_fitness_data();
        else if (cmd == 'B') view_fitness_data();
        else if (cmd == 'C') {
            if (health_data_entered) {
                training_status[0] = 'P';
                printf("Stage 1 completed!\n");
                return;
            } else {
                printf("Please enter fitness data first.\n");
            }
        } else {
            printf("Invalid choice.\n");
        }
    }
}

void enter_fitness_data(void) {
    printf("\nAvailable Members:\n");
    for (int i = 0; i < member_count; i++) {
        printf("- %s (%s)\n", milliways_members[i].name, milliways_members[i].nickname);
    }
    printf("Enter member nickname: ");
    char nick[NICKNAME_LEN];
    fgets(nick, sizeof(nick), stdin);
    nick[strcspn(nick, "\n")] = 0;
    int idx = find_member_index(nick);
    if (idx < 0) {
        printf("Member not found.\n");
        return;
    }
    printf("Enter fitness data as CSV (7 values):\n");
    printf("Example: 8.5,14.2,2.1,3.5,4.2,6.8,1.5\n");
    char line[128];
    fgets(line, sizeof(line), stdin);
    parse_fitness_data(line, health_scores[idx]);
    health_data_entered = 1;
    printf("Data recorded for %s.\n", milliways_members[idx].name);
}

void parse_fitness_data(char *input, float *scores) {
    char *tk = strtok(input, ",");
    int i = 0;
    while (tk && i < MAX_TESTS) {
        scores[i++] = atof(tk);
        tk = strtok(NULL, ",");
    }
}

void view_fitness_data(void) {
    if (!health_data_entered) {
        printf("No fitness data yet.\n");
        return;
    }
    while (1) {
        printf("\nView Data:\n1. All\n2. Member\n3. Specific Test\n4. Return\nChoice: ");
        char in[10];
        fgets(in, sizeof(in), stdin);
        char c = in[0];
        if (c == '1') display_all_fitness_data();
        else if (c == '2') {
            printf("Enter nickname: ");
            char nick[NICKNAME_LEN];
            fgets(nick,sizeof(nick),stdin);
            nick[strcspn(nick,"\n")] = 0;
            display_member_fitness(nick);
        } else if (c == '3') {
            printf("Enter nickname: ");
            char nick[NICKNAME_LEN];
            fgets(nick,sizeof(nick),stdin);
            nick[strcspn(nick,"\n")] = 0;
            printf("Enter test number (1-7): ");
            int t; scanf("%d",&t);
            while(getchar()!='\n');
            display_test_result(nick,t);
        } else if (c == '4') return;
        else printf("Invalid.\n");
    }
}

void display_all_fitness_data(void) {
    printf("\nAll Fitness Data:\n");
    for (int i = 0; i < member_count; i++) {
        printf("%s (%s): ", milliways_members[i].name, milliways_members[i].nickname);
        for (int j = 0; j < MAX_TESTS; j++) {
            printf("%.2f ", health_scores[i][j]);
        }
        printf("\n");
    }
}

void display_member_fitness(char *nick) {
    int idx = find_member_index(nick);
    if (idx < 0) {
        printf("Member not found.\n");
        return;
    }
    printf("%s (%s):\n", milliways_members[idx].name, nick);
    for (int i = 0; i < MAX_TESTS; i++) {
        printf("Test %d: %.2f\n", i+1, health_scores[idx][i]);
    }
}

void display_test_result(char *nick, int test) {
    int idx = find_member_index(nick);
    if (idx < 0) {
        printf("Member not found.\n");
        return;
    }
    if (test < 1 || test > MAX_TESTS) {
        printf("Invalid test number.\n");
        return;
    }
    printf("%s's result for Test %d: %.2f\n",
           milliways_members[idx].name, test, health_scores[idx][test-1]);
}

/* Other stages placeholder */
void handle_training_stage(int stage) {
    printf("Stage %d evaluated and passed.\n", stage);
    training_status[stage-1] = 'P';
}

/* Trauma management */
void overcomeTrauma(void) {
    while (1) {
        printf("\nTrauma Management:\n1. Input Trauma\n2. Counseling\n3. View Completed\n4. Return\nChoice: ");
        char in[10]; fgets(in,sizeof(in),stdin);
        char c = in[0];
        if (c=='1') trauma_input_menu();
        else if (c=='2') counseling_session_menu();
        else if (c=='3') view_completed_sessions();
        else if (c=='4') return;
        else printf("Invalid.\n");
    }
}

void trauma_input_menu(void) {
    while (1) {
        printf("Enter nickname (or Q to return): ");
        char nick[NICKNAME_LEN];
        fgets(nick,sizeof(nick),stdin);
        nick[strcspn(nick,"\n")] = 0;
        if (tolower(nick[0])=='q') return;
        int mi = find_member_index(nick);
        if (mi<0) { printf("Not found.\n"); continue;}
        int ti = find_trauma_index(nick);
        if (ti<0 && traumaCount<MAX_TRAUMA) ti=traumaCount++;
        strcpy(traumaList[ti].nickname, nick);
        traumaList[ti].age = rand()%23 + 18;
        traumaList[ti].hasTrauma = 1;
        printf("Enter trauma description: ");
        fgets(traumaList[ti].trauma, MAX_TRAUMA_DESC, stdin);
        strtok(traumaList[ti].trauma, "\n");
        printf("Recorded.\n");
    }
}

void counseling_session_menu(void) {
    printf("\nTrauma cases:\n");
    for (int i=0;i<traumaCount;i++) {
        if (traumaList[i].hasTrauma) printf("- %s\n", traumaList[i].nickname);
    }
    printf("Enter nickname to counsel (or Q): ");
    char nick[NICKNAME_LEN];
    fgets(nick,sizeof(nick),stdin);
    nick[strcspn(nick,"\n")] = 0;
    if (tolower(nick[0])=='q') return;
    int ti = find_trauma_index(nick);
    if (ti<0) { printf("No record.\n"); return;}
    int done=0, asked[5]={0};
    for (int r=0;r<respCount;r++) {
        if (strcmp(responses[r].nickname,nick)==0) {
            asked[responses[r].qID-1]=1; done++;
        }
    }
    while (done<3) {
        int q;
        do { q = rand()%5; } while(asked[q]);
        asked[q]=1;
        printf("\nQ: %s\nA: ", questionList[q].q);
        char ans[MAX_RESP_LEN+2];
        fgets(ans,sizeof(ans),stdin);
        ans[strcspn(ans,"\n")]=0;
        if (strlen(ans)==0 || strlen(ans)>MAX_RESP_LEN) {
            printf("Invalid.\n");
            continue;
        }
        strcpy(responses[respCount].nickname, nick);
        responses[respCount].qID = questionList[q].id;
        strcpy(responses[respCount].resp, ans);
        respCount++; done++;
        if (done<3) {
            printf("Pause? (Y to pause): ");
            char c = getchar(); while(getchar()!='\n');
            if (tolower(c)=='y') { printf("Paused.\n"); return;}
        }
    }
    printf("Counseling done for %s\n", nick);
}

void view_completed_sessions(void) {
    for (int i=0;i<traumaCount;i++) {
        int cnt=0;
        for (int j=0;j<respCount;j++) {
            if (strcmp(traumaList[i].nickname, responses[j].nickname)==0) cnt++;
        }
        if (cnt>0) printf("%s: %d answered\n", traumaList[i].nickname, cnt);
    }
    printf("Enter nickname to view (or Q): ");
    char nick[NICKNAME_LEN];
    fgets(nick,sizeof(nick),stdin);
    nick[strcspn(nick,"\n")]=0;
    if (tolower(nick[0])=='q') return;
    int ti = find_trauma_index(nick);
    if (ti<0) { printf("Not found.\n"); return;}
    printf("%s (age %d)\nTrauma: %s\n", traumaList[ti].nickname,
           traumaList[ti].age, traumaList[ti].trauma);
    for (int j=0;j<respCount;j++) {
        if (strcmp(responses[j].nickname,nick)==0) {
            printf("Q%d: %s\nA: %s\n", responses[j].qID,
                   questionList[responses[j].qID-1].q,
                   responses[j].resp);
        }
    }
}

/* Helpers */
int find_member_index(const char *nick) {
    for (int i=0;i<member_count;i++)
        if (strcasecmp(nick, milliways_members[i].nickname)==0)
            return i;
    return -1;
}

int find_trauma_index(const char *nick) {
    for (int i=0;i<traumaCount;i++)
        if (strcasecmp(nick, traumaList[i].nickname)==0)
            return i;
    return -1;
}

/* Easter egg */
void find_easter_egg(void) {
    printf("<<Arthur's Easter Egg>>\n");
    scramble_show();
    printf("Enter 7 characters matching above: ");
    char input[16];
    fgets(input, sizeof(input), stdin);
    if (isEasterEgg(input)) {
        printf("##Easter Egg Discovered!$$\n%s\n", arthurEgg.message);
    } else {
        printf("Incorrect. Returning.\n");
    }
}

void scramble_show(void) {
    char bins[7][9];
    for (int i=0;i<7;i++) toBinaryReversed(arthurEgg.keyword[i], bins[i]);
    for (int i=6;i>=0;i--) printf("%s ", bins[i]);
    printf("\n");
}

void toBinaryReversed(char ch, char *out) {
    for (int i=0;i<8;i++)
        out[i] = ((ch >> i) & 1) ? '1' : '0';
    out[8] = 0;
}

int isRightChar(char in, char target) {
    return toupper(in) == toupper(target);
}

int isEasterEgg(const char *in) {
    for (int i=0;i<7;i++) if (!isRightChar(in[i], arthurEgg.keyword[i])) return 0;
    return 1;
}
