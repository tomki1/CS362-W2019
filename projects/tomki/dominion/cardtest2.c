/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 *      gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

 #include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// This function tests whether adventurer correctly reveals 2 treasure cards by checking the player's coin count 
int main() {

	printf("Testing adventurer card\n\n");
	
	int k[10] = {adventurer, village, remodel, great_hall, minion
			   , steward, ambassador, embargo, outpost, sea_hag};
	struct gameState G;
	int numPlayers2 = 2;
    int seed = 1000;
	int choice_1 = -1;
	int choice_2 = -1;
	int choice_3 = -1;
	int whoseTurn;
	int failed = 0;
		
	// initialize game 1
	initializeGame(numPlayers2, k, seed, &G);
	whoseTurn = G.whoseTurn;
	
	
	G.phase = 0;
	if (G.numActions < 1) {
		G.numActions = 1;
	}
	
	G.handCount[whoseTurn] = 5;
	G.hand[whoseTurn][0] = smithy;
	G.hand[whoseTurn][1] = smithy;
	G.hand[whoseTurn][2] = estate;
	G.hand[whoseTurn][3] = adventurer;
	G.hand[whoseTurn][4] = village;
	
	G.deckCount[whoseTurn] = 4;
	G.deck[whoseTurn][0] = estate;
	G.deck[whoseTurn][1] = minion;
	G.deck[whoseTurn][2] = copper;
	G.deck[whoseTurn][3] = estate;
	
	G.discardCount[whoseTurn] = 2;
	G.discard[whoseTurn][0] = copper;
	G.discard[whoseTurn][1] = copper;
	
	
	G.coins = 0;
	printf("test 1\n");
	printf("Player has %d coins\n", G.coins);


	// implement adventurer card effect
	playCard(3, choice_1, choice_2, choice_3, &G);
	if (G.coins == 2) {
		printf("Test passed.  After playing adventuerer, player has %d coins\n\n", G.coins);
	}
	else {
		printf("Test failed.  After playing adventuerer, player has %d coins\n\n", G.coins);
		failed = 1;
	}
	
	// initialize game 2
	initializeGame(numPlayers2, k, seed, &G);
	whoseTurn = G.whoseTurn;
	
	G.phase = 0;
	if (G.numActions < 1) {
		G.numActions = 1;
	}
	
	G.handCount[whoseTurn] = 5;
	G.hand[whoseTurn][0] = silver;
	G.hand[whoseTurn][1] = adventurer;
	G.hand[whoseTurn][2] = copper;
	G.hand[whoseTurn][3] = estate;
	G.hand[whoseTurn][4] = village;
	
	G.deckCount[whoseTurn] = 4;
	G.deck[whoseTurn][0] = village;
	G.deck[whoseTurn][1] = copper;
	G.deck[whoseTurn][2] = minion;
	G.deck[whoseTurn][3] = estate;
	
	G.discardCount[whoseTurn] = 2;
	G.discard[whoseTurn][0] = gold;
	G.discard[whoseTurn][1] = gold;
	
	
	G.coins = 3;
	printf("test 2\n");
	printf("Player has %d coins\n", G.coins);


	// implement adventurer card effect
	playCard(1, choice_1, choice_2, choice_3, &G);
	if (G.coins == 7) {
		printf("Test passed. After playing adventuerer, player has %d coins\n\n", G.coins);
	}
	else {
		printf("Test failed.  After playing adventuerer, player has %d coins\n\n", G.coins);
		failed = 1;
	}
		
				
	// initialize game 3
	initializeGame(numPlayers2, k, seed, &G);
	whoseTurn = G.whoseTurn;
	
	G.phase = 0;
	if (G.numActions < 1) {
		G.numActions = 1;
	}
	
	G.handCount[whoseTurn] = 5;
	G.hand[whoseTurn][0] = village;
	G.hand[whoseTurn][1] = estate;
	G.hand[whoseTurn][2] = gold;
	G.hand[whoseTurn][3] = silver;
	G.hand[whoseTurn][4] = adventurer;
	
	G.deckCount[whoseTurn] = 4;
	G.deck[whoseTurn][0] = copper;
	G.deck[whoseTurn][1] = village;
	G.deck[whoseTurn][2] = minion;
	G.deck[whoseTurn][3] = estate;
	
	G.discardCount[whoseTurn] = 2;
	G.discard[whoseTurn][0] = gold;
	G.discard[whoseTurn][1] = ambassador;
	
	
	G.coins = 5;
	printf("test 3\n");
	printf("Player has %d coins\n", G.coins);


	// implement adventurer card effect
	playCard(4, choice_1, choice_2, choice_3, &G);
	if (G.coins == 9){
		printf("Test passed.  After playing adventuerer, player has %d coins\n\n", G.coins);
	}
	else {
		printf("Test failed.  After playing adventuerer, player has %d coins\n\n", G.coins);
		failed = 1;
	}
	
	
	// initialize game 4
	initializeGame(numPlayers2, k, seed, &G);
	whoseTurn = G.whoseTurn;
	
	G.phase = 0;
	if (G.numActions < 1) {
		G.numActions = 1;
	}
	
	G.handCount[whoseTurn] = 5;
	G.hand[whoseTurn][0] = adventurer;
	G.hand[whoseTurn][1] = estate;
	G.hand[whoseTurn][2] = silver;
	G.hand[whoseTurn][3] = estate;
	G.hand[whoseTurn][4] = village;
	
	G.deckCount[whoseTurn] = 4;
	G.deck[whoseTurn][0] = gold;
	G.deck[whoseTurn][1] = village;
	G.deck[whoseTurn][2] = minion;
	G.deck[whoseTurn][3] = estate;
	
	G.discardCount[whoseTurn] = 2;
	G.discard[whoseTurn][0] = gold;
	G.discard[whoseTurn][1] = silver;
	
	
	G.coins = 2;
	printf("test 4\n");
	printf("Player has %d coins\n", G.coins);


	// implement adventurer card effect
	playCard(0, choice_1, choice_2, choice_3, &G);
	if (G.coins == 8) {
		printf("Test passed.  After playing adventuerer, player has %d coins\n\n", G.coins);
	}
	else {
		printf("Test failed.  After playing adventuerer, player has %d coins\n\n", G.coins);
		failed = 1;
	}
	
	// initialize game 5
	initializeGame(numPlayers2, k, seed, &G);
	whoseTurn = G.whoseTurn;
	
	G.phase = 0;
	if (G.numActions < 1) {
		G.numActions = 1;
	}
	
	G.handCount[whoseTurn] = 5;
	G.hand[whoseTurn][0] = adventurer;
	G.hand[whoseTurn][1] = estate;
	G.hand[whoseTurn][2] = silver;
	G.hand[whoseTurn][3] = estate;
	G.hand[whoseTurn][4] = village;
	
	G.deckCount[whoseTurn] = 4;
	G.deck[whoseTurn][0] = gold;
	G.deck[whoseTurn][1] = village;
	G.deck[whoseTurn][2] = minion;
	G.deck[whoseTurn][3] = estate;
	
	G.discardCount[whoseTurn] = 2;
	G.discard[whoseTurn][0] = estate;
	G.discard[whoseTurn][1] = minion;
	
	
	G.coins = 2;
	printf("test 5\n");
	printf("Player has %d coins\n", G.coins);


	// implement adventurer card effect
	playCard(0, choice_1, choice_2, choice_3, &G);
	if (G.coins == 5) {
		printf("Test passed.  After playing adventuerer, player has %d coins\n\n", G.coins);
	}
	else {
		printf("Test failed.  After playing adventuerer, player has %d coins\n\n", G.coins);
		failed = 1;
	}
		
	// initialize game 6
	initializeGame(numPlayers2, k, seed, &G);
	whoseTurn = G.whoseTurn;
	
	G.phase = 0;
	if (G.numActions < 1) {
		G.numActions = 1;
	}
	
	G.handCount[whoseTurn] = 5;
	G.hand[whoseTurn][0] = adventurer;
	G.hand[whoseTurn][1] = estate;
	G.hand[whoseTurn][2] = silver;
	G.hand[whoseTurn][3] = estate;
	G.hand[whoseTurn][4] = village;
	
	G.deckCount[whoseTurn] = 4;
	G.deck[whoseTurn][0] = village;
	G.deck[whoseTurn][1] = village;
	G.deck[whoseTurn][2] = minion;
	G.deck[whoseTurn][3] = estate;
	
	G.discardCount[whoseTurn] = 2;
	G.discard[whoseTurn][0] = estate;
	G.discard[whoseTurn][1] = minion;
	
	
	G.coins = 2;
	printf("test 6\n");
	printf("Player has %d coins\n", G.coins);


	// implement adventurer card effect
	playCard(0, choice_1, choice_2, choice_3, &G);
	if (G.coins == 2) {
		printf("Test passed.  After playing adventuerer, player has %d coins\n\n", G.coins);
	}
	else {
		printf("Test failed.  After playing adventuerer, player has %d coins\n\n", G.coins);
		failed = 1;
	}
	if ( failed == 0) {
	printf("All tests passed!\n");
	}
	
	return 0;
}
