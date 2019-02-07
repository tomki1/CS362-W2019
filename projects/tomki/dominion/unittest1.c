/* -----------------------------------------------------------------------
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

 #include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {
	
	struct gameState G;
	int checkGameOver = 0;
	int supplyPileEmpty = 0;
	int failed = 0;
	
	printf("Testing isGameOver function\n\n");
	// game should end if province supply pile is empty
	printf("Setting game to have 0 province cards left in the supply pile\n");
	G.supplyCount[province] = 0;
	checkGameOver = isGameOver(&G);
	if (checkGameOver == 1) {
		printf("Test passed, there are %d province cards in the supply pile and isGameOver is %d\n\n", G.supplyCount[province], isGameOver(&G));
	}
	else {
		printf("Test failed. There are %d province cards in the supply pile and isGameOver is %d\n\n", G.supplyCount[province], isGameOver(&G));	
		failed = 1;
	}
	
	
	// game should not end if province pile has a card in it and there are only two supply piles empty
	printf("Setting game to have one province card left in the supply pile and only two supply piles empty\n");
	G.supplyCount[province] = 1;
	
	// set 2 supply piles to have 0 cards
	G.supplyCount[0] = 0;
	G.supplyCount[1] = 0;

	// set rest of supply piles to have 1 card
	for (int i = 2; i < 25; i ++) {
		G.supplyCount[i] = 1;
	}
	
	supplyPileEmpty = 0;
	for (int i = 0; i < 25; i++) {
	if (G.supplyCount[i] == 0)
		supplyPileEmpty++;
	}
	
	checkGameOver = isGameOver(&G);
	if (checkGameOver == 0) {
		printf("Test passed, there are %d province cards in supply pile, %d empty supply piles, and isGameOver is %d\n\n", G.supplyCount[province], supplyPileEmpty, isGameOver(&G));
	}
	else {
		printf("Test failed. There are %d province cards in supply pile, %d empty supply piles, and isGameOver is %d\n\n", G.supplyCount[province], supplyPileEmpty, isGameOver(&G));
		failed = 1;

	}
	
	// game should end if there is a province card left in supply pile and 3 supply piles are empty
	printf("Setting game to have 1 province card in supply pile and 3 supply piles are empty\n");
	G.supplyCount[province] = 1;
	
	// set 3 supply piles to have 0 cards
	G.supplyCount[0] = 0;
	G.supplyCount[1] = 0;
	G.supplyCount[2] = 0;


	// set rest of supply piles to have 1 card
	for (int i = 3; i < 25; i ++) {
		G.supplyCount[i] = 1;
	}
	
	supplyPileEmpty = 0;
	for (int i = 0; i < 25; i++) {
	if (G.supplyCount[i] == 0)
		supplyPileEmpty++;
	}
	
	checkGameOver = isGameOver(&G);
	if (checkGameOver == 1) {
		printf("Test passed, there are %d province cards left in supply pile, %d empty supply piles, and isGameOver is %d\n\n", G.supplyCount[province], supplyPileEmpty, isGameOver(&G));
	}
	else {
		printf("Test failed, there are %d province cards left in supply pile, %d empty supply piles, and isGameOver is %d\n\n", G.supplyCount[province], supplyPileEmpty, isGameOver(&G));
		failed = 1;

	}
	
	
	if (failed == 0) {
		printf("All tests passed!\n");
	}
	
    return 0;
}
