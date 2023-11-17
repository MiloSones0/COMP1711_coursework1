#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
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

int total_records(FILE * file);

int menu(FILE * file);

int fewest_steps(FILE * file);

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

#endif // FITNESS_DATA_STRUCT_H