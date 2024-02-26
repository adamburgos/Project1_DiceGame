#include "dicegame.h"

int getRandomNumber(int min, int max) {
    return (rand() % max) + min;
}

ROUND_TYPE getRoundType() {
    int roundType = (rand() % 10) + 1;

    if (roundType <= 5){
        return REGULAR;
    } else if (roundType >= 6 && roundType <= 8){
        return BONUS;
    } else {
        return DOUBLE;
    }
}

int getRoundPoints(ROUND_TYPE roundType) {
    int roundPoints;
        if (roundType == REGULAR){

        }
        return 0;
}

void printPlayerPoints(int p1, int p2) {

    printf("P1\t: %d\n", p1);
    printf("P2\t: %d\n\n", p2);

}

void printRoundInfo(ROUND_TYPE t, int dice, int points) {
    if (t == 0){
        points = 200; 
    } else if(t == 1){
        points = points * 2;
    } else {
        points = points;
    }

    char *roundName[] = {
        "BONUS",
        "DOUBLE",
        "REGULAR"
    };

    printf("Type\t: %s\nDICE\t: %d\nPOINTS\t: %d\n", roundName[t], dice, points);

}
