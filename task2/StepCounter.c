#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char filename[50]; 
    char input[1];
    printf("A: Specify the filename to be imported\n"
        "B: Display the total number of records in the file\n"
        "C: Find the date and time of the timeslot with the fewest steps\n"
        "D: Find the data and time of the timeslot with the largest number of steps\n"
        "E: Find the mean step count of all the records in the file\n"
        "F: Find the longest continuous period where the step count is above 500 steps\n"
        "Q: Quit\n");

    scanf("%s", input);
    if(!strcmp(input, "A")) {
        printf("Input filename:");
        scanf("%s", filename);

    }
    else if(!strcmp(input, "B")) {
        printf("Total records: %d", total_records(filename));

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
    return 0;
}


int total_records(char filename[50]) {
    // add error checking for file probably in seperate function.
    int buffer_size = 100;
    char line_buffer[buffer_size];
    int total_records = 0;
    FILE *file = fopen (filename, "a+");
    while (fgets(line_buffer, buffer_size, file)) {
        total_records ++;
    }
    fclose(file);
    return total_records;
}