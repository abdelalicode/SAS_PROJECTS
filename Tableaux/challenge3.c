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
	
	int temp;

	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (nombres[i] < nombres[j])
			{
				temp = nombres[i];
				nombres[i] = nombres[j];
				nombres[j] = temp;
			}
		}
	}

	//Afficher la liste de tri
	printf("Les nombres de plus grand au plus petit:\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", nombres[i]);
	}

	return 0; 	
}

