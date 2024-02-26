#include <stdio.h>
#include <stdlib.h>
#include "dicegame.h"

int main() {

    // Initialize the srand() to start the random generator
    srand(time(NULL));
	// Initialize the player-1 and player-2 points to 0
    int player1 = 0;
    int player2 = 0;
	// Initialize all other required variables
    int dice = 0;
    int points = 0;
    int rounds = 0;
    int startingPlayer = 0;
    int secondPlayer = 0;
	// scanf the user for the number of rounds to run the game
    printf("Enter the number of rounds: " );
    scanf("%d", &rounds);
	// Call printPlayerPoints() function to print the initial player points which will be 0
    printPlayerPoints(player1, player2);
    // Determine the starting player randomly
        if (getRandomNumber(2,1) == 1){
            //printf("Starting player: Player 1\n\n");
            startingPlayer = 1;
            secondPlayer = 2;
        } else {
            //printf("Starting player: Player 2\n\n");
            startingPlayer = 2;
            secondPlayer = 1;
        }
    
    // Set up the loop to go through all the rounds one at a time
    for (int i = 0; i < rounds; i++){
        		// Call the corresponding functions to get the information for this round - type, dice, points
        points = (getRandomNumber(1, 10)) * 10;
        dice = getRandomNumber(1, 6);
        ROUND_TYPE roundType = getRoundType();
        int currentPlayer = 0;
        
                // Print round number
        printf("ROUND: %d\n", i+1);
        printf("--------\n");
                // Print current player
        if (i == 0 || i % 2 == 0){
            printf("Current player: %d\n", startingPlayer);
            currentPlayer = startingPlayer;
        } else {
            printf("Current player: %d\n", secondPlayer);
            currentPlayer = secondPlayer;
        }
                // Call printRoundInfo() to print the round information
        printRoundInfo(roundType, dice, points);

                // MAIN GAME LOGIC
                // Write code here to get the main game logic using branches
                // Success: Player-1 (odd player) is the current player and the dice rolled is odd
                // OR Player-2 (even player) is the current player and the dice rolled is even.
                    // Current player gains the points, based on the type of the round (see above). The current player’s turn continues in the next round.
                // Failure: Player-1 (odd player) is the current player and the dice rolled is even
                // OR Player-2 (even player) is the current player and the dice rolled is odd.
                    // Current player incurs penalty of the same number of points, based on the type of the round (see above). In the next round, the current player is changed to the other player.
                // Call printPlayerPoints() to print the player information at the end of the round

        if (roundType == BONUS){
            points = 200; 
        } 
        else if(roundType == DOUBLE){
            points = points * 2;
        } 
        else {
            points = points;
        }

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


    printf("Game Over!!\n");

    // Compare the final points for player-1 and player-2
	// Print the winner as the one with higher points
	// Return from the main() function to end the program successfully
    if (player1 > player2){
        printf("P1 Won\n\n");
    } 
    else {
        printf("P2 Won\n\n");
    }

    return 0;
}
