/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
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
	
	int playerTurn = 0;
	G.whoseTurn = 0;
	
	printf("Testing whoseTurn function\n");
	
	// for each iteration, check if whoseTurn returns correctly which player's turn it is, then increment the turn and player's turn
	for (int i = 0; i < 20; i++) {
		
		assert (whoseTurn(&G) == playerTurn);
		printf("The turn is %d and it is player %d turn\n", playerTurn, G.whoseTurn);
		printf("incrementing turn...\n");
		playerTurn = playerTurn + 1;
		G.whoseTurn = G.whoseTurn + 1;
	}
	
	
	printf("All tests passed.\n");
	
	return 0;
}


