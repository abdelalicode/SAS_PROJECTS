#include <stdio.h>

int main(void)
{
	int nombres[10];
	
	printf("Entrer 10 nombres entiers.\n");

	for (int i = 0; i < 10; i++)
	{
		printf(" Entrer le nombre %d: ", i + 1);
		scanf("%d", &nombres[i]);
	}

	int max = 0;

	//Calculer le max d'elements du tableau
	for (int i = 0; i < 10; i++)
	{
		if (nombres[i] > max)
			max = nombres[i];
	}

	int min = nombres[0];
	// Calculer le min d'elements du tableau
	for (int i = 0; i < 10; i++)
	{
		if (nombres[i] < min)
		{
			min = nombres[i];
		}
	}
	// Afficher les elements du tableayu
	printf("Les elements du tableau:\n nombres[] = ");

	for(int i = 0; i < 10; i++)
	{
		printf("%d", nombres[i]);
		if(i < 9)
			printf(", ");	
	}
	printf("\n");

	// Afficher le max et le min
	printf("Min des nombres = %d\n", min);
	printf("Max des nombres = %d\n", max);
		

	return 0;
}

