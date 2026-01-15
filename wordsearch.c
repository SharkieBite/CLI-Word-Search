//Imports the necessary modules needed for the program
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "wordsearch.h"

//Defines a function which handles reading the user's input or getting input from a file arugment, and returns an array containing the user's inputs
char** read(FILE *currentInput, int *numberOfRows, int *numberOfColumns, char ***userWordFind, int *numberOfSearchWords) {

    //Defines variables which will be used later in the program such as to store the search grid, or if the user is now entering search words
    char **wordGrid = NULL;
    bool enteringWordFinds = false;
    
    //Defines variables which initialize character array used later in the program
    char currentWord[256];

    //Defines a variable to read characters and track the position in the current row
    char currentCharacter; 
    int positionInRow = 0; 

    //Sets the number of rows and search words first element in the pointer to zero, as they are being cleared
    *numberOfRows = 0;
    *numberOfSearchWords = 0;

    //Determines if the current input is not a integer giving a value via scanf not equal to one
    if (fscanf(currentInput, "%d", numberOfColumns) != 1) {

        //Calls the usage function to output the error message along with no usage message, and exits
        displayUsage("Error: Invalid file format, or missing column count", true);

    }

    //Determines if the current input is a integer less than or equal to zero for columns
    if (*numberOfColumns <= 0) {

        //Calls the usage function to output the error message along with no usage message, and exits
        displayUsage("Error: Invalid count of columns", true);
    }

    //Defines word grid to allocate memory for a pointer of a character
    wordGrid = (char**)malloc(sizeof(char*));

    //Determines if the memory allocation failed
    if (wordGrid == NULL) {

        //Calls the usage function to output the error message along with no usage message, and exits
        displayUsage("Error: Memory allocation failed", false);
    }

    //Defines word grid to allocate memory for the entire row
    wordGrid[0] = (char*)malloc(*numberOfColumns + 1);

    //Determines if the memory allocation failed
    if (wordGrid[0] == NULL) {

        //Calls the usage function to output the error message along with no usage message, and exits
        displayUsage("Error: Memory allocation failed", false);
    }

    //Defines a while loop that reads every iteration and loops until it reaches a EOF, or until the loop is broken
    while (fscanf(currentInput, " %currentCharacter", &currentCharacter) == 1) {

        //Determines if the current line is a equal sign
        if (currentCharacter == '=') {

            //Sets the entering word finds variable to true
            enteringWordFinds = true;
            wordGrid[*numberOfRows][positionInRow] = '\0';
            
            //Determines if the position current row is greater than zero
            if (positionInRow > 0) {

                //Adds one to the number of rows
                (*numberOfRows)++;
            }
            
            //Defaults to this statement if the current row is not greater than zero
            else {

                //Free the current row in memory
                free(wordGrid[*numberOfRows]);
            }

            //Breaks out of the current while loop
            break; 
        }

        //Sets the current element to be equal to the current character
        wordGrid[*numberOfRows][positionInRow] = currentCharacter;
        
        //Adds one to the position in the current row
        positionInRow++;

        //Determines if current position in the row is equal to the number of columns, meaning were at the end of the row
        if (positionInRow == *numberOfColumns) {

            //Sets the end of the row to have a null terminator
            wordGrid[*numberOfRows][positionInRow] = '\0';
            
            //Adds on to the number of rows
            (*numberOfRows)++;
            
            //Sets the position in the current row to index zero
            positionInRow = 0;

            //Sets the current word grid to reallocate it's memory by the new number of rows multipled by the size of a pointer to a character (Creates a new row)
            wordGrid = (char**)realloc(wordGrid, (*numberOfRows + 1) * sizeof(char *));

            //Determines if the memory allocation failed
            if (wordGrid == NULL) {

                //Calls the usage function to output the error message along with no usage message, and exits
                displayUsage("Error: Memory allocation failed", false);
            }
            
            //Defines the current row data to be made as a new allocation in memory, with the number of columns representing the number of characters in the row
            wordGrid[*numberOfRows] = (char*)malloc(*numberOfColumns + 1);
            
            //Determines if the memory allocation failed
            if (wordGrid[*numberOfRows] == NULL) {
                
                //Calls the usage function to output the error message along with no usage message, and exits
                displayUsage("Error: Memory allocation failed", false);
            }
        }
    }

    //Determines if the user reached EOF before inputting their find words
    if (!enteringWordFinds) {
        
        //Calls the usage function to output the error message along with a usage message, and exits
        displayUsage("Error: Reached end of file before '='", true);
    }

    //Determines if the entering word finds variable is true, if the user is entering word to search in the grid
    if (enteringWordFinds) {

        //Defines a while loop that loops over the current word inputted by the user using scanf
        while (scanf("%s", currentWord) == 1) {
            
            //Sets the words to fine to reallocate it's memory to increment it's size by one
            *userWordFind = (char**)realloc(*userWordFind, (*numberOfSearchWords + 1) * sizeof(char *));
            
            //Determines if the memory allocation failed
            if (*userWordFind == NULL) {
                
                //Calls the usage function to output the error message along with no usage message, and exits
                displayUsage("Error: Memory allocation failed", false);
            }

            //The new allocation to be made in memory, to hold the current word
            (*userWordFind)[*numberOfSearchWords] = (char*)malloc(strlen(currentWord) + 1);

            //Determines if the memory allocation failed
            if ((*userWordFind)[*numberOfSearchWords] == NULL) {
                
                //Calls the usage function to output the error message along with no usage message, and exits
                displayUsage("Error: Memory allocation failed", false);
            }

            //Copies the current word into the array of words to find
            strcpy((*userWordFind)[*numberOfSearchWords], currentWord);

            //Increases the number of search words value using the deference, by one
            (*numberOfSearchWords)++;
        }
    }

    //Returns the final word grid
    return wordGrid;
}

