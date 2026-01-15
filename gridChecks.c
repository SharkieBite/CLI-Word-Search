/* Michael Mondaini, 400591695, November 20th, 2025
*
* Description: Contains the program that deals with checking the word grids for word matches. This file is coded in C.
*/

//Imports the necessary modules needed for the program
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "wordsearch.h"

//Defines a function which handles finding the user's search word in the word grid, and returns nothing
void find(char ***colouredWordGrid, char **userWordFind, int numberOfWords, int numberOfRows, int numberOfColumns, char **wordGrid) {

    //Defines a for loop that loops through the number of words, the user has passed
    for (int i = 0; i < numberOfWords; i++) {

        //Defines the current checking word to be the current iteration element in the user word find array
        char *checkingWord = userWordFind[i];

        //Calls the respective functions to check if the word is located in a multitude of different directions
        checkHorizontalWord(colouredWordGrid, wordGrid, checkingWord, numberOfRows, numberOfColumns);
        checkVerticalWord(colouredWordGrid, wordGrid, checkingWord, numberOfRows, numberOfColumns);
        checkDiagonalWord(colouredWordGrid, wordGrid, checkingWord, numberOfRows, numberOfColumns);
    }

    //Calls the output function to output the final coloured grid, with the words the user has searched
    output(colouredWordGrid, numberOfRows, numberOfColumns);
}

//Defines a function which handles checking if there are any matches for a word in the horizontal direction, and returns nothing
void checkHorizontalWord(char ***colouredWordGrid, char **wordGrid, const char *checkingWord, int numberOfRows, int numberOfColumns) {

    //Defines and initializes variables used later in the program
    int currentlyCorrect = true;
    int wordLength = strlen(checkingWord);
    int currentRow, currentColumn, currentFindingLetter;

    //Defines a for loop that loops through the number of rows
    for (currentRow = 0; currentRow < numberOfRows; currentRow++) { 

        //Defines a for loop that loops through the number of columns
        for (currentColumn = 0; currentColumn <= numberOfColumns - wordLength; currentColumn++) {

            //Sets the word currently correct variable to true after looping through the current finding word
            currentlyCorrect = true;

            //Defines a for loop that loops through the number of characters in the current finding word
            for (currentFindingLetter = 0; currentFindingLetter < wordLength; currentFindingLetter++) {

                //Determines if the current letter in the finding word is not equal to the letter in the grid, for the forwards direction
                if (tolower(checkingWord[currentFindingLetter]) != tolower(wordGrid[currentRow][currentColumn + currentFindingLetter])) {
                    
                    //Sets the currently correct variable to false and breaks out of the loop
                    currentlyCorrect = false;
                    break;
                }
            }

            //Determines if the currently correct variable is true, meaning the word was found in the grid
            if (currentlyCorrect) {

                //Defines a for loop that loops through the number of characters in the current finding word
                for (currentFindingLetter = 0; currentFindingLetter < wordLength; currentFindingLetter++) {

                    //Calls the mark found letter function to mark the letters in the grid as correct
                    markFoundLetter(colouredWordGrid, currentRow, currentColumn + currentFindingLetter, wordGrid[currentRow][currentColumn + currentFindingLetter]);
                }
            }
        }
    }

    //Defines a for loop that loops through the number of rows
    for (currentRow = 0; currentRow < numberOfRows; currentRow++) {

        //Defines a for loop that loops through the number of columns
        for (currentColumn = wordLength - 1; currentColumn < numberOfColumns; currentColumn++) {

            //Sets the word currently correct variable to true after looping through the current finding word
            currentlyCorrect = true;

            //Defines a for loop that loops through the number of characters in the current finding word
            for (currentFindingLetter = 0; currentFindingLetter < wordLength; currentFindingLetter++) {

                //Determines if the current letter in the finding word is not equal to the letter in the grid, for the backwards direction
                if (tolower(checkingWord[currentFindingLetter]) != tolower(wordGrid[currentRow][currentColumn - currentFindingLetter])) {

                    //Sets the currently correct variable to false and breaks out of the loop
                    currentlyCorrect = false;
                    break;
                }
            }

            //Determines if the currently correct variable is true, meaning the word was found in the grid
            if (currentlyCorrect) {

                //Defines a for loop that loops through the number of characters in the current finding word
                for (currentFindingLetter = 0; currentFindingLetter < wordLength; currentFindingLetter++) {

                    //Calls the mark found letter function to mark the letters in the grid as correct
                    markFoundLetter(colouredWordGrid, currentRow, currentColumn - currentFindingLetter, wordGrid[currentRow][currentColumn - currentFindingLetter]);
                }
            }
        }
    }
}

