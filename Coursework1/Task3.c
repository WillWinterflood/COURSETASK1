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
//Void function is outside the main function to ensure that the qsort works and the steps are organised in descending order 
int CompareSteps(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);  
}



int main() {
    int buffer = 250;
    //Max characters in each line 
    char read[buffer];
    // stores each line that will be read from the file 
    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    // opens the file and reads it only 
    if (file == NULL) {
        // handles error
        perror("");
        return 1;
        // if file cannot be opened, it returns 1 and prints ""
    }
    int x = 0;
    FitnessData FitnessFile[x];
    while (fgets(read, buffer, file) != NULL) {
        char CSteps[6];
        // tokenise only works with chracters therefore temporarily letting it become
        // a character so then turn it back to an integer
        tokeniseRecord(read, ",", FitnessFile[x].date, FitnessFile[x].time, CSteps);
        // makes an array
        int steps;
        sscanf(CSteps, "%d", &steps);
        //Converting CSteps back into steps (integer), to then be 
        // stored in the array

        FitnessFile[x].steps = steps;
        x++;
    }
    fclose(file);
    qsort(FitnessFile, x, sizeof(FitnessData), CompareSteps);
    for (int i = 0; i < x; i++) {
        printf("%d", FitnessFile[i].steps);
    }
      
}










/*int count = 0;
int MaxSteps = -1;
int CurrentSteps[1000];
int buffer = 250;
int buffer_size[1000];
char line[buffer];
FILE* NewFile;
char NewFilename[] = "FitnessData_2023.csv.tsv";

char FileName[] = "FitnessData_2023.csv";

printf("Input Filename: ");
scanf("%s", FileName);
FILE* file = fopen(FileName, "r");
if (file == NULL) {
perror("Error: could not find or open the file. \n");
// Error message.
return 1;

}
printf("File successfully loaded.\n");

while(fgets(line, buffer, file) != NULL) {

char date[11];
char time[6];
char steps[100];
int arr[];
int *size;
//Declaring them all as characters as this means that you can append them to a list
tokeniseRecord(line,",", date, time, steps);
    
CurrentSteps[count] = atoi(steps);
// changing steps into Currentsteps[count] which changes a chraracter into an integer 

    
for (i = *size - 1; i >= 0 && arr[i] < steps; i--) {
arr[i + 1] = arr[i];

}      
if (CurrentSteps[count] > MaxSteps) {
MaxSteps = CurrentSteps[count];
NewFile = fopen("%s", NewFilename);
if (NewFile != NULL) {
    fprintf("%s", line);
    
}
            
}

    }
*/




    
    
