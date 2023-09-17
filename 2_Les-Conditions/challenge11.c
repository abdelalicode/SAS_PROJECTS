#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int jour;

	srand( time(NULL) );
	jour = ( rand() % 6 ) + 1;

	switch (jour) {
		case 1: 
			printf("Dimanche\n");
			break;
		case 2:
			printf("Lundi\n");
			break;
		case 3:
			printf("Mardi\n");
			break;
		case 4:
			printf("Mercredi\n");
			break;
		case 5:
			printf("Jeudi\n");
			break;
		case 6:
			printf("Vendredi\n");
			break;
		case 7:
			printf("Samedi\n");
			break;
		}
	return 0;
}
	

