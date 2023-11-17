#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define buffer_size 100
#define dataArray_size 500


// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
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




// int total_records(FITNESS_DATA *data) {
//     // add error checking for file probably in seperate function.
//     // change to use open_file func at some point
//     char line_buffer[buffer_size];
//     int total_records = 0;
//     for (int i = 0; i < dataArray_size; i++){
//         continue;
//     }
//     return total_records;
// }

int menu(FILE * file);

int fewest_steps(FILE * file);


/**
 * @brief Prompts the user for a file name, opens said file and save to an array
 * @param fitnessDataArray The array that is updated with data inside file
 * @returns number of lines in the file as int or 0 if error opening file
 */

int open_file(FITNESS_DATA * fitnessDataArray) {
    char filename[50];
	char line[buffer_size];
	int linesCounter;
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

#endif // FITNESS_DATA_STRUCT_H