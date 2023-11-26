#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

int main() {
    FITNESS_DATA data[dataArray_size] = {};
    ANALYSED_DATA analysedData = {};
    char input;
    int lines;
    longestBlock block = {};
    while(1) {
        printf( "Menu Options:\n"
                "A: Specify the filename to be imported\n"
                "B: Display the total number of records in the file\n"
                "C: Find the date and time of the timeslot with the fewest steps\n"
                "D: Find the data and time of the timeslot with the largest number of steps\n"
                "E: Find the mean step count of all the records in the file\n"
                "F: Find the longest continuous period where the step count is above 500 steps\n"
                "Q: Quit\n");
        scanf(" %c", &input);
        switch (input)
        {
        case 'A':
        case 'a':; // weird not allowed to define a variable as the first thing you do so have to have a semi colon above.
            lines = open_file(data);

            if (lines == 0){
                exit(1);
            }
            printf("File successfully loaded.\n");
            gatherData(data,&analysedData,lines);
            break;
        case 'B':
        case 'b':
            printf("Total records: %d\n", lines);
            break;

        case 'C':
        case 'c':
            printf("%s\n", analysedData.fewestSteps);
            break;

        case 'D':
        case 'd':
            printf("%s\n", analysedData.largestSteps);
            break;

        case 'E':
        case 'e':
            printf("Mean step count: %d\n", analysedData.mean);
            break;

        case 'F':
        case 'f':
            block = longestPeriod(data, lines);
            printf("Longest period start: %s %s\n"
                    "Longest period end: %s %s\n",
                    data[block.start].date,
                    data[block.start].time,
                    data[block.start + block.length].date,
                    data[block.start + block.length].time);
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

void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

int open_file(FITNESS_DATA * fitnessDataArray) {
    char filename[50];
	char line[buffer_size];
	int linesCounter = 0;
    printf("Input filename: ");
    scanf("%s", filename); 
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Could not find or open the file.\n");
        return 0;
    }
	while (fgets(line, buffer_size, file)){
		char steps[8];
		tokeniseRecord(line, ",", fitnessDataArray[linesCounter].date, fitnessDataArray[linesCounter].time, steps);
		fitnessDataArray[linesCounter].steps = atoi(steps);
		linesCounter ++;
	}
    return linesCounter;
}

void gatherData(FITNESS_DATA * fitnessDataArray, ANALYSED_DATA *data, int lines) {
    int lowest = 0;
    int highest = 0;
    int sum = 0;
    for (int i = 0; i < lines; i++) { 
        if (fitnessDataArray[i].steps > highest) {
            highest = fitnessDataArray[i].steps;
            sprintf(data->largestSteps, "Largest steps: %s %s", fitnessDataArray[i].date,fitnessDataArray[i].time);
        }
        else {
            lowest = fitnessDataArray[i].steps;
            sprintf(data->fewestSteps, "Fewest steps: %s %s", fitnessDataArray[i].date,fitnessDataArray[i].time);
        }
        sum += fitnessDataArray[i].steps;
    }
    data->mean = sum/lines;
}

longestBlock longestPeriod(FITNESS_DATA * fitnessDataArray, int lines) {
    longestBlock block = {};
    int last = 0;
    int length = 0;
    for (int i = 0; i < lines; i++) {
        if (fitnessDataArray[i].steps < 500) {
            last = i;
            length = 0;
        } else {
            length ++;
        }
        if (length > block.length) {
            block.length = length;
            block.start = last + 1;
        }
    }
    return block;
}