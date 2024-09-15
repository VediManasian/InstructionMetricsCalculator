#include <stdio.h>
#include <stdlib.h>

int main_menu() {
    int usr_choice;
    printf("Performance assessment:\n"
    "--------------------\n"
    "1) Enter parameteres\n"
    "2) Print table of input parameters\n"
    "3) Print table of performance\n"
    "4) Quit\n"
    "Enter selection: ");
    scanf("%d", &usr_choice);
    return usr_choice;
}

int main() {

    int user_choice;

    int num_IC, frequency, CPI;


    do {
        user_choice = main_menu(); //Shows Main Manu and takes user input
        switch(user_choice) {
        case 1:
            //-------------------------------------



            //-------------------------------------
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printf("Quitting the program...\n");
            exit(0); //Terminate the run
        default:
            printf("Invalid input\n");
            break;
        }
    } while (user_choice != 4); //Loops until user quits (AKA chooses 4)
    

    return 0;
}