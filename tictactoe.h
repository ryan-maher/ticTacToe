#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Helper functions

char displayCapitalXO(char letter){

    if(letter == 'o'){
        return 'O';
    } else{
        return 'X';
    }

}

// Asks for user to input 1 or 2, loops if something else is entered
int askUserInputNum12(){

    int inputInt;
    scanf("%d", &inputInt);

    if(inputInt == 2){
        return 2;
    }
    else if(inputInt == 1){
        return 1;
    } else{
        printf("Please enter either 1 or 2: ");
        return askUserInputNum12();
    }

}

// Asks for user to input 1, 2, or 3, loops if something else is entered
int askUserInputNum123(){

    int inputInt;
    scanf("%d", &inputInt);

    if(inputInt == 3){
        return 3;
    }
    else if(inputInt == 2){
        return 2;
    }
    else if(inputInt == 1){
        return 1;
    
    } else{
        printf("Please enter either 1, 2, or 3: ");
        return askUserInputNum123();
    }

}

// Asks for user to input x, X, o, or O, loops if something else is entered
char askUserInputXO(){

    char inputChar;
    scanf(" %c", &inputChar);

    if(inputChar == 'x' || inputChar == 'X'){
        return 'x';
    }else if(inputChar == 'o' || inputChar == 'O'){
        return 'o';
    } else{
        printf("Please enter either letter X or letter O.\n");
        return askUserInputXO();
    }

}

// Asks for user to input y, Y, n, or N, loops if something else is entered
char askUserInputYN(){

    char inputChar;
    scanf(" %c", &inputChar);

    if(inputChar == 'y' || inputChar == 'Y'){
        return 'y';
    }else if(inputChar == 'n' || inputChar == 'N'){
        return 'n';
    } else{
        printf("Please enter either letter y or letter n.\n");
        return askUserInputYN();
    }

}

// Prints the current tic tac toe table with marked positions
void printCurrentTable(char row1[], char row2[], char row3[]){

    printf("\n");
    printf("|");

    for(int i = 0; i < 3; i++){
        
        if(row1[i] == 'x'){
            printf(" X |");

        } else if (row1[i] == 'o'){
            printf(" O |");

        } else {
            printf(" - |");
        }
    }
    
    printf("\n-------------\n");
    printf("|");
    
    for(int i = 0; i < 3; i++){
        
        if(row2[i] == 'x'){
            printf(" X |");

        } else if (row2[i] == 'o'){
            printf(" O |");

        } else {
            printf(" - |");
        }
    }

    printf("\n-------------\n");
    printf("|");
    
    for(int i = 0; i < 3; i++){
        
        if(row3[i] == 'x'){
            printf(" X |");

        } else if (row3[i] == 'o'){
            printf(" O |");

        } else {
            printf(" - |");
        }
    }

    printf("\n\n");

}

// Prints tic tac toe table with numbered positions
void printTableStart(){
    
    printf("\n");
    printf("|");

    for(int i = 0; i < 3; i++){
        
        printf(" %i |", (i+1));
    }
    
    printf("\n-------------\n");
    printf("|");
    
    for(int i = 0; i < 3; i++){
        
        printf(" %i |", (i+4));
        
    }

    printf("\n-------------\n");
    printf("|");
    
    for(int i = 0; i < 3; i++){
        
        printf(" %i |", (i+7));

    }

    printf("\n");

}

