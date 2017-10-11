#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main() {
    printf("Testing card smithy\n");
    // the tests will fail because bugs were intentionally added to smithy
    // in previous assignment
    struct gameState state;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int randomSeed = 5;
    int player = 0;
    int handPos = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

    initializeGame(3, k, randomSeed, &state);
    int prevHandCount = state.handCount[player];
    int prevDeckCount = state.deckCount[player];
    cardEffect(smithy, choice1, choice2, choice3, &state, handPos, &bonus);
    // smithy adds 3 cards to hand but smithy card is discarded
    if (prevHandCount + 2 == state.handCount[player]) {
        printf("smithy: PASS hand count increased by 3\n");
    } else {
        printf("smithy: FAIL hand count=%d expected=%d\n", state.handCount[player], prevHandCount+2);
    }
    if (prevDeckCount - 3 == state.deckCount[player]) {
        printf("smithy: PASS deck count=%d expected=%d\n", state.deckCount[player], prevDeckCount-3);
    } else {
        printf("smithy: FAIL deck count=%d expected=%d\n", state.deckCount[player], prevDeckCount-3);
    }
    return 0;
}