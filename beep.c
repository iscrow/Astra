#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define PIN 3

int main (int argc, char *argv[])
{
	int NUM, ON, OFF; 
		
	if (argc < 2) { NUM = 1;  } else { NUM = atoi(argv[1]); }
	if (argc < 3) { ON = 100; } else { ON = atoi(argv[2]); }
	if (argc < 4) { OFF = 100;  } else { OFF = atoi(argv[3]); }

	// Checking if all the numbers are positive of not 
	if (NUM < 0 || ON < 0 || OFF < 0)	
	{ 
		printf("Enter only positive arguments"); 
		return 1; 
	} 
	wiringPiSetup () ;
	pinMode (PIN, OUTPUT) ;

//	printf("%d | %d | %d\n", NUM, ON, OFF);

	int i=0;
	for (i=0; i<NUM; i++)
	{
		digitalWrite (PIN, HIGH);
		delay (ON);
		digitalWrite (PIN,	LOW);
		if (i < NUM-1) { delay (OFF); }
	}
	return 0 ;
}

