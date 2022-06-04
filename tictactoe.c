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

int askUserInputBoard(char row1[], char row2[], char row3[], char playerChar){

    int boardChoice;
    
    printf("Enter a position from 1 to 9: ");
    scanf("%i", &boardChoice);

    if(boardChoice < 1 || boardChoice > 9){
        printf("Please choose a number from 1 to 9.\n");
        askUserInputBoard(row1, row2, row3, playerChar);
    
    } else{
        switch(boardChoice){
            case 1:
            if((char)row1[0] == (char)' '){
                (row1[0]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row1[0]));
                askUserInputBoard(row1, row2, row3, playerChar);
            }
            break;

            case 2:
            if((char)row1[1] == (char)' '){
                (row1[1]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row1[1]));
                askUserInputBoard(row1, row2, row3, playerChar);
            }
            break;

            case 3:
            if((char)row1[2] == (char)' '){
                (row1[2]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row1[2]));
                askUserInputBoard(row1, row2, row3, playerChar);
            }
            break;

            case 4:
            if((char)row2[0] == (char)' '){
                (row2[0]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row2[0]));
                askUserInputBoard(row1, row2, row3, playerChar);
            }
            break;

            case 5:
            if((char)row2[1] == (char)' '){
                (row2[1]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row2[1]));
                askUserInputBoard(row1, row2, row3, playerChar);
            }
            break;

            case 6:
            if((char)row2[2] == (char)' '){
                (row2[2]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row2[2]));
                askUserInputBoard(row1, row2, row3, playerChar);
            }
            break;

            case 7:
            if((char)row3[0] == (char)' '){
                (row3[0]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row3[0]));
                askUserInputBoard(row1, row2, row3, playerChar);
            }
            break;

            case 8:
            if((char)row3[1] == (char)' '){
                (row3[1]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row3[1]));
                askUserInputBoard(row1, row2, row3, playerChar);
            }
            break;

            case 9:
            if((char)row3[2] == (char)' '){
                (row3[2]) = playerChar;
            } else {
                printf("Position %i is already taken by %c, please choose another.", boardChoice, displayCapitalXO(row3[2]));
                askUserInputBoard(row1, row2, row3, playerChar);
            }
            break;
        }
    }

}

int checkWinCondition(char row1[], char row2[], char row3[], char *winnerChar){
    
    // Check vertical lines
    for(int i = 0; i < 3; i++){
        
        if(!(row1[i] == ' ' && row2[i] == ' ' && row3[i] == ' ')){
            
            if(row1[i] == row2[i] && row2[i] == row3[i]){
                winnerChar = row1[i];

                if(winnerChar == 'x'){
                    winnerChar = 'X';
                } else if(winnerChar == 'o'){
                    winnerChar = 'O';
                }

                printf("We have a winner! %c wins the game!\n", winnerChar);
                return 1;
            }
        }
    }

    // Check first diagonal (top left to bottom right)
    if(!(row1[0] == ' ' || row2[1] == ' ' || row3[2] == ' ')){
        
        if(row1[0] == row2[1] && row2[1] == row3[2]){
            winnerChar = row1[0];
            
            if(winnerChar == 'x'){
                    winnerChar = 'X';
                } else if(winnerChar == 'o'){
                    winnerChar = 'O';
                }

            printf("We have a winner! %c wins the game!\n", winnerChar);
            return 1;
        }
    
    }

    // Check second diagonal (top right to bottom left)
    if(!(row1[2] == ' ' || row2[1] == ' ' || row3[0] == ' '))
    {
        if(row1[2] == row2[1] && row2[1] == row3[0]){
            winnerChar = row1[2];

            if(winnerChar == 'x'){
                    winnerChar = 'X';
                } else if(winnerChar == 'o'){
                    winnerChar = 'O';
                }

            printf("We have a winner! %c wins the game!\n", winnerChar);
            return 1;
        }

    }

    // Check horizontal lines   
    if(!(row1[0] == ' ' || row1[1] == ' ' || row1[2] == ' ')){
        
        if(row1[0] == row1[1] && row1[1] == row1[2]){
            winnerChar = row1[0];

            if(winnerChar == 'x'){
                    winnerChar = 'X';
                } else if(winnerChar == 'o'){
                    winnerChar = 'O';
                }

            printf("We have a winner! %c wins the game!\n", winnerChar);
            return 1;
        }

    } else if(!(row2[0] == ' ' || row2[1] == ' ' || row2[2] == ' ')){
        
        if(row2[0] == row2[1] && row2[1] == row2[2]){
            winnerChar = row2[0];

            if(winnerChar == 'x'){
                    winnerChar = 'X';
                } else if(winnerChar == 'o'){
                    winnerChar = 'O';
                }

            printf("We have a winner! %c wins the game!\n", winnerChar);
            return 1;
        }
    
    } else if(!(row3[0] == ' ' || row3[1] == ' ' || row3[2] == ' ')){
        
        if(row3[0] == row3[1] && row3[1] == row3[2]){
            winnerChar = row3[0];

            if(winnerChar == 'x'){
                    winnerChar = 'X';
                } else if(winnerChar == 'o'){
                    winnerChar = 'O';
                }

            printf("We have a winner! %c wins the game!\n", winnerChar);
            return 1;
        }
    }
    
    return 0;

}

