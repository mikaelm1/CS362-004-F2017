#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main() {
    printf("Testing isGameOver(\n");
    struct gameState state;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int randomSeed = 5;

    initializeGame(3, k, randomSeed, &state);
    int gameOver = isGameOver(&state);
    if (gameOver) {
        printf("isGameOver(): FAIL before making any moves\n");
    } else {
        printf("isGameOver(): PASS before making moves\n");
    }
    // set province count to 0 to simulate game over
    int provinceCount = state.supplyCount[province];
    // printf("province count before: %d\n", provinceCount);
    state.supplyCount[province] = 0;
    gameOver = isGameOver(&state);
    if (!gameOver) {
        printf("isGameOver(): FAIL when province count is 0\n");
    } else {
        printf("isGameOver(): PASS when province count is 0\n");
    } 
    // reset province count
    state.supplyCount[province] = provinceCount;
    // simulate 3 empty piles
    int i;
    for (i=0; i<3; i++) {
        state.supplyCount[i] = 0;
    }
    gameOver = isGameOver(&state);
    if (!gameOver) {
        printf("isGameOver(): FAIL when 3 pile count is 0\n");
    } else {
        printf("isGameOver(): PASS when 3 pile count is 0\n");
    } 
    return 0;
}