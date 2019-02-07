/* -----------------------------------------------------------------------
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

 #include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// This function tests whether playing council room increases buys by 1
int main() {

	
	printf("Testing council room card\n");
	
	int k[10] = {council_room, village, remodel, great_hall, minion
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


	// initialize game
	initializeGame(numPlayers2, k, seed, &G);
	whoseTurn = G.whoseTurn;

	
	G.phase = 0;
	if (G.numActions < 1) {
		G.numActions = 1;
	}
	

	G.hand[whoseTurn][0] = council_room;
	G.numBuys = 1;
	printf("Testing with %d buy(s) before playing card\n", G.numBuys);

	
	// play council room card
	cardEffect(council_room, choice_1, choice_2, choice_3, &G, 0, bonus);
	if (G.numBuys == 2) {
		// after playing council room card, buys should increase from 1 to 2
		printf("Test passed.  Played council room, number of buys updated to %d successfully\n\n", G.numBuys);
	}
	else {
		printf("Test failed. number of buys updated to %d\n\n", G.numBuys);
		failed = 1;
	}
	
	// initialize game
	initializeGame(numPlayers2, k, seed, &G);
	whoseTurn = G.whoseTurn;

	
	G.phase = 0;
	if (G.numActions < 1) {
		G.numActions = 1;
	}
	

	G.hand[whoseTurn][2] = council_room;
	G.numBuys = 2;
	printf("Testing with %d buy(s) before playing card\n", G.numBuys);

	
	// play council room card
	cardEffect(council_room, choice_1, choice_2, choice_3, &G, 2, bonus);
	if (G.numBuys == 3) {
		// after playing council room card, buys should increase from 2 to 3
		printf("Test passed.  Played council room, number of buys updated to %d successfully\n\n", G.numBuys);
	}
	else {
		printf("Test failed. number of buys updated to %d\n\n", G.numBuys);
		failed = 1;
	}
	
	// initialize game
	initializeGame(numPlayers2, k, seed, &G);
	whoseTurn = G.whoseTurn;

	
	G.phase = 0;
	if (G.numActions < 1) {
		G.numActions = 1;
	}
	

	G.hand[whoseTurn][4] = council_room;
	G.numBuys = 3;
	printf("Testing with %d buy(s) before playing card\n", G.numBuys);

	// play council room card
	cardEffect(council_room, choice_1, choice_2, choice_3, &G, 4, bonus);
	if (G.numBuys == 4) {
		// after playing council room card, buys should increase from 3 to 4
		printf("Test passed.  Played council room, number of buys updated to %d successfully\n\n", G.numBuys);
	}
	else {
		printf("Test failed. number of buys updated to %d\n\n", G.numBuys);
		failed = 1;
	}
	
	
	// initialize game
	initializeGame(numPlayers2, k, seed, &G);
	whoseTurn = G.whoseTurn;

	
	G.phase = 0;
	if (G.numActions < 1) {
		G.numActions = 1;
	}
	

	G.hand[whoseTurn][4] = council_room;
	G.numBuys = 8;
	printf("Testing with %d buy(s) before playing card\n", G.numBuys);

	// play council room card
	cardEffect(council_room, choice_1, choice_2, choice_3, &G, 4, bonus);
	if (G.numBuys == 9) {
		// after playing council room card, buys should increase from 3 to 4
		printf("Played council room, number of buys updated to %d successfully\n\n", G.numBuys);
	}
	else {
		printf("Test failed. number of buys updated to %d\n\n", G.numBuys);
		failed = 1;
	}
	
	if (failed == 0) {
		printf("All tests passed!\n");
	}

	return 0;
}
