#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


// returns 0 if card is of treasure type
int getOtherPlayer(int currentPlayer, int numPlayers) {
    int i;
    for (i = 0; i < numPlayers; i++) {
        if (i != currentPlayer) {
            return currentPlayer;
        }
    }
    return 0;
}

int main() {
    printf("Random Test for council room\n");
    struct gameState state;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int randomSeed = 5;
    int player = 0;
    int otherPlayer = 0;
    int numPlayers = 4;
    int i;
    int handPos;
    
    for (i=0; i<5000; i++) {
        randomSeed = floor(Random() * 500 + 1);
        initializeGame(numPlayers, k, randomSeed, &state);
        player = floor(Random() * numPlayers);
        state.deckCount[player] = floor(Random() * MAX_DECK);
        state.discardCount[player] = floor(Random() * MAX_DECK);
        state.handCount[player] = floor(Random() * MAX_HAND);
        otherPlayer = getOtherPlayer(player, numPlayers);
        handPos = floor(Random() * state.handCount[player]);
        int prevHandCount = state.handCount[player];
        int prevHandCountOtherPlayer = state.handCount[otherPlayer];
        int prevBuy = state.numBuys;
        // printf("handPos %d\n", handPos);
        council_roomEffect(&state, player, handPos);
        // smithy adds 3 cards to hand but smithy card is discarded
        if (state.numBuys == prevBuy + 1) {
            printf("PASS number of buys incremented\n");
        } else {
            printf("FAIL number of buys not incremented\n");
        }
        // player should have an extra 3 cards in hand (4 - council room card)
        if (state.handCount[player] == prevHandCount + 3) {
            printf("PASS player hand count expected=%d got=%d\n", prevHandCount+3, state.handCount[player]);
        } else {
            printf("FAIL player hand count expected=%d got=%d\n", prevHandCount+3, state.handCount[player]);
        }
        if (state.handCount[otherPlayer] == prevHandCountOtherPlayer + 1) {
            printf("PASS other player hand count expected=%d got=%d\n", prevHandCountOtherPlayer+1, state.handCount[otherPlayer]);
        } else {
            printf("FAIL other player hand count expected=%d got=%d\n", prevHandCountOtherPlayer+1, state.handCount[otherPlayer]);
        }
    }

    return 0;
}