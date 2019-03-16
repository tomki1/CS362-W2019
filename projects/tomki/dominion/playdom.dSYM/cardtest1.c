/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

 #include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// This function checks whether Smithy adds 3 cards to the player's hand
int main() {

	printf("Testing if Smithy card adds 3 cards to hand\n");
	
	int k[10] = {smithy, village, remodel, great_hall, minion
			   , steward, ambassador, embargo, outpost, sea_hag};
	struct gameState G;
	int numPlayers2 = 2;
    int seed = 1000;
	int choice_1 = -1;
	int choice_2 = -1;
	int choice_3 = -1;
	int handPosition = -1;
	int *bonus = 0;
	int failed = 0;
		
	// initialize game 1
	initializeGame(numPlayers2, k, seed, &G);
	
	// player 0 has 2 cards in hand
	G.handCount[0] = 2;
	printf("Player has %d cards in hand\n", G.handCount[0]);

	// implement smithy card effect
	cardEffect(smithy, choice_1, choice_2, choice_3, &G, handPosition, bonus);
	printf("After playing Smithy, player has %d cards in hand\n", G.handCount[0]);

	// check how many cards player has in hand after playing smithy, player had 2 cards and after adding 3 cards to hand, and discarding Smithy, should have 4 cards
	if (G.handCount[0] == 4) {
		printf("Test passed.  Added 3 cards to hand after playing Smithy successfully\n");
	}
	else {
		printf("Test failed.  Did not add 3 cards to hand after playing Smithy\n");
		failed = 1;
	}
	
		
	// initialize game 2
	initializeGame(numPlayers2, k, seed, &G);
	
	// player 0 has 4 cards in hand
	G.handCount[0] = 4;
	printf("Player has %d cards in hand\n", G.handCount[0]);

	// implement smithy card effect
	cardEffect(smithy, choice_1, choice_2, choice_3, &G, handPosition, bonus);
	printf("After playing Smithy, player has %d cards in hand\n", G.handCount[0]);

	// check how many cards player has in hand after playing smithy, player had 4 cards and after adding 3 cards to hand, and discarding Smithy, should have 6 cards
	if (G.handCount[0] == 6) {
		printf("Test passed.  Added 3 cards to hand after playing Smithy successfully\n");
	}
	else {
		printf("Test failed.  Did not add 3 cards to hand after playing Smithy\n");
		failed = 1;
	}
	
	if (failed == 0) {
		printf("All tests passed!\n");
	}

	return 0;
}
