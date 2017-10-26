#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


int main() {
    printf("Random Test for smithy\n");
    struct gameState state;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int randomSeed = 5;
    int player = 0;
    int numPlayers = 4;
    int i;
    int handPos;

    SelectStream(2);
    PutSeed(3);
    
    // initializeGame(numPlayers, k, randomSeed, &state);
    for (i=0; i<5000; i++) {
        randomSeed = floor(Random() * 500 + 1);
        initializeGame(numPlayers, k, randomSeed, &state);
        player = floor(Random() * numPlayers);
        state.deckCount[player] = floor(Random() * MAX_DECK);
        state.discardCount[player] = floor(Random() * MAX_DECK);
        state.handCount[player] = floor(Random() * MAX_HAND);
        handPos = floor(Random() * state.handCount[player]);
        int prevHandCount = state.handCount[player];
        int prevDeckCount = state.deckCount[player];
        // printf("handPos %d\n", handPos);
        smithyEffect(&state, handPos, player);
        // smithy adds 3 cards to hand but smithy card is discarded
        if (prevHandCount + 2 == state.handCount[player]) {
            printf("PASS hand count increased by 3\n");
        } else {
            printf("FAIL hand count=%d expected=%d\n", state.handCount[player], prevHandCount+2);
        }
        if (prevDeckCount - 3 == state.deckCount[player]) {
            printf("PASS deck count=%d expected=%d\n", state.deckCount[player], prevDeckCount-3);
        } else {
            printf("FAIL deck count=%d expected=%d\n", state.deckCount[player], prevDeckCount-3);
        }
    }

    return 0;
}