#ifndef DICEGAME_H
#define DICEGAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    BONUS,
    DOUBLE,
    REGULAR
} ROUND_TYPE;

int getRandomNumber(int min, int max);
ROUND_TYPE getRoundType();
int getRoundPoints(ROUND_TYPE roundType);
void printPlayerPoints(int p1, int p2);
void printRoundInfo(ROUND_TYPE t, int dice, int points);

#endif
