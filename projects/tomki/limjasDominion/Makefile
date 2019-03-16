CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
 
cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g  randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g  randomtestcard2.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	
	
	
testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

randomtestad: randomtestadventurer.c playdom
	echo "GCOV for only randomtestadventurer" >> randomtestadventurer.out
	gcov randomtestadventurer.c >> randomtestadventurer.out
	echo "total GCOV after randomtestadventurer" >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomtest1: randomtestcard1.c playdom
	echo "GCOV for only randomtestcard1" >> randomtestcard1.out
	gcov randomtestcard1.c >> randomtestcard1.out
	echo "total GCOV after randomtestcard1" >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

randomtest2: randomtestcard2.c playdom
	echo "GCOV for only randomtestcard2" >> randomtestcard2.out
	gcov randomtestcard2.c >> randomtestcard2.out
	echo "total GCOV after randomtestcard2" >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out
	
	
unittest: 
	./unittest1 &> unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gov >> unittestresults.out

cardtest1results: cardtest1

	cardtest1
	echo "-------------------" >> unittestresult.out
	echo "cardtest1" >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	echo "-------------------" unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	echo >> unittestresult.out
        

cardtest4results: cardtest4

	cardtest4
	echo "-------------------" >> unittestresult.out
	echo "cardtest4" >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	echo "-------------------" unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	echo >> unittestresult.out



cardtestresults: cardtest1 cardtest4
	rm -f unittestresult.out
	echo "---------------------------------------------------" >> unittestresult.out
	echo -n "Assignment 3 Unit Test Results" >> unittestresult.out
	echo "---------------------------------------------------" >> unittestresult.out

	cardtest1
	echo "-------------------" >> unittestresult.out
	echo "cardtest1" >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	echo "-------------------" unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	echo >> unittestresult.out
        
	cardtest4
	echo "-------------------" >> unittestresult.out
	echo "cardtest4" >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	echo "-------------------" unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	echo >> unittestresult.out

unittestresults: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	rm -f unittestresult.out
	echo "---------------------------------------------------" >> unittestresult.out
	echo -n "Assignment 3 Unit Test Results" >> unittestresult.out
	echo "---------------------------------------------------" >> unittestresult.out

	unittest1
	echo "-------------------" >> unittestresult.out
	echo "unittest1" >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	echo "-------------------" unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	echo >> unittestresult.out

	unittest2
	echo "-------------------" >> unittestresult.out
	echo "unittest2" >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	echo "-------------------" unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	echo >> unittestresult.out

	unittest3
	echo "-------------------" >> unittestresult.out
	echo "unittest3" >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	echo "-------------------" unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	echo >> unittestresult.out

	unittest4
	echo "-------------------" >> unittestresult.out
	echo "unittest4" >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	echo "-------------------" unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	echo >> unittestresult.out

	cardtest1
	echo "-------------------" >> unittestresult.out
	echo "cardtest1" >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	echo "-------------------" unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	echo >> unittestresult.out

	cardtest2
	echo "-------------------" >> unittestresult.out
	echo "cardtest2" >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	echo "-------------------" unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	echo >> unittestresult.out

	cardtest3
	echo "-------------------" >> unittestresult.out
	echo "cardtest3" >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	echo "-------------------" unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	echo >> unittestresult.out

	cardtest4
	echo "-------------------" >> unittestresult.out
	echo "cardtest4" >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	echo "-------------------" unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	echo >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)


all: playdom player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard1 randomtestcard2 randomtestadventurer

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out unittest1 unittest1.exe unittest2 unittest2.exe unittest3 unittest3.exe unittest4 unittest4.exe cardtest1 cardtest1.exe cardtest2 cardtest2.exe cardtest3 cardtest3.exe cardtest4 cardtest4.exe randomtestcard1 randomtestcard1.exe randomtestcard2 randomtestcard2.exe randomtestadventurer randomtestadventurer.exe randomtestadventurer.out randomtestcard1.out randomtestcard2.out
