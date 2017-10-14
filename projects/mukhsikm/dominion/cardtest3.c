#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main() {
    printf("Testing card feast\n");
    // the tests will fail because bugs were intentionally added to smithy
    // in previous assignment
    struct gameState state;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int randomSeed = 5;
    int player = 0;
    int handPos = 0;
    int choice1 = village, choice2 = 0, choice3 = 0, bonus = 0;
    // will loop infinitely if choice1 is either too expensive or not in supply
    initializeGame(3, k, randomSeed, &state);
    int prevHandCount = state.handCount[player];
    int prevSupplyCount = state.supplyCount[village];
    // printf("%d\n", state.coins);
    // feast supposed to give 5 coins to player and let player
    // purchase one card
    cardEffect(feast, choice1, choice2, choice3, &state, handPos, &bonus);
    // printf("%d\n", state.coins);
    if (state.coins == 5) {
        printf("feast: PASS 5 coins added\n");
    } else {
        printf("feast: FAIL expected 5 coins got=%d\n", state.coins);
    }
    if (state.handCount[player] == prevHandCount) {
        printf("feast: PASS hand count unchanged\n");
    } else {
        printf("feast: FAIL expected hand count=%d got=%d\n", prevHandCount, state.handCount[player]);
    }
    if (state.supplyCount[village] == prevSupplyCount - 1) {
        printf("feast: PASS supply count decremented\n");
    } else {
        printf("feast: FAIL supply count not decremented\n");
    }
    int lastCard = state.hand[player][state.handCount[player]-1];
    if (lastCard == village) {
        printf("feast: PASS purchased village\n");
    } else {
        printf("feast: FAIL village not purchased\n");
    }
    
    return 0;
}