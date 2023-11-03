int main() {
    int Records_Counter = 0;
    int buffer = 250;
    char line[buffer];
    char filename [] = "FitnessData.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        // handles error
        perror("");
        return 1;
    }

    while (fgets(line, buffer, file) != NULL) {

        Records_Counter = Records_Counter + 1;
        //Counts how many lines there are in a file and increments 
        // the record counter by one for every line 
        

    }
    printf("Number of records in file: %d\n", Records_Counter);
    //Printing the records counter
    rewind(file);
    // The while loop doesnt reset the file meaning we have to go back up to the top
    // rewind does this for us
    FitnessData FitnessFile[Records_Counter];
    int x = 0;
    while (fgets(line, buffer, file) != NULL) {

        char CSteps[6];
        // tokenise only works with chracters therefore temporarily letting it become
        // a character so then turn it back to an integer
        tokeniseRecord(line, ",", FitnessFile[x].date, FitnessFile[x].time, CSteps);
        
        int steps;
        
        sscanf(CSteps, "%d", &steps);
        FitnessFile[x].steps = steps;
        x++;

    }
    for (int x = 0; x < 3; x++);
        printf("%s/%s/%d\n", FitnessFile[x].date, FitnessFile[x].time, FitnessFile[x].steps);

    return 0;
