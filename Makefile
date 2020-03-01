all: beep beeptrain

beep: beep.c
	gcc -Wall -o beep beep.c -lwiringPi

beeptrain: beeptrain.c
	gcc -Wall -o beeptrain beeptrain.c -lwiringPi
