#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main() {
    printf("Testing discardCard()\n");
    struct gameState state;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int randomSeed = 5;
    int player = 0;
    int trashFlag = 0;
    int handPos = 0;

    initializeGame(3, k, randomSeed, &state);
    // printf("last card in player's hand: %d\n", state.handCount[player]-1);
    int previousPlayedCount = state.playedCardCount;
    int previousHandCount = state.handCount[player];
    discardCard(handPos, player, &state, trashFlag);
    if (state.playedCardCount == previousPlayedCount + 1) {
        printf("discardCard(): PASS played card count incremented\n");
    } else {
        printf("discardCard(): FAIL played card count not incremented\n");
    }
    if (state.handCount[player] == previousHandCount - 1) {
        printf("discardCard(): PASS hand count decremented\n");
    } else {
        printf("discardCard(): FAIL hand count not decremented\n");
    }
    // call while trashing the card
    trashFlag = 1;
    discardCard(handPos, player, &state, trashFlag);
    previousPlayedCount = state.playedCardCount;
    // played count should not change when trashing card
    if (state.playedCardCount == previousPlayedCount) {
        printf("discardCard(): PASS played count unchnaged when trashing\n");
    } else {
        printf("discardCard(): FAIL played count changed when trashing\n");
    }
    return 0;
}