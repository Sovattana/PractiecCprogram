#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep()

#define SIZE 6
#define GRID_SIZE 10

struct car
{
    char car[30];
    char brand[30];
    int year;
    int x,y;
};

struct  car cars[SIZE] = {
    {"Toyota","Toyota",2001,0,0},
    {"Model Y","Tesla",2010,0,0},
    {"Kia 2003","KIa",2003,0,0},
    {"Prius","Toyota",2020,0,0},
    {"Ford","Ford",2015,0,0},
    {"","",0,0,0}
};

// 1.Function to store new car
void user_input(char* car_name, char* car_brand, int car_year, int car_x, int car_y) {
    // Find the first empty slot
    int i;
    for (i = 0; i < SIZE; i++) {
        if (cars[i].car[0] == '\0') { // Check if car name is empty
            break;
        }
    }
    
    if (i < SIZE) {
        strncpy(cars[i].car, car_name, 29);
        cars[i].car[29] = '\0'; // Ensure null-termination
        strncpy(cars[i].brand, car_brand, 29);
        cars[i].brand[29] = '\0';
        cars[i].year = car_year;
        cars[i].x = car_x;
        cars[i].y = car_y;
    } else {
        printf("No space left to add new car!\n");
    }
}
//2.Receive User input
void userinput_car_info(){
    char user_input_car_name [30];
    char user_car_brand[30];
    int user_input_year;
    int user_input_x,user_input_y;
    printf("Car name: ");
    fgets(user_input_car_name,30,stdin);

    printf("Car brand: ");
    fgets(user_car_brand,30,stdin);

    printf("Year of car: ");
    scanf("%d",&user_input_year);

    printf("Position: ");
    scanf("%d,%d",&user_input_x,&user_input_y);

    while (getchar() != '\n');
    user_input(user_input_car_name,user_car_brand,user_input_year,user_input_x,user_input_y);
};

//3.print car information
void print_car_info(){
    for (int i = 0; i < SIZE; i++) {
        if (cars[i].car[0] != '\0') { // Only print if car exists
            printf("Car %d:\n", i+1);
            printf("  Name: %s\n", cars[i].car);
            printf("  Brand: %s\n", cars[i].brand);
            printf("  Year: %d\n", cars[i].year);
            printf("  Position: (%d, %d)\n\n", cars[i].x, cars[i].y);
        }
    }
}
//4.This function is for Selected car for its movement
void selected_car(){
    int car_number = 0;
    printf("Select car by number to move it to the destination: ");
    scanf("%d",&car_number);
    if(car_number==1){
        //It will select the car number in car struct based on the selected num
    }
    return car_number;
};
//5.Print Grid Function, Receive the number of the selected car and move that car
void drawGrid(int carX, int carY, int destX, int destY) {
    printf("    ");
    for (int i = 0; i < GRID_SIZE; i++) printf("%2d ", i);
    printf("\n");

   for (int y = 0; y < GRID_SIZE; y++) {
        printf("%2d |", y); // Prints row numbers
        for (int x = 0; x < GRID_SIZE; x++) {
            if (x == carX && y == carY)
                printf("%d",selected_car); // Shows the car (e.g., " C ")
            else if (x == destX && y == destY)
                printf(" D "); // Shows the destination
            else
                printf(" . "); // Empty space
        }
        printf("\n");
    }
}

void drawGrid(int carX, int carY, int destX, int destY);

//Main function
int main() {
    int carX = 0, carY = 0;
    int destX, destY;

    userinput_car_info();
    print_car_info();
    selected_car();

    printf("Enter destination coordinates (0 to %d for X and Y): ", GRID_SIZE - 1);
    scanf("%d %d", &destX, &destY);

    //Automatic Movement
    while (carX != destX || carY != destY) {
        system("clear"); // Use "cls" for Windows
        drawGrid(carX, carY, destX, destY);
        sleep(1);

        if (carX < destX) carX++;
        else if (carX > destX) carX--;

        else if (carY < destY) carY++;
        else if (carY > destY) carY--;
    }

    system("clear");
    drawGrid(carX, carY, destX, destY);
    printf("Arrived at (%d, %d)\n", destX, destY);

    return 0;
}


