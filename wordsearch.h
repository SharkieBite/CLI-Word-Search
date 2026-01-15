//Defines a constant variable that will never change throughout the program, representing the bytes of a string cell in the final array
#define ELEMENT_SIZE 20

//Declares the functions as a prototypes
void find(char ***colouredWordGrid, char **userWordFind, int numberOfWords, int numberOfRows, int numberOfColumns, char **wordGrid);
char*** copy(int numberOfRows, int numberOfColumns, char **wordGrid);
void markFoundLetter(char ***colouredWordGrid, int currentRow, int currentColumn, char originalCharacter);
void output(char ***colouredWordGrid, int numberOfRows, int numberOfColumns);
void checkHorizontalWord(char ***colouredWordGrid, char **wordGrid, const char *checkingWord, int numberOfRows, int numberOfColumns);
void checkVerticalWord(char ***colouredWordGrid, char **wordGrid, const char *checkingWord, int numberOfRows, int numberOfColumns);
void checkDiagonalWord(char ***colouredWordGrid, char **wordGrid, const char *checkingWord, int numberOfRows, int numberOfColumns);
char** read(FILE *currentInput, int *numberOfRows, int *numberOfColumns, char ***userWordFind, int *numberOfSearchWords);
void displayUsage(const char *errorMessage, bool displayUsage);
void displayHelp();