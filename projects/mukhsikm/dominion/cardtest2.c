#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

// returns 0 if card is of treasure type
int isTreasureCard(int card) {
    if (card == copper || card == silver || card == gold) {
        return 0;
    }
    return 1;
}

int main() {
    printf("Testing card adventurer\n");
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
    // int prevDeckCount = state.deckCount[player];
    cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, &bonus);
    // adventurer is supposed to add 2 treasure cards to hand
    if (state.handCount[player] == prevHandCount + 2) {
        printf("adventurer: PASS hand count=%d expected=%d\n", state.handCount[player], prevHandCount+2);
    } else {
        printf("adventurer: FAIL hand count=%d expected=%d\n", state.handCount[player], prevHandCount+2);
    }
    // last two cards in hand should be treasure cards
    int lastCard = state.hand[player][state.handCount[player]-1];
    int beforeLast = state.hand[player][state.handCount[player]-2];
    if (isTreasureCard(lastCard) == 0) {
        printf("adventurer: PASS last card is treasure\n");
    } else {
        printf("adventurer: FAIL last card is not treasure\n");
    }
    if (isTreasureCard(beforeLast) == 0) {
        printf("adventurer: PASS before last card is treasure\n");
    } else {
        printf("adventurer: FAIL before last card is not treasure\n");
    }
    return 0;
}