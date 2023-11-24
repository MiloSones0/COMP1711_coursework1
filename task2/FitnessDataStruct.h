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

typedef struct {
	int mean;
	char fewestSteps[50];
	char largestSteps[50];
	char startDate[50];
	char endDate[50];
} ANALYSED_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);
void gatherData(FITNESS_DATA * fitnessDataArray,ANALYSED_DATA *data, int lines);



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

int open_file(FITNESS_DATA * fitnessDataArray);
#endif // FITNESS_DATA_STRUCT_H