//Defines a function which handles checking if there are any matches for a word in the vertical direction, and returns nothing
void checkVerticalWord(char ***colouredWordGrid, char **wordGrid, const char *checkingWord, int numberOfRows, int numberOfColumns) {

    //Defines and initializes variables used later in the program
    int currentlyCorrect = true;
    int wordLength = strlen(checkingWord);
    int currentRow, currentColumn, currentFindingLetter;

    //Defines a for loop that loops through the number of columns
    for (currentColumn = 0; currentColumn < numberOfColumns; currentColumn++) {

        //Defines a for loop that loops through the number of rows
        for (currentRow = 0; currentRow <= numberOfRows - wordLength; currentRow++) {

            //Sets the word currently correct variable to true after looping through the current finding word
            currentlyCorrect = true;

            //Defines a for loop that loops through the number of characters in the current finding word
            for (currentFindingLetter = 0; currentFindingLetter < wordLength; currentFindingLetter++) {

                //Determines if the current letter in the finding word is not equal to the letter in the grid, for the forwards direction
                if (tolower(checkingWord[currentFindingLetter]) != tolower(wordGrid[currentRow + currentFindingLetter][currentColumn])) {
                    
                    //Sets the currently correct variable to false and breaks out of the loop
                    currentlyCorrect = false;
                    break;
                }
            }

            //Determines if the currently correct variable is true, meaning the word was found in the grid
            if (currentlyCorrect) {

                //Defines a for loop that loops through the number of characters in the current finding word
                for (int currentFindingLetter = 0; currentFindingLetter < wordLength; currentFindingLetter++) {

                    //Calls the mark found letter function to mark the letters in the grid as correct
                    markFoundLetter(colouredWordGrid, currentRow + currentFindingLetter, currentColumn, wordGrid[currentRow + currentFindingLetter][currentColumn]);
                }
            }
        }
    }

    //Defines a for loop that loops through the number of columns
    for (currentColumn = 0; currentColumn < numberOfColumns; currentColumn++) {

        //Defines a for loop that loops through the number of rows
        for (currentRow = wordLength - 1; currentRow < numberOfRows; currentRow++) {

            //Sets the word currently correct variable to true after looping through the current finding word
            currentlyCorrect = true;

            //Defines a for loop that loops through the number of characters in the current finding word
            for (currentFindingLetter = 0; currentFindingLetter < wordLength; currentFindingLetter++) {

                //Determines if the current letter in the finding word is not equal to the letter in the grid, for the backwards direction
                if (tolower(checkingWord[currentFindingLetter]) != tolower(wordGrid[currentRow - currentFindingLetter][currentColumn])) {

                    //Sets the currently correct variable to false and breaks out of the loop
                    currentlyCorrect = false;
                    break;
                }
            }

            //Determines if the currently correct variable is true, meaning the word was found in the grid
            if (currentlyCorrect) {

                //Defines a for loop that loops through the number of characters in the current finding word
                for (currentFindingLetter = 0; currentFindingLetter < wordLength; currentFindingLetter++) {

                    //Calls the mark found letter function to mark the letters in the grid as correct
                    markFoundLetter(colouredWordGrid, currentRow - currentFindingLetter, currentColumn, wordGrid[currentRow - currentFindingLetter][currentColumn]);
                }
            }
        }
    }
}

