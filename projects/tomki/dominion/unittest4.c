/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

 #include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {
	
    int seed = 1000;
    int numPlayers2 = 2;
	int numPlayers3 = 3;
	int numPlayers4 = 4;
	struct gameState G;
	int k[10] = {smithy, village, remodel, great_hall, minion
               , steward, ambassador, embargo, outpost, sea_hag};

	
	
	// initialize game 1	
	initializeGame(numPlayers2, k, seed, &G);
	printf("Testing Victory card count for 2 players\n");
	
	assert (G.supplyCount[estate] == 8);
	printf("There are %d estate cards\n", G.supplyCount[estate]);
	assert (G.supplyCount[duchy] == 8);
	printf("There are %d duchy cards\n", G.supplyCount[duchy]);
	assert (G.supplyCount[province] == 8);
	printf("There are %d province cards\n", G.supplyCount[province]);

	// initialize game 2
	initializeGame(numPlayers3, k, seed, &G);
	printf("Testing Victory card count for 3 players\n");

	assert (G.supplyCount[estate] == 12);
	printf("There are %d estate cards\n", G.supplyCount[estate]);
	assert (G.supplyCount[duchy] == 12);
	printf("There are %d duchy cards\n", G.supplyCount[duchy]);
	assert (G.supplyCount[province] == 12);
	printf("There are %d province cards\n", G.supplyCount[province]);
	
	
	// initialize game 3
	initializeGame(numPlayers4, k, seed, &G);
	printf("Testing Victory card count for 4 players\n");

	assert (G.supplyCount[estate] == 12);
	printf("There are %d estate cards\n", G.supplyCount[estate]);
	assert (G.supplyCount[duchy] == 12);
	printf("There are %d duchy cards\n", G.supplyCount[duchy]);
	assert (G.supplyCount[province] == 12);
	printf("There are %d province cards\n", G.supplyCount[province]);
	
	printf("All tests passed.\n");
	return 0;
}


