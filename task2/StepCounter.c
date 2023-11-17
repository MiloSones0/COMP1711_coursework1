#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here

// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array

int main(){
    // FILE * file;
    // while(menu(file));
    FITNESS_DATA data[dataArray_size];
    char input;
    while(1) {
        printf( "Menu Options:"
                "A: Specify the filename to be imported\n"
                "B: Display the total number of records in the file\n"
                "C: Find the date and time of the timeslot with the fewest steps\n"
                "D: Find the data and time of the timeslot with the largest number of steps\n"
                "E: Find the mean step count of all the records in the file\n"
                "F: Find the longest continuous period where the step count is above 500 steps\n"
                "Q: Quit\n");
        input = getchar();
    }
    while (getchar() != '\n');
    switch (input)
    {
    case 'A':
    case 'a':
        return 0;
        break;
    case 'B':
    case 'b':
        return 0;
        break;

    case 'C':
    case 'c':
        return 0;
        break;

    case 'D':
    case 'd':
        return 0;
        break;

    case 'E':
    case 'e':
        return 0;
        break;

    case 'F':
    case 'f':
        return 0;
        break;

    case 'G':
    case 'g':
        return 0;
        break;

    case 'Q':
    case 'q':
        return 0;
        break;

    // if they type anything else:
    default:
        printf("Invalid choice. Try again.\n");
    }


}


int total_records(FITNESS_DATA *data) {
    // add error checking for file probably in seperate function.
    // change to use open_file func at some point
    char line_buffer[buffer_size];
    int total_records = 0;
    for (int i = 0; i < dataArray_size; i++){
        
    }
    return total_records;
}

int fewest_steps(FILE * file) {
    return 0;
}




int menu(FILE * file) {
    char input[1];
    printf( "Menu Options:"
            "A: Specify the filename to be imported\n"
            "B: Display the total number of records in the file\n"
            "C: Find the date and time of the timeslot with the fewest steps\n"
            "D: Find the data and time of the timeslot with the largest number of steps\n"
            "E: Find the mean step count of all the records in the file\n"
            "F: Find the longest continuous period where the step count is above 500 steps\n"
            "Q: Quit\n");
    // Add check that a file has been provided and is valid before allowing any other function to run
    // have a valid bool that is default value false and is updated when open_file is called and check in each if breanch.
    scanf("%s", input);
    if(!strcmp(input, "A")) {
        file = open_file();
    }
    else if(!strcmp(input, "B")) {
        printf("Total records: %d", total_records(file));

    }
    else if(!strcmp(input, "C")) {
        printf("Fewest steps: ");
    }
    else if(!strcmp(input, "D")) {
        printf("Largest steps: ");
    }
    else if(!strcmp(input, "E")) {
        printf("Mean step count: ");
    }
    else if(!strcmp(input, "F")) {
        printf("Longest period start: \n"
               "Longest period end: ");
    }
    else if(!strcmp(input, "Q")) {
        return 0;
    }
    else {
        printf("Invalid input\n");
    }
    return 1;
}