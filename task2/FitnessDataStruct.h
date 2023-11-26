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

typedef struct {
	int start;
	int length;
} longestBlock;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);
void gatherData(FITNESS_DATA * fitnessDataArray,ANALYSED_DATA *data, int lines);
longestBlock longestPeriod(FITNESS_DATA * fitnessDataArray, int lines);
int open_file(FITNESS_DATA * fitnessDataArray);


#endif // FITNESS_DATA_STRUCT_H