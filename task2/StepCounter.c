#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

int main() {
    FITNESS_DATA data[dataArray_size];
    char input;
    int lines;
    while(1) {
        printf( "Menu Options:\n"
                "A: Specify the filename to be imported\n"
                "B: Display the total number of records in the file\n"
                "C: Find the date and time of the timeslot with the fewest steps\n"
                "D: Find the data and time of the timeslot with the largest number of steps\n"
                "E: Find the mean step count of all the records in the file\n"
                "F: Find the longest continuous period where the step count is above 500 steps\n"
                "Q: Quit\n");
        input = getchar();
        while (getchar() != '\n');
        switch (input)
        {
        case 'A':
        case 'a':; // weird not allowed to define a variable as the first thing you do so have to have a semi colon above.
            lines = open_file(data);
            if (lines == 0){
                exit(1);
            }
            break;
        case 'B':
        case 'b':
            printf("B");
            break;

        case 'C':
        case 'c':
            printf("C");
            break;

        case 'D':
        case 'd':
            printf("D");
            break;

        case 'E':
        case 'e':
            printf("E");
            break;

        case 'F':
        case 'f':
            printf("F");
            break;
        case 'Q':
        case 'q':
            printf("Q");
            exit(0);
            break;

        // if they type anything else:
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

}