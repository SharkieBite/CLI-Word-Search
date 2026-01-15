//Imports the necessary modules needed for the program
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "wordsearch.h"

//Declares the function that handles the program
int main(int argc, char *argv[]) {

    //Defines and initializes variables used later in the program
    char **wordGrid = NULL;
    char **userWordFind = NULL;
    int numberOfRows = 0;
    int numberOfColumns = 0;
    int numberOfSearchWords = 0;

    //Determines if the user entered three or more arguments
    if (argc > 3) {

        //Calls the usage function to output the error message along with a usage message, and exits
        displayUsage("", true);
    }

    //Determines if the user entered two arguments and the last argument was the help flag, using the string comparsion method
    else if (argc == 2 && strcmp(argv[1], "--help") == 0) {

        //Calls the display help function to output the necessary information
        displayHelp();
    }

    //Determines if the number of arugments passed through the program is greater than one
    else if (argc > 1) {
        
        //Sets the current input to the be the file passed in read mode
        FILE *currentInput = fopen(argv[1], "r");
        
        //Determines if the current input could not be read with the code zero
        if (currentInput == NULL) {
            
            //Calls the usage function to output the error message along with no usage message, and exits
            displayUsage("Error: File cannot be opened, please ensure this file exists", false);
        }

        //Sets the word grid to the user's file by calling the read function with the needed parameters
        wordGrid = read(currentInput, &numberOfRows, &numberOfColumns, &userWordFind, &numberOfSearchWords);
        
        //Closes the file when done
        fclose(currentInput);
    }

    //Defaults to this statement if the number of arguments passed is less than one
    else {

        //Sets the word grid to the user's input by calling the read function with the needed parameters
        wordGrid = read(stdin, &numberOfRows, &numberOfColumns, &userWordFind, &numberOfSearchWords);
    }

    //Defines the coloured word grid to be a string grid of the character grid by calling the copy function
    char ***colouredWordGrid = copy(numberOfRows, numberOfColumns, wordGrid);

    //Calls the find function to output the found words in the word grid from the given input
    find(colouredWordGrid, userWordFind, numberOfSearchWords, numberOfRows, numberOfColumns, wordGrid);

    //Defines a for loop that loops through the number of rows
    for (int i = 0; i < numberOfRows; i++) {

        //Defines a for loop that loops through the number of columns
        for (int j = 0; j < numberOfColumns; j++) {

            //Frees the current element for coloured word grid
            free(colouredWordGrid[i][j]);
        }

        //Frees the current coloured word grid row
        free(colouredWordGrid[i]);

        //Frees the current word grid
        free(wordGrid[i]);
    }

    //Defines a for loop that loops through the number of search words
    for (int i = 0; i < numberOfSearchWords; i++) {

        //Frees the current user word finds
        free(userWordFind[i]);
    }

    //Frees the pointers
    free(colouredWordGrid);
    free(wordGrid);
    free(userWordFind);

    return 0;
}
