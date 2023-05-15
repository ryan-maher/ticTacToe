#include "tictactoe.h"

// Start
int main(){

    int inputNum;
    int gameMode = 1;
    int startingPlayer;
    int winCondition = 0;
    char playAgain = 'n';
    int turnCounter = 0;
    int computerDifficulty = 1;
    int bot1Difficulty = 1;
    int bot2Difficulty = 1;

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

    inputNum = askUserInputNum12();
    
    if(inputNum == 2){
        printf("Thanks for playing! Come back soon.\n\n");
        sleep(1);
        return 0;
    }

    else{
            
        printf("\n");
        printf("Press 1 to play against the computer. \n");
        printf("Press 2 for local multiplayer.\n");
        printf("Press 3 to watch two bots play against each other.\n");

        gameMode = askUserInputNum123();

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
                printf("You have chosen to be %c.\n", displayLetter);
                sleep(1);

                printf("\n");
                printf("Please choose a difficulty:\n");
                sleep(1);
                printf("Difficulty 1: Computer randomly chooses its spots.\n");
                sleep(1);
                printf("Difficulty 2: Computer actively tries to block your lines and/or fills in its own.\n");
                sleep(1);
                printf("Difficulty 3: Similar to 2, but computer always takes the chance to win if possible.\n");
                sleep(1);
                printf("Please enter either 1, 2, or 3: ");

                computerDifficulty = askUserInputNum123();

                printf("\n");
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
                printf("Would you like to play again? (y/n): ");
                playAgain = askUserInputYN();

                clearTable(&firstRow, &secondRow, &thirdRow);
                printf("\n");
                turnCounter = 0;
            
            } while(playAgain == 'y');
                
            printf("Thanks for playing! Come back soon.\n\n");
            sleep(1);
            return 0;
        
        // Local multiplayer option
        } else if(gameMode == 2){

            do{

                printf("\n");
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

        // Bot vs Bot option
        } else {

            do{

            printf("\n");
            printf("Please choose a difficulty for each bot:\n");
            sleep(1);
            printf("Difficulty 1: Computer randomly chooses its spots.\n");
            sleep(1);
            printf("Difficulty 2: Computer actively tries to block your lines and/or fills in its own.\n");
            sleep(1);
            printf("Difficulty 3: Similar to 2, but computer always takes the chance to win if possible.\n");
            sleep(1);
            printf("Bot 1: Please enter either 1, 2, or 3: ");

            bot1Difficulty = askUserInputNum123();
            
            printf("\n");
            printf("Bot 2: Please enter either 1, 2, or 3: ");

            bot2Difficulty = askUserInputNum123();

            printf("\n");
            printf("Choosing starting bot...\n");
            sleep(1);
            srand(time(0));
            startingPlayer = rand() % 2;

            if(startingPlayer == 0){
                printf("Bot 1 gets to start first.\n");
                sleep(1);
            } else{
                printf("Bot 2 gets to start first.\n");
                sleep(1);
            }

            if(startingPlayer == 0){

                printf("\n");
                printf("Choosing X or O for Bot 1...\n");
                sleep(1);

                if(rand() % 2 == 0){
                    player1Letter = 'X';
                    player1DisplayLetter = 'X';
                    player2Letter = 'O';
                    player2DisplayLetter = 'O';
                } else {
                    player1Letter = 'O';
                    player1DisplayLetter = 'O';
                    player2Letter = 'X';
                    player2DisplayLetter = 'X';
                }

                printf("\n");
                printf("Bot 1 will be %c.\n", player1DisplayLetter);
                sleep(1);
                printf("Bot 2 will be %c.\n", player2DisplayLetter);
                sleep(1);

                printTableStart();
                printf("\n");
                sleep(1);

                do{
                
                    //askUserInputBoard(&firstRow, &secondRow, &thirdRow, player1Letter, gameMode);
                    askComputerInputBoard(&firstRow, &secondRow, &thirdRow, player2Letter, bot1Difficulty, turnCounter);
                    turnCounter++;
                    printf("\n");

                    printCurrentTable(firstRow, secondRow, thirdRow);
                    sleep(2);

                    winCondition = checkWinCondition(firstRow, secondRow, thirdRow, winnerChar);
                    if(winCondition){
                        break;
                    }

                    if(turnCounter == 9){
                        printf("Stalemate!\n");
                        break;
                    }

                    askComputerInputBoard(&firstRow, &secondRow, &thirdRow, player1Letter, bot2Difficulty, turnCounter);

                    turnCounter++;
                    printCurrentTable(firstRow, secondRow, thirdRow);
                    sleep(2);

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

                printf("\n");
                printf("Choosing X or O for Bot 2...\n");
                sleep(1);

                if(rand() % 2 == 0){
                    player2Letter = 'X';
                    player2DisplayLetter = 'X';
                    player1Letter = 'O';
                    player1DisplayLetter = 'O';
                } else {
                    player2Letter = 'O';
                    player2DisplayLetter = 'O';
                    player1Letter = 'X';
                    player1DisplayLetter = 'X';
                }

                printf("\n");
                printf("Bot 1 will be %c.\n", player1DisplayLetter);
                sleep(1);
                printf("Bot 2 will be %c.\n", player2DisplayLetter);
                sleep(1);

                do{
                
                    askComputerInputBoard(&firstRow, &secondRow, &thirdRow, player1Letter, bot2Difficulty, turnCounter);
                    turnCounter++;
                    printf("\n");

                    printCurrentTable(firstRow, secondRow, thirdRow);
                    sleep(2);

                    winCondition = checkWinCondition(firstRow, secondRow, thirdRow, winnerChar);
                    if(winCondition){
                        break;
                    }

                    if(turnCounter == 9){
                        printf("Stalemate!\n");
                        break;
                    }

                    askComputerInputBoard(&firstRow, &secondRow, &thirdRow, player2Letter, bot1Difficulty, turnCounter);

                    turnCounter++;
                    printCurrentTable(firstRow, secondRow, thirdRow);
                    sleep(2);

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
            printf("Would you like to play again? (y/n): ");
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
}