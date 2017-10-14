#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main() {
    printf("Testing card council room\n");
    // the tests will fail because bugs were intentionally added to smithy
    // in previous assignment
    struct gameState state;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int randomSeed = 5;
    int player = 0;
    int otherPlayer = 1;
    int handPos = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    // will loop infinitely if choice1 is either too expensive or not in supply
    initializeGame(2, k, randomSeed, &state);
    int prevHandCount = state.handCount[player];
    int prevHandCountOtherPlayer = state.handCount[otherPlayer];
    // printf("%d\n", prevHandCount);
    int prevBuy = state.numBuys;
    cardEffect(council_room, choice1, choice2, choice3, &state, handPos, &bonus);
    if (state.numBuys == prevBuy + 1) {
        printf("council room: PASS number of buys incremented\n");
    } else {
        printf("council room: FAIL number of buys not incremented\n");
    }
    // player should have an extra 3 cards in hand (4 - council room card)
    if (state.handCount[player] == prevHandCount + 3) {
        printf("council room: PASS player hand count expected=%d got=%d\n", prevHandCount+3, state.handCount[player]);
    } else {
        printf("council room: FAIL player hand count expected=%d got=%d\n", prevHandCount+3, state.handCount[player]);
    }
    if (state.handCount[otherPlayer] == prevHandCountOtherPlayer + 1) {
        printf("council room: PASS other player hand count expected=%d got=%d\n", prevHandCountOtherPlayer+1, state.handCount[otherPlayer]);
    } else {
        printf("council room: FAIL other player hand count expected=%d got=%d\n", prevHandCountOtherPlayer+1, state.handCount[otherPlayer]);
    }
    
    return 0;
}