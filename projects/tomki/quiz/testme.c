/*
name: Kimberly Tom
class: CS 362
date: 2/7/19
Random Testing quiz
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
	
	char character;
	
	// generates a random character in the ascii table with codes 0 - 255
	character = rand() % 256;
	
    return character;
}

char *inputString()
{
    // TODO: rewrite this function
	
	// create a character string that holds 6 characters
	static char charString[6];
	
	// create a string that holds the letters in the target string
	char targetString[] = "reset";

	// initialize charString to null
	for (int i = 0; i < 6; i++) {
		charString[i] = '\0';
	}
	
	// randomly generate a character from the target string and put it in i position of character string
	for (int i = 0; i < 6; i++) {
		
		charString[i] = targetString[rand() % 6];
		
	}
	
	return charString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
