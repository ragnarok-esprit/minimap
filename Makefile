prog:main.o fonction.o
	gcc main.o fonction.o -o prog -g  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf 

main.o:main.c
	gcc -c main.c -g
chrono.o:fonction.c
	gcc -c fonction.c -g