//Defines a function which handles checking if there are any matches for a word in the diagonal direction, and returns nothing
void checkDiagonalWord(char ***colouredWordGrid, char **wordGrid, const char *checkingWord, int numberOfRows, int numberOfColumns) {

    //Defines and initializes variables used later in the program
    int currentlyCorrectForward = true;
    int currentlyCorrectBackward = true;
    int wordLength = strlen(checkingWord);
    int currentRow, currentColumn, currentFindingLetter;

    //Defines a for loop that loops through the number of rows
    for (int currentRow = 0; currentRow < numberOfRows; currentRow++) {

        //Defines a for loop that loops through the number of columns
        for (int currentColumn = 0; currentColumn < numberOfColumns; currentColumn++) {
            
            //Determines if with the current row and current column, if the correct word is going to fit
            if (currentRow + wordLength <= numberOfRows && currentColumn + wordLength <= numberOfColumns) {
                
                //Sets the word currently correct variable to true after looping through the current finding word
                bool currentlyCorrectForward = true;

                //Defines a for loop that loops through the number of characters in the current finding word
                for (int currentFindingLetter = 0; currentFindingLetter < wordLength; currentFindingLetter++) {
                    
                    //Determines if the current letter in the finding word is not equal to the letter in the grid, for the down direction
                    if (tolower(wordGrid[currentRow + currentFindingLetter][currentColumn + currentFindingLetter]) != tolower(checkingWord[currentFindingLetter])) {
                        
                        //Sets the currently correct variable to false and breaks out of the loop
                        currentlyCorrectForward = false;
                        break;
                    }
                }

                //Determines if the currently correct variable is true, meaning the word was found in the grid
                if (currentlyCorrectForward) {

                    //Defines a for loop that loops through the number of characters in the current finding word
                    for (int currentFindingLetter = 0; currentFindingLetter < wordLength; currentFindingLetter++) {

                        //Calls the mark found letter function to mark the letters in the grid as correct
                        markFoundLetter(colouredWordGrid, currentRow + currentFindingLetter, currentColumn + currentFindingLetter, wordGrid[currentRow + currentFindingLetter][currentColumn + currentFindingLetter]);
                    }
                }
                
                //Sets the word currently correct variable to true after looping through the current finding word
                bool currentlyCorrectBackward = true;

                //Defines a for loop that loops through the number of characters in the current finding word
                for (int currentFindingLetter = 0; currentFindingLetter < wordLength; currentFindingLetter++) {
                    
                    //Determines if the current letter in the finding word is not equal to the letter in the grid, for the up direction
                    if (tolower(wordGrid[currentRow + currentFindingLetter][currentColumn + currentFindingLetter]) != tolower(checkingWord[wordLength - 1 - currentFindingLetter])) {
                        
                        //Sets the currently correct variable to false and breaks out of the loop
                        currentlyCorrectBackward = false;
                        break;
                    }
                }

                //Determines if the currently correct variable is true, meaning the word was found in the grid
                if (currentlyCorrectBackward) {
                    
                    //Defines a for loop that loops through the number of characters in the current finding word
                    for (int currentFindingLetter = 0; currentFindingLetter < wordLength; currentFindingLetter++) {

                        //Calls the mark found letter function to mark the letters in the grid as correct
                        markFoundLetter(colouredWordGrid, currentRow + currentFindingLetter, currentColumn + currentFindingLetter, wordGrid[currentRow + currentFindingLetter][currentColumn + currentFindingLetter]);
                    }
                }
            }
        }
    }

    //Defines a for loop that loops through the number of rows
    for (int currentRow = 0; currentRow < numberOfRows; currentRow++) {

        //Defines a for loop that loops through the number of columns
        for (int currentColumn = 0; currentColumn < numberOfColumns; currentColumn++) {
            
            //Determines if with the current row and current column, if the correct word is going to fit
            if (currentRow + wordLength <= numberOfRows && currentColumn >= wordLength - 1) {
                
                //Sets the word currently correct variable to true after looping through the current finding word
                bool currentlyCorrectForward = true;

                //Defines a for loop that loops through the number of characters in the current finding word
                for (int currentFindingLetter = 0; currentFindingLetter < wordLength; currentFindingLetter++) {
                    
                    //Determines if the current letter in the finding word is not equal to the letter in the grid, for the upwards direction
                    if (tolower(wordGrid[currentRow + currentFindingLetter][currentColumn - currentFindingLetter]) != tolower(checkingWord[currentFindingLetter])) {
                        
                        //Sets the currently correct variable to false and breaks out of the loop
                        currentlyCorrectForward = false;
                        break;
                    }
                }

                //Determines if the currently correct variable is true, meaning the word was found in the grid
                if (currentlyCorrectForward) {

                    //Defines a for loop that loops through the number of characters in the current finding word
                    for (int currentFindingLetter = 0; currentFindingLetter < wordLength; currentFindingLetter++) {

                        //Calls the mark found letter function to mark the letters in the grid as correct
                        markFoundLetter(colouredWordGrid, currentRow + currentFindingLetter, currentColumn - currentFindingLetter, wordGrid[currentRow + currentFindingLetter][currentColumn - currentFindingLetter]);
                    }
                }
                
                //Sets the word currently correct variable to true after looping through the current finding word
                bool currentlyCorrectBackward = true;

                //Defines a for loop that loops through the number of characters in the current finding word
                for (int currentFindingLetter = 0; currentFindingLetter < wordLength; currentFindingLetter++) {

                    //Determines if the current letter in the finding word is not equal to the letter in the grid, for the downwards direction
                    if (tolower(wordGrid[currentRow + currentFindingLetter][currentColumn - currentFindingLetter]) != tolower(checkingWord[wordLength - 1 - currentFindingLetter])) {
                        
                        //Sets the currently correct variable to false and breaks out of the loop
                        currentlyCorrectBackward = false;
                        break;
                    }
                }

                //Determines if the currently correct variable is true, meaning the word was found in the grid
                if (currentlyCorrectBackward) {
                    
                    //Defines a for loop that loops through the number of characters in the current finding word
                    for (int currentFindingLetter = 0; currentFindingLetter < wordLength; currentFindingLetter++) {

                        //Calls the mark found letter function to mark the letters in the grid as correct
                        markFoundLetter(colouredWordGrid, currentRow + currentFindingLetter, currentColumn - currentFindingLetter, wordGrid[currentRow + currentFindingLetter][currentColumn - currentFindingLetter]);
                    }
                }
            }
        }
    }
}