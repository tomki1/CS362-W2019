/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
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

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
	
	struct gameState G;

	
		printf("Setting game so 1 province remains and only 2 supplies are 0...\n");
	for (i = 0; i < 2; i++)
	{
		G.supplyCount[i] = 0;

	}

	for (i = 2; i < 25; i++)
	{
		G.supplyCount[i] = 1;

	}

	gameOver = isGameOver(&G);
	assert(gameOver == 0);
	printf("Test passes, gameOver is %d\n", gameOver);
	
	

	// game should not end if province supply pile has a card in it and there are only two supply piles empty
	printf("Setting game to have one province cards left in the supply pile and only two supply piles empty\n");
	G.supplyCount[province] = 1;
	G.supplyCount[0] = 0;
	G.supplyCount[1] = 0;

	for (int i = 2; i < 10; i ++) {
		G.supplyCount[i] = 1;
	}
	
	int gameOver = isGameOver(&G);
	assert (gameOver == 0);
	printf("Test passed, there are %d province cards in the supply pile and isGameOver is %d\n", G.supplyCount[province], isGameOver(&G));
	
	// game should end if province supply pile is empty
	printf("Setting game to have no province cards left in the supply pile\n");
	G.supplyCount[province] = 0;
	int gameOver = isGameOver(&G);
	assert (gameOver == 1);
	printf("Test passed, there are %d province cards in the supply pile and isGameOver is %d\n", G.supplyCount[province], isGameOver(&G));
	
	
	// game should end when any three supply piles are empty
	
	
	printf("All tests passed!\n");

    return 0;
}