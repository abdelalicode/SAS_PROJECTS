#include <stdio.h>

int main(void)
{
	int num;

	printf("Entrer le nombre à vérifier: ");
	scanf("%d", &num);

	if (num < 0)
	{
		printf("Le nombre est négative.\n");
	}
	else if (num > 0)
	{
		printf("Le nombre est positive.\n");
	}
	else
	{	
		printf("Le nombre est égal à zéro.\n");
	}

	return 0;
}
