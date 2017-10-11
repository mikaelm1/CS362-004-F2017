#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main() {
    printf("Testing getCost()\n");
    // Run tests for a few random cards
    int cost = getCost(curse);
    if (cost == 0) {
        printf("getCost(): PASS when card is curse\n");
    } else {
        printf("getCost(): FAIL when card is curse. expected=0 got=%d\n", cost);
    }
    cost = getCost(gold);
    if (cost == 6) {
        printf("getCost(); PASS when card is gold\n");
    } else {
        printf("getCost(): FAIL when card is gold. expected=6 got=%d\n", cost);
    }
    cost = getCost(gardens);
    if (cost == 4) {
        printf("getCost(); PASS when card is gardens\n");
    } else {
        printf("getCost(): FAIL when card is gardens. expected=4 got=%d\n", cost);
    }
    cost = getCost(ambassador);
    if (cost == 3) {
        printf("getCost(); PASS when card is ambassador\n");
    } else {
        printf("getCost(): FAIL when card is ambassador. expected=3 got=%d\n", cost);
    }

    return 0;
}