//Defines a function which handles copying a chracter array to be a string array, returns the new array
char*** copy(int numberOfRows, int numberOfColumns, char **wordGrid) {

    //Defines a new coloured array to allocate in memory the correct number of rows 
    char ***colouredWordGrid = (char***)malloc(numberOfRows * sizeof(char**));

    //Determines if the memory allocation failed
    if (colouredWordGrid == NULL) {
                
        //Calls the usage function to output the error message along with no usage message, and exits
        displayUsage("Error: Memory allocation failed", false);
    }

    //Defines a for loop that loops through the number of rows in the character array
    for (int i = 0; i < numberOfRows; i++) {
        
        //Sets the coloured array to allocate in memory the correct number of columns 
        colouredWordGrid[i] = (char**)malloc(numberOfColumns * sizeof(char*));

        //Determines if the memory allocation failed
        if (colouredWordGrid[i] == NULL) {
                    
            //Calls the usage function to output the error message along with no usage message, and exits
            displayUsage("Error: Memory allocation failed", false);
        }

        //Defines a for loop that loops through the number of columns in the character array
        for (int j = 0; j < numberOfColumns; j++) {
            
            //Sets the coloured array to allocate in memory the correct element size, to hold a chracter and the colouring format string, which is 20 bytes defined by the ELEMENT_SIZE
            colouredWordGrid[i][j] = (char*)malloc(ELEMENT_SIZE * sizeof(char));

            //Determines if the memory allocation failed
            if (colouredWordGrid[i][j] == NULL) {
                        
                //Calls the usage function to output the error message along with no usage message, and exits
                displayUsage("Error: Memory allocation failed", false);
            }

            //Copies the character from the wordGrid array to the new coloured array, to be a string
            colouredWordGrid[i][j][0] = wordGrid[i][j];

            //Sets the end to have a null terminator
            colouredWordGrid[i][j][1] = '\0';
        }
    }

    //Returns the final coloured array
    return colouredWordGrid;
}

//Defines a function which handles marking a current letter to be found using colour formatted strings, returns nothing
void markFoundLetter(char ***colouredWordGrid, int currentRow, int currentColumn, char originalCharacter) {

    //Defines a pointer to the current cell
    char *currentElement = colouredWordGrid[currentRow][currentColumn];

    //Copies the text formatting red string to the cell
    strcpy(currentElement, "\033[1;31m"); 

    //Defines the length of the element in the cell using the strlen function
    int elementLength = strlen(currentElement);    

    //Sets the originial character to be added with a null terminator
    currentElement[elementLength] = originalCharacter;    
    currentElement[elementLength + 1] = '\0';      

    //Adds the rest of the text formatting red string to the cell using the strcat function
    strcat(currentElement, "\033[0m");
}

//Defines a function which handles outputting the word grid to the user, and returns nothing
void output(char ***colouredWordGrid, int numberOfRows, int numberOfColumns) {

    //Defines a for loop that loops through the number of rows
    for (int i = 0; i < numberOfRows; i++) {

        //Defines a for loop that loops through the number of columns
        for (int j = 0; j < numberOfColumns; j++) {

            //Outputs the current element in the word grid
            printf("%s", colouredWordGrid[i][j]);
        }
    
        //Outputs a new character, once a entire row has be outputed
        printf("\n");
    }
}

//Defines a function which handles with outputting errors to standard error, taking two parameter input to function
void displayUsage(const char *errorMessage, bool displayUsage) {

    //Determines if the error message is not empty to output the message
    if (!(strcmp(errorMessage,"") == 0)) {

        //Outputs to the user the given error message given from parameters, to standard error
        fprintf(stderr, "%s\n", errorMessage);
    }

    //Determines if the usage error is needed to be outputted, using the value given in the parameters
    if (displayUsage) {

        //Outputs to the user the given usage message in parameters, to standard error
        fprintf(stderr, "Usage: wordsearch [FILE]\n");
    }

    //Exits the program with a failure
    exit(EXIT_FAILURE);
}

//Defines a function which handles with outputting information about the utility, and exits after called
void displayHelp() {

    //Outputs to the user the necessary information about the utility, and then exits the program
    puts("The utility is a program that processes a two-dimensional grid of characters to search for hidden words.\nPlease see below the proper usage and syntax needed to run the program.\n---------------------------------------------------\nUsage: wordsearch [FILE]\n \n[FILE]: Argument represents the file name with extension, that the grid is made out of.\nwordsearch: Inputs first a number (Number of Columns), and then characters (Charcters in Grid), and then a equal sign and words (Words to Search)");
    exit(0);
}
