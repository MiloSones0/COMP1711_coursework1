#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

#define buffer_size 100
#define filename_size 50

char isNotNumber(char * number);
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps);
int open_file(FitnessData * fitnessDataArray, char filename[filename_size]);
void sort(FitnessData * data, int lines);
int validate(FitnessData * data, int lines);
void write_file(FitnessData * data, int lines, char filename[filename_size]);


int main() {
    char filename[filename_size];
    FitnessData data[500] = {};
    int lines = open_file(data,filename);
    if (lines == 0){
        exit(1);
    }
    // // validate returns 1 if data is invalid and 0 if it is valid
    // if (validate(data, lines)) {
    //     exit(1);
    // }
    sort(data, lines);
    write_file(data, lines, filename);
}

void sort(FitnessData * data, int lines) {
    for (int j = 0; j < lines -1; j ++) {
        for (int i = 0; i < lines - 1; i ++) {
            FitnessData temp;
            if(data[i].steps < data[i+1].steps) {
                temp = data[i+1];
                data[i+1] = data[i];
                data[i] = temp;
            }
        }
    }
}

int open_file(FitnessData * fitnessDataArray, char filename[filename_size]) {
	char line[buffer_size];
	int linesCounter = 0;
    printf("Enter Filename: ");
    scanf("%s", filename); 
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Could not find or open the file.\n");
        return 0;
    }
	while (fgets(line, buffer_size, file)){
		tokeniseRecord(line, ',', fitnessDataArray[linesCounter].date, fitnessDataArray[linesCounter].time, &fitnessDataArray[linesCounter].steps);
		linesCounter ++;
	}
    return linesCounter;
}

void write_file(FitnessData * data, int lines, char filename[filename_size]) {
    strcat(filename, ".tsv");
    FILE * file = fopen(filename, "w");
    for (int i = 0; i < lines; i ++) {
        fprintf(file, "%s\t%s\t%i\n", data[i].date, data[i].time, data[i].steps);
    }
}

// returns 1 if not a number
char isNotNumber(char * number) {
    int i = 0;
    if(number[0] == '\r') return 1;
    while(number[i] != '\r') {
        if (number[i] < 48 || number[i] > 57){printf("\n\n"); return 1;}
        i++;
    }
    printf("\n");
    return 0;
    
}

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        // check if prt meets the pattern of date
        // int year, month, day;
        // sscanf(ptr, "%d-%d-%d", &year, &month, &day);
        // printf("%d %d %d\n", year, month, day);       
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            int hour, min;
            sscanf(ptr, "%d:%d", &hour, &min);
            if (hour < 0 || hour > 24 || min > 60 || min < 0) {
                printf("Invalid data in time column\n");
                exit(1);
            }
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                // check if prt meets the pattern of steps
                if (isNotNumber(ptr)) {
                    printf("Invalid data in steps column\n");
                    exit(1);
                }
                *steps = atoi(ptr);
            } else {printf("Missing data\n");exit(1);}
        }
    } 
}
/*
Run the program:
================
./FitnessDataSorterExpected 
Output on Screen
=========================
Enter Filename: FitnessData_2023.csv
Data sorted and written to FitnessData_2023.csv.tsv
We then expect to see a file called: FitnessData_2023.csv.tsv
Written out to the same directory your code is in
*/

/*
Your program should:
When you run your program, it should:
1. Ask the user for a filename.
Enter filename:
1. Your program should ensure that the filename provided is a valid file (able to be opened by C), and
that all of the data inside the file is in the correct format (for example, 12-15-2023,,200 would be
invalid as the time is missing). If the file does not exist or if it contains invalid data, your program
should give a suitable error message, return 1, and exit:
Error: invalid file
2. If the file exists then your program should read the file into an array, and sort the data in descending
order of steps (highest number of steps at the top, smallest number at the bottom). If two records
have the same step count, these should be consecutive but the order does not matter.
3. Write out the sorted data file with the same filename, but with the file extension .tsv added to it.
Once this is complete, return 0 to exit successfully.
If the input file is:
mydata.csv
2023-12-30,09:30,598
2023-12-30,09:45,376
2023-12-30,10:00,521
The output file will be:
mydata.csv.tsv
2023-12-30 09:30 598
2023-12-30 10:00 521
2023-12-30 09:45 376
(Note that the spaces are \t characters)
How it will be marked:
1. Providing the menu option and coping with an incorrect filename: 5 marks
2. Coping with an incorrectly formatted file (the fields in the wrong order): 5 marks
3. Creating an output file in the correct format: 5 marks
Note that the auto-grader expects the program in exactly this structure- it will enter a filename and expect
the program to run without needing any further input.
*/