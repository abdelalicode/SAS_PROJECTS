#include <stdio.h>

int main(void)
{
	int nombre;
	int cent, dix, unit;
	int reversed;

	printf("Entrer nombre de 3 chiffres: ");
	scanf("%d", &nombre);

	cent = nombre / 100;
	dix = (nombre / 10) % 10;
	unit = nombre % 10;

	reversed = (unit * 100) + (dix * 10) + cent;

	printf("L'inverse du nombre est: %d\n", reversed);

	return 0;
}