void askComputerInputBoard(char row1[], char row2[], char row3[], char playerChar){

    char computerChar;
    int computerChoice;
    int valid = 1;
    
    if(playerChar == 'x'){
        computerChar = 'o';
    }

    if(playerChar == 'o'){
        computerChar = 'x';
    }

    // Randomly choose position from 1 to 9 and check if it is taken
    do{
        srand(time(0));
        computerChoice = 1 + rand() % 9;
        
        
        if(computerChoice < 4){
            if(row1[computerChoice-1] != ' '){
                valid = 0;
            } else{
                valid = 1;
                row1[computerChoice-1] = computerChar;
                printf("Computer picked %i\n", computerChoice);
            }
        }
        else if(computerChoice > 3 && computerChoice < 7){
            if(row2[computerChoice-4] != ' '){
                valid = 0;
            } else{
                valid = 1;
                row2[computerChoice-4] = computerChar;
                printf("Computer picked %i\n", computerChoice);
            }
        }
        else if(computerChoice > 6 && computerChoice < 10){
            if(row3[computerChoice-7] != ' '){
                valid = 0;
            } else{
                valid = 1;
                row3[computerChoice-7] = computerChar;
                printf("Computer picked %i\n", computerChoice);
            }
        }

    } while(!valid);
    //printf("Exception: computer choice: %i\n", computerChoice);
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
    int startingPlayer;
    int winCondition = 0;
    char playAgain = 'n';
    int turnCounter = 0;

    char inputLetter;
    char displayLetter;
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

        do{
            printf("\n");
            printf("Would you like to be X or O ?\n");

            inputLetter = askUserInputXO();

            if(inputLetter == 'x'){
                displayLetter = 'X';
            } else if(inputLetter == 'o'){
                displayLetter = 'O';
            }
            
            printf("\n");
            printf("You have chosen to be %c\n", displayLetter);

            printf("Choosing starting player...\n");
            sleep(2);
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
                
                    askUserInputBoard(&firstRow, &secondRow, &thirdRow, inputLetter);
                    turnCounter++;
                    printf("\n");

                    printCurrentTable(firstRow, secondRow, thirdRow);

                    winCondition = checkWinCondition(firstRow, secondRow, thirdRow, &winnerChar);
                    if(winCondition){
                        break;
                    }

                    if(turnCounter == 9){
                        printf("Stalemate!\n");
                        break;
                    }
                    
                    printf("Waiting for computer to make its pick...\n");

                    sleep(1);

                    askComputerInputBoard(&firstRow, &secondRow, &thirdRow, inputLetter);
                    turnCounter++;
                    printCurrentTable(firstRow, secondRow, thirdRow);

                    winCondition = checkWinCondition(firstRow, secondRow, thirdRow, &winnerChar);
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
                sleep(2);

                do{
                
                    printf("\n");

                    printf("Waiting for computer to make its pick...\n");

                    sleep(1);

                    askComputerInputBoard(&firstRow, &secondRow, &thirdRow, inputLetter);
                    turnCounter++;
                    printf("\n");

                    printCurrentTable(firstRow, secondRow, thirdRow);

                    winCondition = checkWinCondition(firstRow, secondRow, thirdRow, &winnerChar);
                    if(winCondition){
                        break;
                    }

                    if(turnCounter == 9){
                        printf("Stalemate!\n");
                        break;
                    }
                    
                    printf("\n");

                    askUserInputBoard(&firstRow, &secondRow, &thirdRow, inputLetter);
                    turnCounter++;
                    printCurrentTable(firstRow, secondRow, thirdRow);
                        
                    winCondition = checkWinCondition(firstRow, secondRow, thirdRow, &winnerChar);
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

    }
}