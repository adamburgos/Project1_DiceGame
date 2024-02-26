#include <stdio.h>
#include <stdlib.h>
#include "dicegame.h"

int main() {
    //initialize Random number generator
    srand(time(NULL));
    //initialize variables 
    int player1 = 0;
    int player2 = 0;
    int dice = 0;
    int points = 0;
    int rounds = 0;
    int startingPlayer = 0;
    int secondPlayer = 0;
	//get number of rounds from user
    printf("Enter the number of rounds: " );
    scanf("%d", &rounds);
	//print player points 
    printPlayerPoints(player1, player2);
    
        if (getRandomNumber(2,1) == 1){
            startingPlayer = 1;
            secondPlayer = 2;
        } else {
            startingPlayer = 2;
            secondPlayer = 1;
        }
    
    //main game loop
    for (int i = 0; i < rounds; i++){
        //randomize points, dice and round type
        points = (getRandomNumber(1, 10)) * 10;
        dice = getRandomNumber(1, 6);
        ROUND_TYPE roundType = getRoundType();
        int currentPlayer = 0;
        
        //print rounds 
        printf("ROUND: %d\n", i+1);
        printf("--------\n");
        //determine starting player 
        if (i == 0 || i % 2 == 0){
            printf("Current player: %d\n", startingPlayer);
            currentPlayer = startingPlayer;
        } else {
            printf("Current player: %d\n", secondPlayer);
            currentPlayer = secondPlayer;
        }

        printRoundInfo(roundType, dice, points);
        //determine points per round 
        if (roundType == BONUS){
            points = 200; 
        } 
        else if(roundType == DOUBLE){
            points = points * 2;
        } 
        else {
            points = points;
        }
        //add or subtract points to player based on round
        if (currentPlayer & 2 != 0){
            if (dice % 2 != 0){
                player1 += points;
            } 
            else {
                player1 -= points;
            }
        } 
        else {
            if (dice % 2 == 0){
                player2 += points;
            }
            else {
                player2 -= points;
            }
        }

        printPlayerPoints(player1, player2);

                printf("\n\n");
    }


    printf("GAME OVER!!\n");
    //print final outcome
    if (player1 > player2){
        printf("P1 Won\n\n");
    } 
    else {
        printf("P2 Won\n\n");
    }

    return 0;
}
