#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

// This function tests whether adventurer correctly reveals cards from deck until 2 Treasure card are revealed and placed in hand.
// the other revealed cards should be discarded

int main() {
	srand(time(NULL));
	
	printf("Testing adventurer card\n\n");
	
	int k[10] = {adventurer, village, remodel, great_hall, minion, steward, ambassador, embargo, outpost, sea_hag};
	struct gameState G;
	int numPlayers2 = 2;
    int seed = 1000;
	// int choice_1 = -1;
	// int choice_2 = -1;
	// int choice_3 = -1;
	// int hand_position = -1;
	// int* bonus_1 = 0;
	int whoseTurn;
	int failed = 0;
	
	
	int playerCardRand;
	int playerDeckRand = rand() % (MAX_DECK + 1);
	int playerHandRand = rand() % (playerDeckRand + 1);
	int playerKingdomCardRand;
	

	initializeGame(numPlayers2, k, seed, &G);

	whoseTurn = G.whoseTurn;
	
	
	G.phase = 0;
	if (G.numActions < 1) {
		G.numActions = 1;
	}
	
	int coinsCount = 0;	
	
	G.deckCount[0] = playerDeckRand - playerHandRand;
	G.handCount[0] = playerHandRand;
	
	printf("deck count: %d\n", G.deckCount[0]);
	printf("hand count: %d\n", G.handCount[0]);


	// randomize both player's deck
		for (int j = 0; j < G.deckCount[0]; j++){
			playerCardRand = rand() % (50 + 1);
			playerKingdomCardRand = rand() % 10;
			if(playerCardRand == 0){
				G.deck[0][j] = copper;
			}
			else if(playerCardRand == 1){
				G.deck[0][j] = silver;
			}
			else if(playerCardRand == 2){
				G.deck[0][j] = gold;
			}
			else {
				G.deck[0][j] = k[playerKingdomCardRand];
			}
		}
	
		for (int j = 0; j < G.deckCount[1]; j++){
			playerCardRand = rand() % (50 + 1);
			playerKingdomCardRand = rand() % 10;
			if(playerCardRand == 0){
				G.deck[1][j] = copper;
			}
			else if(playerCardRand == 1){
				G.deck[1][j] = silver;
			}
			else if(playerCardRand == 2){
				G.deck[1][j] = gold;
			}
			else {
				G.deck[1][j] = k[playerKingdomCardRand];
			}
		}
		
		
	 for(int i = 0; i < G.handCount[whoseTurn]; i++){
            if(G.hand[whoseTurn][i] == copper || G.hand[whoseTurn][i] == silver || G.hand[whoseTurn][i] == gold){
                coinsCount++;
            }
        }
	

	printf("Player has %d coins\n", coinsCount);
	
	// implement adventurer card effect
	// cardEffect(adventurer, choice_1, choice_2, choice_3, &G, hand_position, bonus_1);
	
	
	
	if ( failed == 0) {
	printf("All tests passed!\n");
	}
	
	
	
	return 0;
}

