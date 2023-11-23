#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
char FileName[1000];
int buffer_size = 1000;
int Records_Counter = 0;
FILE *file;
int MinSteps = 9999999;
char minTime[6];
char minDate[11];
int MaxSteps = -1;
//DECLARING MOST OF MY VARIABLES HERE MEANING THEY ARE GLOBAL AND CAN BE USED IN THE SWITCH FUNCTION




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

    char line[buffer_size];
    char filename[buffer_size];
    char choice;

    // get filename from the user
    

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.   

    

    while (1)
    {
        printf("Menu Options:\n");
        
        printf("A: Specify the filename to be imported - you need to check that the file opened correctly.\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the data and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit\n");
        printf("Enter Choice: ");
        scanf(" %c", &choice);
        getchar();



        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            printf("Input Filename: ");
            scanf("%s", FileName);
            file = fopen(FileName, "r");
            if (file == NULL) {
                perror("Error: could not find or open the file. \n");
                return 1;

            }
            printf("File successfully loaded.\n");
            fclose(file);
            break;

        case 'B':
        case 'b':
            Records_Counter = 0;
            file = fopen(FileName, "r");
            if (file == NULL) {
                perror("Error: Could not open the file. \n");
                return 1;
            
            }
            //Already defined records counter in the global variables bit.
            while (fgets(line, buffer_size, file) != NULL) {

                Records_Counter = Records_Counter + 1;
                //Counts how many lines there are in a file and increments 
                // the record counter by one for every line 
            }
            printf("Number of records in file: %d\n", Records_Counter);
            //Printing the records counter
            fclose(file);
            break; 

        case 'C':
        case 'c':
            file = fopen(FileName,"r");
            if (file == NULL) {

                perror("Error: Could not open the file");
                return 1;
            }
            
            FITNESS_DATA listofffitnessdata[500];
            FITNESS_DATA loweststeps;
            int count = 0;

            while (fgets(line,buffer_size,file) != NULL) {
                int CurrentSteps[1000];

                char date[11];
                char time[6];
                char steps[100];
                //Declaring them all as characters as this means that you can append them to a list
                tokeniseRecord(line,",", date, time, steps);
                
                CurrentSteps[count] = atoi(steps);

               
                
                if (CurrentSteps[count] < MinSteps) {
                    MinSteps = CurrentSteps[count];
                    strcpy(minDate, date);
                    strcpy(minTime, time);
                    
                     
                }
            }
            printf("Fewest steps: %s %s\n", minDate, minTime);
            
            break;

        case 'D':
        case 'd':
            file = fopen(FileName,"r");
            if (file == NULL) {

                perror("Error: Could not open the file");
                return 1;
            }
            
            count = count*0;

            while (fgets(line,buffer_size,file) != NULL) {
                int CurrentSteps[1000];

                char date[11];
                char time[6];
                char steps[100];
                //Declaring them all as characters as this means that you can append them to a list
                tokeniseRecord(line,",", date, time, steps);
                
                CurrentSteps[count] = atoi(steps);

               
                
                if (CurrentSteps[count] > MaxSteps) {
                    MaxSteps = CurrentSteps[count];
                    strcpy(minDate, date);
                    strcpy(minTime, time);
                    
                     
                }
            }
            printf("Most steps: %s %s\n", minDate, minTime);
            break;

        case 'E':
        case 'e':
            file = fopen(FileName,"r");
            if (file == NULL) {

                perror("Error: Could not open the file");
                return 1;
            }
            
            char date[11];
            char time[6];
            char steps_char[1000];
            int steps[1000];
            int meansteps;
            int sumsteps;
            int linecount = 0;

            while (fgets(line,buffer_size,file) != NULL) {
                linecount = linecount + 1;
                tokeniseRecord(line, ",", date, time, steps_char);
                steps[linecount] = atoi(steps_char);
                sumsteps += steps[linecount];
            }
            meansteps = sumsteps / linecount;
            printf("%d\n", meansteps);  
            break;

        case 'F':
        case 'f':
            file = fopen(FileName,"r");
            if (file == NULL) {

                perror("Error: Could not open the file");
                return 1;
            }
            int fivecount = 0;
            int steps1;
            int secondcounter = 0;
            char startdate[11];
            char enddate[11];
            char currentstartdate[11];
            char currentenddate[11];
            while (fgets(line,buffer_size,file) != NULL) {
                steps1 = atoi(steps_char);

                if (steps1 > 500) {
                    if (fivecount > 0) {
                        //strcpy(currentenddate, currentstartdate);
                        fivecount = fivecount + 1;

                    }
                    else {
                        strcpy(currentstartdate, date);
                        fivecount = fivecount + 1;
                    }
                }
                
                else {
                    strcpy(currentenddate, date);
                    if (secondcounter > fivecount) {
                        secondcounter = secondcounter;
                    }
                    else {
                        secondcounter = fivecount;
                        strcpy(startdate, currentstartdate);
                        strcpy(enddate, currentenddate);
                    }
                }

            }
                
            printf("Longest period start date: %s\n", startdate);
            printf("Longest period end date: %s\n", enddate);
                
                
                
                
                
                
                
                
                
                
                /*tokeniseRecord(line, ",", date, time, steps_char);
                steps[fivecount] = atoi(steps_char);
                while (steps[fivecount] > 500) {
                    fivecount = fivecount + 1;
                    if (fivecount > secondcounter) {
                        secondcounter = fivecount;
                        fivecount = 0;
                    }
                    else {
                        fivecount = 0;
                    }
                }
            }
            fclose(file);
            printf("%d\n", secondcounter);*/
            break;

        case 'Q':
        case 'q':
        return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
}
  










    

     



