#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main() {
    printf("Testing drawCard()\n");
    struct gameState state;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int randomSeed = 5;
    int player = 0;

    initializeGame(3, k, randomSeed, &state);
    int previousHandCount = state.handCount[player];
    int previousDeckCount = state.deckCount[player];
    drawCard(player, &state);
    if (state.handCount[player] != previousHandCount + 1) {
        printf("drawCard(): FAIL hand count not incremented\n");
    } else {
        printf("drawCard(): PASS hand count incremented\n");
    }
    if (state.deckCount[player] != previousDeckCount - 1) {
        printf("drawCard(): FAIL deck count not decremented\n");
    } else {
        printf("drawCard(): PASS deck count decremented\n");
    }
    // simulate emtpy deck for player
    state.deckCount[player] = 0;
    drawCard(player, &state);
    if (state.discardCount[player] == 0) {
        printf("drawCard(): PASS when deck empty before drawing\n");
    } else {
        printf("drawCard(): FAIL when deck empty before drawing\n");
    }
    return 0;
}