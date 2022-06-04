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
int askUserInputNum(){

    int inputInt;
    scanf("%d", &inputInt);

    if(inputInt == 2){
        return 2;
    }
    else if(inputInt == 1){
        return 1;
    } else{
        printf("Please enter either 1 or 2.\n");
        return askUserInputNum();
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

void printTableStart(){
    
    printf("\n");
    printf("|");

    for(int i = 0; i < 3; i++){
        
        printf(" %i |", (i+1));
    }
    
    printf("\n-------------\n");
    printf("|");
    
    for(int i = 0; i < 3; i++){
        
        printf(" %i |", (i + 4));
        
    }

    printf("\n-------------\n");
    printf("|");
    
    for(int i = 0; i < 3; i++){
        
        printf(" %i |", (i+7));

    }

    printf("\n");

}

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
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row1[0]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;

            case 2:
            if((char)row1[1] == (char)' '){
                (row1[1]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row1[1]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;

            case 3:
            if((char)row1[2] == (char)' '){
                (row1[2]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row1[2]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;

            case 4:
            if((char)row2[0] == (char)' '){
                (row2[0]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row2[0]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;

            case 5:
            if((char)row2[1] == (char)' '){
                (row2[1]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row2[1]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;

            case 6:
            if((char)row2[2] == (char)' '){
                (row2[2]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row2[2]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;

            case 7:
            if((char)row3[0] == (char)' '){
                (row3[0]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row3[0]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;

            case 8:
            if((char)row3[1] == (char)' '){
                (row3[1]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row3[1]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;

            case 9:
            if((char)row3[2] == (char)' '){
                (row3[2]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row3[2]));
                askUserInputBoard(row1, row2, row3, playerChar, gamemode);
            }
            break;
        }
    }

}

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

    if(row1[colNum] == ' ' || row2[colNum] == ' ' || row3[colNum] == ' '){
        return 1;
    } else{
        return 0;
    }

}

int emptyDiagCheck(char row1[], char row2[], char row3[], int diagNum){

    if(diagNum == 0){

        if(row1[0] == ' ' || row2[1] == ' ' || row3[2] == ' '){
            return 1;
        } else{
            return 0;
        }

    } else{
        
        if(row1[2] == ' ' || row2[1] == ' ' || row3[0] == ' '){
            return 1;
        } else{
            return 0;
        }

    }

    return 0;

}

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

void askComputerInputBoard(char row1[], char row2[], char row3[], char playerChar, int difficulty, int turnCounter){

    char computerChar;
    int computerChoice;
    int valid = 1;

    int arrayLength = 0;
    int arrayCounter = 0;
    
    if(playerChar == 'x'){
        computerChar = 'o';
    }

    if(playerChar == 'o'){
        computerChar = 'x';
    }

    // Difficulty 1 is based on randomization
    if(difficulty == 1){
    
        // Save values of available spots in an array and generate a random number from 0 to the length of the array-1
        // This way, computer never hangs because it never picks a taken spot
        
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
        computerChoice = arrayChoices[(rand() % arrayLength)];
        
        printf("Computer has chosen %i", computerChoice);

        if(computerChoice > 0 && computerChoice < 4){
            row1[computerChoice-1] = computerChar;

        } else if(computerChoice > 3 && computerChoice < 7){
            row2[computerChoice-4] = computerChar;
        
        } else{
            row3[computerChoice-7] = computerChar;
        }

    // UNDER CONSTRUCTION
    // Difficulty 2 prioritizes blocking the player's winning lines
    } else if(difficulty == 2){

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

        // // Check current board combinations
        // if(turnCounter > 2){



        // }


    }

}

void clearTable(char row1[], char row2[], char row3[]){
    
    for(int i = 0; i < 3; i++){
        row1[i] = ' ';
        row2[i] = ' ';
        row3[i] = ' ';
    }
}
// End of helper functions

// Start
void main(){

    int inputNum;
    int gameMode = 1;
    int startingPlayer;
    int winCondition = 0;
    char playAgain = 'n';
    int turnCounter = 0;
    int computerDifficulty = 1;

    char inputLetter;
    char player1Letter;
    char player2Letter;
    char displayLetter;
    char player1DisplayLetter;
    char player2DisplayLetter;
    char firstRow[3] = {' ',' ',' '}; 
    char secondRow[3] = {' ',' ',' '};  
    char thirdRow[3]  = {' ',' ',' '};
    char winnerChar = ' ';
      
    
    printf("Welcome to Tic Tac Toe!\n\n");

    printf("Press 1 to start a new game.\n");
    printf("Press 2 to quit.\n");

    inputNum = askUserInputNum();
    
    if(inputNum == 2){
        printf("Thanks for playing! Come back soon.\n\n");
        sleep(1);
        return 0;
    }

    else{
            
        printf("Press 1 to play against the computer. \n");
        printf("Press 2 for local multiplayer.\n");

        gameMode = askUserInputNum();

        if(gameMode == 1){    
            do{
                
                printf("\n");
                printf("Would you like to be X or O ?\n");

                inputLetter = askUserInputXO();

                if(inputLetter == 'x'){
                    displayLetter = 'X';
                } else if(inputLetter == 'o'){
                    displayLetter = 'O';
                } else{
                    displayLetter = inputLetter;
                }
                
                printf("\n");
                printf("You have chosen to be %c\n", displayLetter);

                printf("Choosing starting player...\n");
                sleep(1);
                srand(time(0));
                startingPlayer = rand() % 2;

                if(startingPlayer == 0){
                    printf("You get to start first.\n");
                } else{
                    printf("Computer gets to start first.\n");
                }

                sleep(2);

                printTableStart();

                printf("\n");

                printf("Throughout the game, you will be asked to mark your spot by typing in a number from 1 to 9...\n");
                sleep(2);
                printf("\n");

                if(startingPlayer == 0){
                    printf("The positions are marked on the table above. Now, choose your first position.\n");
                    sleep(2);
                    do{
                    
                        askUserInputBoard(&firstRow, &secondRow, &thirdRow, inputLetter, gameMode);
                        turnCounter++;
                        printf("\n");

                        printCurrentTable(firstRow, secondRow, thirdRow);

                        winCondition = checkWinCondition(firstRow, secondRow, thirdRow, winnerChar);
                        if(winCondition){
                            break;
                        }

                        if(turnCounter == 9){
                            printf("Stalemate!\n");
                            break;
                        }
                        
                        printf("Waiting for computer to make its pick...\n");

                        sleep(1);

                        askComputerInputBoard(&firstRow, &secondRow, &thirdRow, inputLetter, computerDifficulty, turnCounter);
                        turnCounter++;
                        printCurrentTable(firstRow, secondRow, thirdRow);

                        winCondition = checkWinCondition(firstRow, secondRow, thirdRow, winnerChar);
                        if(winCondition){
                            break;
                        }

                        if(turnCounter == 9){
                            printf("Stalemate!\n");
                            break;
                        }

                    }while(!winCondition);

                } else {
                    printf("The positions are marked on the table above. After the computer chooses its first position, you will get to choose yours.\n");
                    sleep(3);

                    do{
                    
                        printf("\n");

                        printf("Waiting for computer to make its pick...\n");

                        sleep(1);

                        askComputerInputBoard(&firstRow, &secondRow, &thirdRow, inputLetter, computerDifficulty, turnCounter);
                        turnCounter++;
                        printf("\n");

                        printCurrentTable(firstRow, secondRow, thirdRow);

                        winCondition = checkWinCondition(firstRow, secondRow, thirdRow, winnerChar);
                        if(winCondition){
                            break;
                        }

                        if(turnCounter == 9){
                            printf("Stalemate!\n");
                            break;
                        }
                        
                        printf("\n");

                        askUserInputBoard(&firstRow, &secondRow, &thirdRow, inputLetter, gameMode);
                        turnCounter++;
                        printCurrentTable(firstRow, secondRow, thirdRow);
                            
                        winCondition = checkWinCondition(firstRow, secondRow, thirdRow, winnerChar);
                        if(winCondition){
                            break;
                        }

                        if(turnCounter == 9){
                            printf("Stalemate!\n");
                            break;
                        }

                    }while(!winCondition);
                }
            
                sleep(1);
                printf("Would you like to play again? (y/n):");
                playAgain = askUserInputYN();

                clearTable(&firstRow, &secondRow, &thirdRow);
                printf("\n");
                turnCounter = 0;
            
            } while(playAgain == 'y');
                
            printf("Thanks for playing! Come back soon.\n\n");
            sleep(1);
            return 0;
        
        } else {

            do{

                printf("Choosing starting player...\n");
                sleep(1);
                srand(time(0));
                startingPlayer = rand() % 2;

                if(startingPlayer == 0){
                    printf("Player 1: You get to start first.\n");
                } else{
                    printf("Player 2: You get to start first.\n");
                }
                
                if(startingPlayer == 0){
                    
                    printf("\n");
                    printf("Player 1: Would you like to be X or O ?\n");

                    player1Letter = askUserInputXO();

                    if(player1Letter == 'x' || player1Letter == 'X'){
                        
                        player1Letter = 'x';
                        player1DisplayLetter = 'X';
                        
                        player2Letter = 'o';
                        player2DisplayLetter = 'O';
                    
                    } else{

                        player1Letter = 'o';
                        player1DisplayLetter = 'O';

                        player2Letter = 'x';
                        player2DisplayLetter = 'X';

                    }

                    printf("\n");
                    printf("Player 1: You have chosen to be %c.\n", player1DisplayLetter);
                    sleep(1);
                    printf("Player 2: You will be %c.\n", player2DisplayLetter);
                    sleep(1);

                    printTableStart();
                    printf("\n");

                    printf("Throughout the game, each of you will be asked to mark your spot by typing in a number from 1 to 9...\n");
                    sleep(2);
                    printf("\n");

                    printf("The positions are marked on the table above. Now, Player 1: choose your first position.\n");
                    sleep(2);

                    do{
                    
                        askUserInputBoard(&firstRow, &secondRow, &thirdRow, player1Letter, gameMode);
                        turnCounter++;
                        printf("\n");

                        printCurrentTable(firstRow, secondRow, thirdRow);

                        winCondition = checkWinCondition(firstRow, secondRow, thirdRow, winnerChar);
                        if(winCondition){
                            break;
                        }

                        if(turnCounter == 9){
                            printf("Stalemate!\n");
                            break;
                        }

                        askUserInputBoard(&firstRow, &secondRow, &thirdRow, player2Letter, gameMode);

                        turnCounter++;
                        printCurrentTable(firstRow, secondRow, thirdRow);

                        winCondition = checkWinCondition(firstRow, secondRow, thirdRow, winnerChar);
                        if(winCondition){
                            break;
                        }

                        if(turnCounter == 9){
                            printf("Stalemate!\n");
                            break;
                        }

                    }while(!winCondition);

                } else{

                    printf("\n");
                    printf("Player 2: Would you like to be X or O ?\n");

                    player2Letter = askUserInputXO();

                    if(player2Letter == 'x' || player2Letter == 'X'){
                        
                        player2Letter = 'x';
                        player2DisplayLetter = 'X';
                        
                        player1Letter = 'o';
                        player1DisplayLetter = 'O';
                    
                    } else{

                        player2Letter = 'o';
                        player2DisplayLetter = 'O';

                        player1Letter = 'x';
                        player1DisplayLetter = 'X';

                    }

                    printf("\n");
                    printf("Player 2: You have chosen to be %c\n", player2DisplayLetter);
                    sleep(1);
                    printf("Player 1: You will be %c.\n", player1DisplayLetter);
                    sleep(1);

                    printTableStart();
                    printf("\n");

                    printf("Throughout the game, each of you will be asked to mark your spot by typing in a number from 1 to 9...\n");
                    sleep(2);
                    printf("\n");

                    printf("The positions are marked on the table above. Now, Player 2: choose your first position.\n");
                    sleep(2);

                    do{
                    
                        askUserInputBoard(&firstRow, &secondRow, &thirdRow, player2Letter, gameMode);
                        turnCounter++;
                        printf("\n");

                        printCurrentTable(firstRow, secondRow, thirdRow);

                        winCondition = checkWinCondition(firstRow, secondRow, thirdRow, winnerChar);
                        if(winCondition){
                            break;
                        }

                        if(turnCounter == 9){
                            printf("Stalemate!\n");
                            break;
                        }

                        askUserInputBoard(&firstRow, &secondRow, &thirdRow, player1Letter, gameMode);

                        turnCounter++;
                        printCurrentTable(firstRow, secondRow, thirdRow);

                        winCondition = checkWinCondition(firstRow, secondRow, thirdRow, winnerChar);
                        if(winCondition){
                            break;
                        }

                        if(turnCounter == 9){
                            printf("Stalemate!\n");
                            break;
                        }

                    }while(!winCondition);

                }

                sleep(1);
                printf("Would you like to play again? (y/n):");
                playAgain = askUserInputYN();

                clearTable(&firstRow, &secondRow, &thirdRow);
                printf("\n");
                turnCounter = 0;

            }while(playAgain == 'y');

            printf("Thanks for playing! Come back soon.\n\n");
            sleep(1);
            return 0;

        }

    }
}