// Asks user to input position from 1 to 9
// If position already taken, asks user to input another position
int askUserInputBoard(char row1[], char row2[], char row3[], char playerChar, int gamemode){

    int boardChoice;
    
    if(gamemode == 2){
        printf("[Player %c] ", displayCapitalXO(playerChar));
    }

    printf("Enter a position from 1 to 9: ");
    scanf("%i", &boardChoice);

    if(boardChoice < 1 || boardChoice > 9){
        
        if(gamemode == 2){
            printf("[Player %c] ", displayCapitalXO(playerChar));
        }

        printf("Please choose a number from 1 to 9.\n");
        askUserInputBoard(row1, row2, row3, playerChar, gamemode);
    
    } else{
        switch(boardChoice){
            case 1:
            if((char)row1[0] == (char)' '){
                (row1[0]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.\n", boardChoice, displayCapitalXO(row1[0]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;

            case 2:
            if((char)row1[1] == (char)' '){
                (row1[1]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.\n", boardChoice, displayCapitalXO(row1[1]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;

            case 3:
            if((char)row1[2] == (char)' '){
                (row1[2]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.\n", boardChoice, displayCapitalXO(row1[2]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;

            case 4:
            if((char)row2[0] == (char)' '){
                (row2[0]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.\n", boardChoice, displayCapitalXO(row2[0]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;

            case 5:
            if((char)row2[1] == (char)' '){
                (row2[1]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.\n", boardChoice, displayCapitalXO(row2[1]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;

            case 6:
            if((char)row2[2] == (char)' '){
                (row2[2]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.\n", boardChoice, displayCapitalXO(row2[2]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;

            case 7:
            if((char)row3[0] == (char)' '){
                (row3[0]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.\n", boardChoice, displayCapitalXO(row3[0]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;

            case 8:
            if((char)row3[1] == (char)' '){
                (row3[1]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.\n", boardChoice, displayCapitalXO(row3[1]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;

            case 9:
            if((char)row3[2] == (char)' '){
                (row3[2]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.\n", boardChoice, displayCapitalXO(row3[2]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;
        }
    }

}

// For the following three functions, the number of empty spots is returned for each row, column, and diagonal

int emptyRowCheck(char row[]){

    int emptyCheck = 0;
    for(int i = 0; i < 3; i++){
        if(row[i] == ' '){
            emptyCheck++;
        }
    }
    return emptyCheck;

}

int emptyColCheck(char row1[], char row2[], char row3[], int colNum){

    if(row1[colNum] != ' ' && row2[colNum] != ' ' && row3[colNum] != ' ')
    {    
        return 0;
    
    } else
    
    if( (row1[colNum] == ' ' && row2[colNum] != ' ' && row3[colNum] != ' ') 
     || (row1[colNum] != ' ' && row2[colNum] == ' ' && row3[colNum] != ' ')
     || (row1[colNum] != ' ' && row2[colNum] != ' ' && row3[colNum] == ' '))
    {
        return 1;

    } else 
    if((row1[colNum] == ' ' && row2[colNum] == ' ' && row3[colNum] != ' ') 
    || (row1[colNum] == ' ' && row2[colNum] != ' ' && row3[colNum] == ' ') 
    || (row1[colNum] != ' ' && row2[colNum] == ' ' && row3[colNum] == ' '))
    {    
        return 2;
    
    } else {

        return 3;
    
    }

}

int emptyDiagCheck(char row1[], char row2[], char row3[], int diagNum){

    // Top left to bottom right diagonal
    if(diagNum == 0){

        if(row1[0] != ' ' && row2[1] != ' ' && row3[2] != ' ')
        {
            return 0;
        
        } else
        
        if((row1[0] == ' ' && row2[1] != ' ' && row3[2] != ' ')
        || (row1[0] != ' ' && row2[1] == ' ' && row3[2] != ' ')
        || (row1[0] != ' ' && row2[1] != ' ' && row3[2] == ' '))
        {
        
            return 1;
        
        } else
        
        if((row1[0] == ' ' && row2[1] == ' ' && row3[2] != ' ')
        || (row1[0] == ' ' && row2[1] != ' ' && row3[2] == ' ')
        || (row1[0] != ' ' && row2[1] == ' ' && row3[2] == ' '))
        {
        
            return 2;
        
        } else {

            return 3;

        }

    // Top right to bottom left diagonal
    } else{

        if(row1[2] != ' ' && row2[1] != ' ' && row3[0] != ' ')
        {
            return 0;
        
        } else
        
        if((row1[2] == ' ' && row2[1] != ' ' && row3[0] != ' ')
        || (row1[2] != ' ' && row2[1] == ' ' && row3[0] != ' ')
        || (row1[2] != ' ' && row2[1] != ' ' && row3[0] == ' '))
        {
        
            return 1;
        
        } else
        
        if((row1[2] == ' ' && row2[1] == ' ' && row3[0] != ' ')
        || (row1[2] == ' ' && row2[1] != ' ' && row3[0] == ' ')
        || (row1[2] != ' ' && row2[1] == ' ' && row3[0] == ' '))
        {
        
            return 2;
        
        } else {

            return 3;

        }

    }
}

// Checks if win conditions for either player have been met
int checkWinCondition(char row1[], char row2[], char row3[], char winnerChar){

    int row1Empty, row2Empty, row3Empty;
    int col1Empty, col2Empty, col3Empty;
    int diag1Empty, diag2Empty;

    row1Empty = emptyRowCheck(row1);
    row2Empty = emptyRowCheck(row2);
    row3Empty = emptyRowCheck(row3);

    col1Empty = emptyColCheck(row1,row2,row3,0);
    col2Empty = emptyColCheck(row1,row2,row3,1);
    col3Empty = emptyColCheck(row1,row2,row3,2);

    diag1Empty = emptyDiagCheck(row1, row2, row3, 0);
    diag2Empty = emptyDiagCheck(row1, row2, row3, 1);
    
    // Check horizontal
    if(!row1Empty){

        if(row1[0] == row1[1] && row1[1] == row1[2]){
            winnerChar = row1[0];
        }
    }

    if(!row2Empty){

        if(row2[0] == row2[1] && row2[1] == row2[2]){
            winnerChar = row2[0];
        }
    }

    if(!row3Empty){

        if(row3[0] == row3[1] && row3[1] == row3[2]){
            winnerChar = row3[0];
        }
    }

    // Check vertical
    if(!col1Empty){
        
        if(row1[0] == row2[0] && row2[0] == row3[0]){
            winnerChar = row1[0];
        }

    }
    
    if(!col2Empty){
        
        if(row1[1] == row2[1] && row2[1] == row3[1]){
            winnerChar = row1[1];
        }

    }
    
    if(!col3Empty){
        
        if(row1[2] == row2[2] && row2[2] == row3[2]){
            winnerChar = row1[2];
        }
    
    }

    // Check diagonals
    if(!diag1Empty){
        
        if(row1[0] == row2[1] && row2[1] == row3[2]){
            winnerChar = row1[0];
        }

    }
    
    if(!diag2Empty){
        
        if(row1[2] == row2[1] && row2[1] == row3[0]){
            winnerChar = row1[2];
        }
    }

    if(winnerChar != ' '){
        printf("We have a winner! %c wins the game!\n", displayCapitalXO(winnerChar));
        return 1;
    }

    return 0;
    
}

int randomlyChooseAvailableSpot(char row1[], char row2[], char row3[]){

    // Save values of available spots in an array and generate a random number from 0 to the length of the array-1
    // This way, computer never hangs because it never picks a taken spot
    
    int arrayLength = 0;
    int arrayCounter = 0;

    for(int i = 0; i<3; i++){
            if(row1[i] == ' '){
                arrayLength++;
            }
            if(row2[i] == ' '){
                arrayLength++;
            }
            if(row3[i] == ' '){
                arrayLength++;
            }
        }

        int arrayChoices[arrayLength];

        // Check first row values
        for(int i = 0; i < 3; i++){

            if(row1[i] == ' '){

                arrayChoices[arrayCounter] = i+1;
                arrayCounter++;
            }

        }

        // Check second row values
        for(int i = 0; i < 3; i++){

            if(row2[i] == ' '){
                
                arrayChoices[arrayCounter] = i+4;
                arrayCounter++;
            }

        }

        // Check third row values
        for(int i = 0; i < 3; i++){

            if(row3[i] == ' '){

                arrayChoices[arrayCounter] = i+7;
                arrayCounter++;
            }

        }
        
        srand(time(0));
        return arrayChoices[(rand() % arrayLength)];

}

// Based on difficulty, generates a position decision
void askComputerInputBoard(char row1[], char row2[], char row3[], char playerChar, int difficulty, int turnCounter){

    char computerChar;
    int computerChoice;
    int valid = 1;
    int favorableChoice = -1;
    int winConditionChoice = -1;
    int choicesFound = 0;
    int winningChoicesFound = 0;
    int winConditions[6];
    int favorableChoices[27]; 

    int arrayLength = 0;
    int arrayCounter = 0;
    
    if(playerChar == 'x' || playerChar == 'X'){
        computerChar = 'o';
    }

    if(playerChar == 'o' || playerChar == 'O'){
        computerChar = 'x';
    }

    // Difficulty 1 is based on randomization
    if(difficulty == 1){
        
        computerChoice = randomlyChooseAvailableSpot(row1,row2,row3);
        
        printf("Computer has chosen %i\n", computerChoice);

        if(computerChoice > 0 && computerChoice < 4){
            row1[computerChoice-1] = computerChar;

        } else if(computerChoice > 3 && computerChoice < 7){
            row2[computerChoice-4] = computerChar;
        
        } else{
            row3[computerChoice-7] = computerChar;
        }

    // Difficulty 2 prioritizes blocking the player's winning lines and/or filling computer's winning lines
    // Due to randomness, computer could block player's winning line when computer could have won by filling its own

    } else if(difficulty == 2){
        
        // Calculate how many empty spaces exist on the board to determine size of choice array
        for(int i = 0; i<3; i++){
            if(row1[i] == ' '){
                arrayLength++;
            }
            if(row2[i] == ' '){
                arrayLength++;
            }
            if(row3[i] == ' '){
                arrayLength++;
            }
        }

        int arrayChoices[arrayLength];

        // Check first row values
        for(int i = 0; i < 3; i++){

            if(row1[i] == ' '){

                arrayChoices[arrayCounter] = i+1;
                arrayCounter++;
            }

        }

        // Check second row values
        for(int i = 0; i < 3; i++){

            if(row2[i] == ' '){
                
                arrayChoices[arrayCounter] = i+4;
                arrayCounter++;
            }

        }

        // Check third row values
        for(int i = 0; i < 3; i++){

            if(row3[i] == ' '){

                arrayChoices[arrayCounter] = i+7;
                arrayCounter++;
            }

        }

        // Check potential win/block conditions in all directions
        if(turnCounter >= 3){

            // Horizontal
            // | X | - | X |
            // -------------
            // | O | O | - |
            // -------------
            // | X | X | - |
            
            // If only one gap is found in a row, check if the two spots are the same character
            if(emptyRowCheck(row1) == 1){

                //printf("First row has a gap.\n");
                // First row check
                if(row1[0] == ' '){
                    if(row1[1] == row1[2]){
                        favorableChoice = 1;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 1.\n");
                    } 
                } else if(row1[1] == ' '){
                    if(row1[0] == row1[2]){
                        favorableChoice = 2;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 2.\n");
                    } 
                } else {
                    if(row1[0] == row1[1]){
                        favorableChoice = 3;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 3.\n");
                    } 
                }
            }

            if(emptyRowCheck(row2) == 1){
                //printf("Second row has a gap.\n");
                // Second row check
                if(row2[0] == ' '){
                    if(row2[1] == row2[2]){
                        favorableChoice = 4;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 4.\n");
                    } 
                } else if(row2[1] == ' '){
                    if(row2[0] == row2[2]){
                        favorableChoice = 5;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 5.\n");
                    } 
                } else {
                    if(row2[0] == row2[1]){
                        favorableChoice = 6;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 6.\n");
                    } 
                }
            
            }

            if(emptyRowCheck(row3) == 1){
                //printf("Third row has a gap.\n");
                // Third row check
                if(row3[0] == ' '){
                    if(row3[1] == row3[2]){
                        favorableChoice = 7;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 7.\n");
                    } 
                } else if(row3[1] == ' '){
                    if(row3[0] == row3[2]){
                        favorableChoice = 8;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 8.\n");
                    } 
                } else {
                    if(row3[0] == row3[1]){
                        favorableChoice = 9;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 9.\n");
                    } 
                }
            
            } 
            
            // Vertical
            // | X | O | - |
            // -------------
            // | - | - | O |
            // -------------
            // | X | - | O |
            
            // Check first column
            if(emptyColCheck(row1,row2,row3,0) == 1){

                if(row1[0] == ' '){
                    if(row2[0] == row3[0]){
                        favorableChoice = 1;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 10.\n");
                    } 
                } else if(row2[0] == ' '){
                    if(row1[0] == row3[0]){
                        favorableChoice = 4;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 11.\n");
                    } 
                } else if(row3[0] == ' '){
                    if(row1[0] == row2[0]){
                        favorableChoice = 7;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 12.\n");
                    } 
                }

            }
            
            // Check second column
            if(emptyColCheck(row1,row2,row3,1) == 1){

                if(row1[1] == ' '){
                    if(row2[1] == row3[1]){
                        favorableChoice = 2;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 13.\n");
                    } 
                } else if(row2[1] == ' '){
                    if(row1[1] == row3[1]){
                        favorableChoice = 5;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 14.\n");
                    } 
                } else if(row3[1] == ' '){
                    if(row1[1] == row2[1]){
                        favorableChoice = 8;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 15.\n");
                    } 
                }

            }
            
            // Check third column
            if(emptyColCheck(row1,row2,row3,2) == 1){

                if(row1[2] == ' '){
                    if(row2[2] == row3[2]){
                        favorableChoice = 3;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 16.\n");
                    } 
                } else if(row2[2] == ' '){
                    if(row1[2] == row3[2]){
                        favorableChoice = 6;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 17.\n");
                    } 
                } else if(row3[2] == ' '){
                    if(row1[2] == row2[2]){
                        favorableChoice = 9;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 18.\n");
                    }
                }

            }

            // Diagonal
            // | X | O | - |
            // -------------
            // | - | O | X |
            // -------------
            // | O | X | O |

            // Top left to bottom right diagonal
            if(emptyDiagCheck(row1,row2,row3,0) == 1){

                if(row1[0] == ' '){

                    if(row2[1] == row3[2]){
                        favorableChoice = 1;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 19.\n");
                    }

                } else if(row2[1] == ' '){

                    if(row1[0] == row3[2]){
                        favorableChoice = 5;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 20.\n");
                    }

                } else if(row3[2] == ' '){

                    if(row1[0] == row2[1]){
                        favorableChoice = 9;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 21.\n");
                    }

                }

            }

            // Top right to bottom left diagonal
            if(emptyDiagCheck(row1,row2,row3,1) == 1){

                if(row1[2] == ' '){

                    if(row2[1] == row3[0]){
                        favorableChoice = 3;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 22.\n");
                    }

                } else if(row2[1] == ' '){

                    if(row1[2] == row3[0]){
                        favorableChoice = 5;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 23.\n");
                    }

                } else if(row3[0] == ' '){

                    if(row1[2] == row2[1]){
                        favorableChoice = 7;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 24.\n");
                    }

                }

            }

            // If choices found is more than one, choose one randomly
            // Due to randomness, this will cause instances where computer could win but 
            // chooses to block player's winning line

            if(choicesFound > 1){

                //printf("Computer has found %i optimal choices.\n", choicesFound);
                srand(time(0));
                computerChoice = favorableChoices[(rand() % choicesFound)];

            } else if(choicesFound == 1){

                computerChoice = favorableChoices[choicesFound-1];
                //printf("Computer has found %i optimal choice.\n", choicesFound);

            } else{

                //printf("Computer found no optimal choice. Picking randomly...\n");
                computerChoice = randomlyChooseAvailableSpot(row1,row2,row3);

            }

            printf("Computer has chosen %i\n", computerChoice);
            
            if(computerChoice > 0 && computerChoice < 4){
                row1[computerChoice-1] = computerChar;

            } else if(computerChoice > 3 && computerChoice < 7){
                row2[computerChoice-4] = computerChar;
        
            } else{
                row3[computerChoice-7] = computerChar;
            }

        // If not enough turns have been played, pick a random spot
        } else {

            computerChoice = randomlyChooseAvailableSpot(row1,row2,row3);
            printf("Computer has chosen %i\n", computerChoice);

            if(computerChoice > 0 && computerChoice < 4){
            row1[computerChoice-1] = computerChar;

            } else if(computerChoice > 3 && computerChoice < 7){
            row2[computerChoice-4] = computerChar;
    
            } else{
            row3[computerChoice-7] = computerChar;
            }

        }
         
    } else if(difficulty == 3){

        // Calculate how many empty spaces exist on the board to determine size of choice array
        for(int i = 0; i<3; i++){
            if(row1[i] == ' '){
                arrayLength++;
            }
            if(row2[i] == ' '){
                arrayLength++;
            }
            if(row3[i] == ' '){
                arrayLength++;
            }
        }

        int arrayChoices[arrayLength];

        // Check first row values
        for(int i = 0; i < 3; i++){

            if(row1[i] == ' '){

                arrayChoices[arrayCounter] = i+1;
                arrayCounter++;
            }

        }

        // Check second row values
        for(int i = 0; i < 3; i++){

            if(row2[i] == ' '){
                
                arrayChoices[arrayCounter] = i+4;
                arrayCounter++;
            }

        }

        // Check third row values
        for(int i = 0; i < 3; i++){

            if(row3[i] == ' '){

                arrayChoices[arrayCounter] = i+7;
                arrayCounter++;
            }

        }

        // Check potential win/block conditions in all directions
        if(turnCounter >= 3){

            // Horizontal
            // | X | - | X |
            // -------------
            // | O | O | - |
            // -------------
            // | X | X | - |
            
            // If only one gap is found in a row, check if the two spots are the same character
            if(emptyRowCheck(row1) == 1){

                //printf("First row has a gap.\n");
                // First row check
                if(row1[0] == ' '){
                    if(row1[1] == row1[2]){
                        
                        if(row1[1] == computerChar){

                            winConditionChoice = 1;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{
                        
                        favorableChoice = 1;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 1.\n");
                        }
                    
                    } 
                } else if(row1[1] == ' '){
                    if(row1[0] == row1[2]){

                        if(row1[0] == computerChar){

                            winConditionChoice = 2;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{
                        favorableChoice = 2;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 2.\n");
                        }

                    } 
                } else {
                    if(row1[0] == row1[1]){
                        
                        if(row1[0] == computerChar){

                            winConditionChoice = 3;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{
                        
                        favorableChoice = 3;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 3.\n");
                        
                        }
                    } 
                }
            }

            if(emptyRowCheck(row2) == 1){
                //printf("Second row has a gap.\n");
                // Second row check
                if(row2[0] == ' '){
                    if(row2[1] == row2[2]){

                        if(row2[1] == computerChar){

                            winConditionChoice = 4;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 4;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 4.\n");
                        
                        }
                    } 
                } else if(row2[1] == ' '){
                    if(row2[0] == row2[2]){

                        if(row2[0] == computerChar){

                            winConditionChoice = 5;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 5;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 5.\n");
                        }
                    } 
                } else {
                    if(row2[0] == row2[1]){
                        
                        if(row2[0] == computerChar){

                            winConditionChoice = 6;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{
                        
                        favorableChoice = 6;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 6.\n");

                        }
                    } 
                }
            
            }

            if(emptyRowCheck(row3) == 1){
                //printf("Third row has a gap.\n");
                // Third row check
                if(row3[0] == ' '){
                    if(row3[1] == row3[2]){

                        if(row3[1] == computerChar){

                            winConditionChoice = 7;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 7;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 7.\n");
                        
                        }
                    } 
                } else if(row3[1] == ' '){
                    if(row3[0] == row3[2]){

                        if(row3[0] == computerChar){

                            winConditionChoice = 8;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{
                        
                        favorableChoice = 8;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 8.\n");

                        }
                    } 
                } else {
                    if(row3[0] == row3[1]){

                        if(row3[0] == computerChar){

                            winConditionChoice = 9;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 9;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 9.\n");
                        
                        }
                    } 
                }
            
            } 
            
            // Vertical
            // | X | O | - |
            // -------------
            // | - | - | O |
            // -------------
            // | X | - | O |
            
            // Check first column
            if(emptyColCheck(row1,row2,row3,0) == 1){

                if(row1[0] == ' '){
                    if(row2[0] == row3[0]){

                        if(row2[0] == computerChar){

                            winConditionChoice = 1;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 1;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 10.\n");
                        }
                    } 
                } else if(row2[0] == ' '){
                    if(row1[0] == row3[0]){

                        if(row1[0] == computerChar){

                            winConditionChoice = 4;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 4;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 11.\n");
                        
                        }
                    } 
                } else if(row3[0] == ' '){

                    if(row1[0] == row2[0]){

                        if(row1[0] == computerChar){

                            winConditionChoice = 7;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 7;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 12.\n");
                        }
                    } 
                }

            }
            
            // Check second column
            if(emptyColCheck(row1,row2,row3,1) == 1){

                if(row1[1] == ' '){
                    if(row2[1] == row3[1]){

                        if(row2[1] == computerChar){

                            winConditionChoice = 2;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 2;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 13.\n");
                        
                        }
                    } 
                } else if(row2[1] == ' '){
                    if(row1[1] == row3[1]){

                        if(row1[1] == computerChar){

                            winConditionChoice = 5;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 5;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 14.\n");
                        }
                    } 
                } else if(row3[1] == ' '){
                    if(row1[1] == row2[1]){

                        if(row1[1] == computerChar){

                            winConditionChoice = 8;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 8;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 15.\n");
                        
                        } 
                    }

                }
            }
            
            // Check third column
            if(emptyColCheck(row1,row2,row3,2) == 1){

                if(row1[2] == ' '){
                    if(row2[2] == row3[2]){

                        if(row2[2] == computerChar){

                            winConditionChoice = 3;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 3;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 16.\n");

                        }
                    } 
                } else if(row2[2] == ' '){
                    if(row1[2] == row3[2]){

                        if(row1[2] == computerChar){

                            winConditionChoice = 6;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 6;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 17.\n");
                        }
                    } 
                } else if(row3[2] == ' '){
                    if(row1[2] == row2[2]){

                        if(row1[2] == computerChar){

                            winConditionChoice = 9;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 9;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 18.\n");
                        }
                    }
                }

            }

            // Diagonal
            // | X | O | - |
            // -------------
            // | - | O | X |
            // -------------
            // | O | X | O |

            // Top left to bottom right diagonal
            if(emptyDiagCheck(row1,row2,row3,0) == 1){

                if(row1[0] == ' '){

                    if(row2[1] == row3[2]){

                        if(row2[1] == computerChar){

                            winConditionChoice = 1;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 1;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 19.\n");
                        }
                    }

                } else if(row2[1] == ' '){

                    if(row1[0] == row3[2]){

                        if(row1[0] == computerChar){

                            winConditionChoice = 5;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 5;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 20.\n");
                        }
                    }

                } else if(row3[2] == ' '){

                    if(row1[0] == row2[1]){

                        if(row1[0] == computerChar){

                            winConditionChoice = 9;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 9;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 21.\n");

                        }
                    }

                }

            }

            // Top right to bottom left diagonal
            if(emptyDiagCheck(row1,row2,row3,1) == 1){

                if(row1[2] == ' '){

                    if(row2[1] == row3[0]){

                        if(row2[1] == computerChar){

                            winConditionChoice = 3;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 3;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 22.\n");
                        
                        }
                    }

                } else if(row2[1] == ' '){

                    if(row1[2] == row3[0]){

                        if(row1[2] == computerChar){

                            winConditionChoice = 5;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 5;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 23.\n");
                        }
                    }

                } else if(row3[0] == ' '){

                    if(row1[2] == row2[1]){

                        if(row1[2] == computerChar){

                            winConditionChoice = 7;
                            winningChoicesFound++;
                            winConditions[winningChoicesFound - 1] = winConditionChoice;
                        
                        } else{

                        favorableChoice = 7;
                        choicesFound++;
                        favorableChoices[choicesFound - 1] = favorableChoice;
                        //printf("Checkpoint 24.\n");
                        }

                    }

                }

            }

            // If choices found is more than one, choose one randomly
            // Due to randomness, this will cause instances where computer could win but 
            // chooses to block player's winning line

            if(winningChoicesFound > 1){

                srand(time(0));
                computerChoice = winConditions[(rand() % winningChoicesFound)];
            
            } else if(winningChoicesFound == 1){

                computerChoice = winConditions[winningChoicesFound - 1];

            } else if(choicesFound > 1){

                srand(time(0));
                computerChoice = favorableChoices[(rand() % choicesFound)];

            } else if(choicesFound == 1){

                computerChoice = favorableChoices[choicesFound-1];
                //printf("Computer has found %i optimal choice.\n", choicesFound);
                
            } else{

                //printf("Computer found no optimal choice. Picking randomly...\n");
                computerChoice = randomlyChooseAvailableSpot(row1,row2,row3);

            }

        // If not enough turns have been played, pick a random spot
        } else {

            computerChoice = randomlyChooseAvailableSpot(row1,row2,row3);
        
        }

        printf("Computer has chosen %i\n", computerChoice);

        if(computerChoice > 0 && computerChoice < 4){
            row1[computerChoice-1] = computerChar;

        } else if(computerChoice > 3 && computerChoice < 7){
            row2[computerChoice-4] = computerChar;
        
        } else{
            row3[computerChoice-7] = computerChar;
        }
                         
    }

}

// Resets the table for a new game
void clearTable(char row1[], char row2[], char row3[]){
    
    for(int i = 0; i < 3; i++){
        row1[i] = ' ';
        row2[i] = ' ';
        row3[i] = ' ';
    }
}
// End of helper functions