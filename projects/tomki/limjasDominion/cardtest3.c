/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * cardtest3: cardtest3.c dominion.o rngs.o
 *      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

 #include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// This function tests whether village correctly draws a card and adds it to the player's hand
int main() {

	
	printf("Testing village card\n");
	
	int k[10] = {smithy, village, remodel, great_hall, minion
			   , steward, ambassador, embargo, outpost, sea_hag};
	struct gameState G;
	int numPlayers2 = 2;
    int seed = 1000;
	int choice_1 = -1;
	int choice_2 = -1;
	int choice_3 = -1;
	int *bonus = 0;
	int whoseTurn;
	int failed = 0;

	
	for (int i = 1; i < 11; i++) {
	// initialize game
	initializeGame(numPlayers2, k, seed, &G);
	whoseTurn = G.whoseTurn;

	
	G.phase = 0;
	if (G.numActions < 1) {
		G.numActions = 1;
	}
	
	G.handCount[whoseTurn] = i;
	G.hand[whoseTurn][0] = village;
	printf("Have %d cards in hand\n", G.handCount[whoseTurn]);
	cardEffect(village, choice_1, choice_2, choice_3, &G, 0, bonus);
	if (G.handCount[whoseTurn] == i) {
		// after playing the card, hand count should stay the same as before as we gained 1 card and discarded village
		printf("Test passed.  Played village, added 1 card, discarded village, and set player's hand to %d successfully\n\n", G.handCount[whoseTurn]);
	}
	else {
		printf("Test failed, player's hand has %d cards in it\n\n", G.handCount[whoseTurn]);
		failed = 1;
	}
	}
	
	
	
	
	
	// initialize game
	initializeGame(numPlayers2, k, seed, &G);
	whoseTurn = G.whoseTurn;

	
	G.phase = 0;
	if (G.numActions < 1) {
		G.numActions = 1;
	}
	
	G.handCount[whoseTurn] = 5;
	G.hand[whoseTurn][4] = village;
	
	printf("Have %d cards in hand\n", G.handCount[whoseTurn]);

	cardEffect(village, choice_1, choice_2, choice_3, &G, 4, bonus);
	if (G.handCount[whoseTurn] == 5) {
		// after playing the card, hand count should stay the same as before as we gained 1 card and discarded village	
		printf("Test passed.  Played village, added 1 card, discarded village, and set player's hand to %d successfully\n\n", G.handCount[whoseTurn]);
	}
	else {
		printf("Test failed, player's hand has %d cards in it\n\n", G.handCount[whoseTurn]);
		failed = 1;
	}
	
	// initialize game
	initializeGame(numPlayers2, k, seed, &G);
	whoseTurn = G.whoseTurn;

	
	G.phase = 0;
	if (G.numActions < 1) {
		G.numActions = 1;
	}
	
	G.handCount[whoseTurn] = 2;
	G.hand[whoseTurn][2] = village;
	
	printf("Have %d cards in hand\n", G.handCount[whoseTurn]);

	cardEffect(village, choice_1, choice_2, choice_3, &G, 2, bonus);
	if (G.handCount[whoseTurn] == 2) {
		// after playing the card, hand count should stay the same as before as we gained 1 card and discarded village
		printf("Test passed.  Played village, added 1 card, discarded village, and set player's hand to %d successfully\n\n", G.handCount[whoseTurn]);
	}
	else {
		printf("Test failed, player's hand has %d cards in it\n\n", G.handCount[whoseTurn]);
		failed = 1;	
	}
	
	
	if (failed == 0) {
		printf("All tests passed!\n");
	}
	return 0;
}
