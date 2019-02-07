/* -----------------------------------------------------------------------
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

 #include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {
	printf("testing getCost function\n");
	
	// check curse cost
	assert (getCost(curse) == 0);
	assert (getCost(0) == 0);
	printf("Test passed, cost of curse is %d\n", getCost(curse));
	
	
	// check estate cost
	assert (getCost(estate) == 2);
	assert (getCost(1) == 2);
	printf("Test passed, cost of estate is %d\n", getCost(estate));

	
	// check ambassador cost
	assert (getCost(ambassador) == 3);
	printf("Test passed, cost of ambassador is %d\n", getCost(ambassador));
	
	
	// check remodel cost
	assert (getCost(remodel) == 4);
	printf("Test passed, cost of remodel is %d\n", getCost(remodel));

	
	// check mine cost
	assert (getCost(mine) == 5);
	printf("Test passed, cost of mine is %d\n", getCost(mine));

	
	// check adventurer cost
	assert (getCost(adventurer) == 6);
	printf("Test passed, cost of adventurer is %d\n", getCost(adventurer));
	
	
	// check province cost
	assert (getCost(province) == 8);
	printf("Test passed, cost of province is %d\n", getCost(province));
	
	
	// check that none of the cards has a cost less than 0
	for (int i = 0; i < 26; i++) {
	assert(getCost(i) >= 0);
	}
	printf("Test passed, no cost is less than 0\n");
	
	
	// check that none of the cards has a cost of 1
	for (int i = 0; i < 26; i++) {
	assert(getCost(i) != 1);
	}
	printf("Test passed, no cost is equal to 1\n");

	
	// check that none of the cards has a cost of greater than 8
	for (int i = 0; i < 26; i++) {
	assert(getCost(i) < 9);
	}
	printf("Test passed, no cost greater than 8\n");

	
	printf("All tests passed!\n");

    return 0;
}
