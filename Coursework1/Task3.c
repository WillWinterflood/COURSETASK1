#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char tempsteps[1000];
    int count = 0;
    int steps;
    int n;
    FILE *OutputFile;
    char OutFilename[] = "FitnessData_2023.csv.tsv";


    //Open file
    printf("Enter Filename: ");
    scanf("%s", filename);
    FILE *inputfile = fopen(filename, "r"); //to read
    if (inputfile == NULL)
    {
        perror("");
        return 1;
    }

    int buffer[1000];
    char line_buffer[buffer];

    while (fgets(line_buffer, buffer, inputfile) != NULL) //loop through the csv record by record
    {
        tokeniseRecord(line_buffer, ",", tempdate, temptime, tempsteps);
        //copy all the temporary data from the cycle to the array of fitness_data whilst checking if NULL data then return 1
        tempsteps[count] = atoi(steps);

        
        count = count + 1;

    }


    InsertionSort(steps, n);

    printArray(steps, n);


    OutputFile = fopen(OutFilename, "w");

    if (OutFilename == NULL) {
        perror("Error opening and writing to file");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf(OutFilename, "%s %s %d", tempdate, temptime, steps);
    }


}