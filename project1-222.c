#include <stdio.h>
#include <stdlib.h>

int main_menu() {
    int usr_choice, validInput;
    while (1) {
        printf("\nPerformance assessment:\n"
        "--------------------\n"
        "1) Enter parameteres\n"
        "2) Print table of input parameters\n"
        "3) Print table of performance\n"
        "4) Quit\n"
        "Enter selection: ");
        validInput = scanf("%d", &usr_choice);
        if (validInput == 1) {
        break;
        } else {
            printf("Invalid Input! Please enter an integer (1-4).\n");
            while (getchar() != '\n');
        }
    }
    return usr_choice;
}

float add(float CPI, int IC) {
    float addition = CPI + IC;
    return addition;
}

int main() {

    int num_IC = 0;
    int frequency, i, user_choice;
    float *cpi = NULL, avg_cpi, cycle_count, avg_IC, CPU_time, MIPS;
    int *ICount = NULL;
    


    do {
        user_choice = main_menu(); //Shows Main Manu and takes user input
        switch(user_choice) {
        case 1:
            //-------------------------------------
            free(cpi); //Frees the allocated memory for cpi so it can be reallocated
            free(ICount); //Frees the allocated memory for ICount so it can be reallocated

            printf("Enter the number of instruction classes:");
            scanf("%d", &num_IC);

            printf("Enter the frequency of the machine (MHz): ");
            scanf("%d", &frequency);

            cpi = malloc(num_IC * sizeof(float));
            ICount = malloc(num_IC * sizeof(int));

            for (i = 0; i < num_IC; i++) { //Takes CPI and Instruction Count of Each Class
                printf("Enter CPI of class %d: ", i + 1);
                scanf("%f", &cpi[i]);
                printf("Enter instruction count of class %d (millions): ", i + 1);
                scanf("%d", &ICount[i]);
            }
            
            //-------------------------------------
            break;
        case 2:
            if (num_IC == 0) { //Checks to make sure parameters have been entered.
                printf("The number of Classes are 0. You must first enter parameters.");
                break;
            }

            printf("-----------------------\n|Class |CPI    |Count  |\n"); //Prints the list
            for (i = 0; i < num_IC; i++) {
                printf("-----------------------\n|%d     |%g      |%d      |\n", i+1, cpi[i], ICount[i]); //Adds the amount of rows needed
            }
            printf("-----------------------\n");


            break;
        case 3:
            if (num_IC == 0) { //Checks to make sure parameters have been entered.
                printf("The number of Classes are 0. You must first enter parameters.");
                break;
            }

            for (i = 0; i < num_IC; i++) { //Calculates average CPI
                cycle_count += cpi[i] * ICount[i];
                avg_IC += ICount[i];
            }
            avg_cpi = cycle_count / avg_IC;

            CPU_time = ((avg_cpi * avg_IC) / frequency) * 1000; //Calculates Clock Rate in ms

            MIPS = frequency / avg_cpi; //Calculates MIPS



            printf("-----------------------\n|Performance   |Value |\n"); //Displays table of performance
            printf("-----------------------\n|Average CPI   |%.2f  |\n", avg_cpi);
            printf("-----------------------\n|CPU Time(ms)  |%.2f  |\n", CPU_time);
            printf("-----------------------\n|MIPS          |%.2f  |\n", MIPS);
            printf("-----------------------\n");

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