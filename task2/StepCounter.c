#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./FitnessDataStruct.h"

int total_records(FILE * file);
int menu(FILE * file);
int fewest_steps(FILE * file);
FILE *open_file();


int main(){
    FILE * file;
    while(menu(file));

}


int total_records(FILE * file) {
    // add error checking for file probably in seperate function.
    // change to use open_file func at some point
    int buffer_size = 100;
    char line_buffer[buffer_size];
    int total_records = 0;
    while (fgets(line_buffer, buffer_size, file)) {
        total_records ++;
    }
    return total_records;
}

int fewest_steps(FILE * file) {
    return 0;
}

FILE *open_file() {
    char filename[50];
    printf("Input filename:");
    scanf("%s", filename); 
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        // change to repromt user and also add checking data is correct format
        printf("Error opening file\n");
        printf("Make sure filename is correct\n");
        return 0;
    }
    return file;
}


int menu(FILE * file) {
    char input[1];
    printf("A: Specify the filename to be imported\n"
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