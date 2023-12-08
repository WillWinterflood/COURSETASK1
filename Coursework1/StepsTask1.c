#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
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
 
// Complete the main function
int main() {
    int Records_Counter = 0;
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

    while (fgets(read, buffer, file) != NULL) {

        Records_Counter = Records_Counter + 1;
        //Counts how many lines there are in a file and increments 
        // the record counter by one for every line 
        

    }
    printf("Number of records in file: %d\n", Records_Counter);
    //Printing the records counter
    rewind(file);
    // The while loop doesnt reset the file meaning we have to go back up to the top
    // rewind does this for us
    FITNESS_DATA FitnessFile[Records_Counter];
    int x = 0;
    while (fgets(read, buffer, file) != NULL) {

        char CSteps[6];
        // tokenise only works with chracters therefore temporarily letting it become
        // a character so then turn it back to an integer
        tokeniseRecord(read, ',', FitnessFile[x].date, FitnessFile[x].time, CSteps);
        // makes an array
        
        int steps;
        
        sscanf(CSteps, "%d", &steps);
        //Converting CSteps back into steps (integer), to thhen be 
        // stored in the array

        FitnessFile[x].steps = steps;
        x++;
        

    }
    for (int x = 0; x < 3 && x < Records_Counter; x++) {
        //this increments x, which prints output less than 3 and the records counter,
        // and increments after every line is finished 
        printf("%s/%s/%d\n", FitnessFile[x].date, FitnessFile[x].time, FitnessFile[x].steps);

    }
    fclose(file);
    // closing the file to avoid memory leaks 

    return 0;





    

        
    

}
            

