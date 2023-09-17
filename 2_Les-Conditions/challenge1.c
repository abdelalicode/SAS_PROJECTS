#include <stdio.h>

int main(void)
{
	int nombre;

	printf("Entrer le nombre: ");
	scanf("%d", &nombre);

	if (nombre % 2 == 0)
		printf("Le nombre %d est paire\n", nombre);
	else 
		printf("Le nombre %d est impaire\n", nombre);

	return 0;
}
