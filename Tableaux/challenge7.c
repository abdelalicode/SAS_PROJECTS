#include <stdio.h>

int main(void)
{
	int tab[5][5];
	int somme = 0;
	
	for (int i = 0; i < 5; i++)
	{	
		printf("Entrer les valeurs de %de ligne\n", i + 1);
			
		for (int j = 0; j < 5; j++)
		{	
			printf("Element [%d][%d]\n", i + 1, j + 1);
			scanf("%d", &tab[i][j]);
			somme += tab[i][j];
		}

		
	}
	printf("Les élements du tableau:\n");
	printf("/              \\ \n");
	for (int i = 0; i < 5; i++)
	{
		printf("|");
		for (int j = 0; j < 5; j++)
		{
			printf(" %d ", tab[i][j]);
		}
		printf("|");
		printf("\n");
	}
	printf("\\              / \n");
	printf("La somme des élements = %d\n", somme);

	return 0;
}
