#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define PIN 3

int main (int argc, char *argv[])
{
	wiringPiSetup () ;
	pinMode (PIN, OUTPUT) ;

	int i=0;
	bool on=true;
	int state=HIGH;

	for (i=1; i<argc; i++)
	{
		if (on) { state=HIGH; } else { state=LOW; }
		digitalWrite (PIN, state);
		delay (atoi(argv[i]));
		on=!on;
	}
	digitalWrite (PIN, LOW);

	return 0 ;
}

