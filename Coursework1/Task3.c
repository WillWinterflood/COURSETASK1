#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defining new variables
#define MaxBufferLength 1000


// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}
void InsertionSort(int steps[], int n) {
    int i, key, j;
    for(i = 1; i < n; i++) {
        key = steps[i];
        j = i - 1; 

        while (j >= 0 && steps[j] > key) {
            steps[j + 1] = steps[j];
            j = j - 1;
        }
        steps[j + 1] = key;
    }
}
void printArray(int steps[], int size) { 
    int i;
    for (i = 0; i < size; i++) 
        printf("%d", steps[i]);
    printf("\n");
}


int main() {
    char filename[] = "FitnessData_2023.csv";


    char tempdate[11];
    char temptime[6];
    char tempsteps[MaxBufferLength];
    int count = 0;
    int steps;
    int n;
    int *StepPtr = &steps;
    FILE *OutputFile;
    char OutFilename[] = "FitnessData_2023.csv.tsv";


    //Open file
    printf("Enter Filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r"); //to read
    if (file == NULL)
    {
        perror("Invalid: Invalid File");
        return 1;
    }
    int buffer;
    char line_buffer[MaxBufferLength];

    while (fgets(line_buffer, MaxBufferLength, file) != NULL) //loop through the csv record by record
    {
        tokeniseRecord(line_buffer, ',', tempdate, temptime, StepPtr);
        //copy all the temporary data from the cycle to the array of fitness_data whilst checking if NULL data then return 1

        count = count + 1;

    }


    InsertionSort(StepPtr, count);

    printArray(StepPtr, count);


    OutputFile = fopen(OutFilename, "w");


    if (OutputFile == NULL) {
        perror("Error opening and writing to file");
        return 1;
    }
    else {
        printf("second file loaded.");
    }
    for (int i = 0; i < count; i++) {
        fprintf(OutputFile, "%s %s %d\n", tempdate, temptime, StepPtr[i]);
    }

    fclose(OutputFile);

    return 0;

}