#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


// returns 0 if card is of treasure type
int isTreasureCard(int card) {
    if (card == copper || card == silver || card == gold) {
        return 0;
    }
    return 1;
}

int main() {
    printf("Random Test for adventurer\n");
    struct gameState state;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int randomSeed = 5;
    int player = 0;
    int numPlayers = 4;
    int tempHand[MAX_HAND]; 
    int drawnTreasure = 2;
    int cardDrawn = 0;
    int z;  // this is the counter for the temp hand
    int i, j;

    SelectStream(2);
    PutSeed(3);
    
    for (i=0; i<50000; i++) {
        z = 0;
        drawnTreasure = floor(Random() * 3);
        randomSeed = floor(Random() * 500 + 1);
        initializeGame(numPlayers, k, randomSeed, &state);
        player = floor(Random() * numPlayers);
        struct gameState pre;
        memcpy (&pre, &state, sizeof(struct gameState));
        adventurerEffect(&state, player, drawnTreasure, z, cardDrawn, tempHand);
        // printf("Hand count: %d\n", state.handCount[player]);
        // printf("Top card: %d\n", state.hand[player][state.handCount[player]-1]);
        pre.handCount[player] += 2;
        // printf("pre hand count: %d\n", pre.handCount[player]);
        if (pre.handCount[player] != state.handCount[player]) {
            printf("FAIL expected hand count=%d got=%d\n", pre.handCount[player], state.handCount[player]);
        } else {
            printf("PASS expected hand count=%d got=%d\n", pre.handCount[player], state.handCount[player]);
        }
        // last two cards in hand should be treasure cards
        int lastCard = state.hand[player][state.handCount[player]-1];
        int beforeLast = state.hand[player][state.handCount[player]-2];
        if (isTreasureCard(lastCard) == 0) {
            printf("PASS last card is treasure\n");
        } else {
            printf("FAIL last card is not treasure\n");
        }
        if (isTreasureCard(beforeLast) == 0) {
            printf("PASS before last card is treasure\n");
        } else {
            printf("FAIL before last card is not treasure\n");
        }
    }

    return 0;
}