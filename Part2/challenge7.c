#include <stdio.h>

int main(void)
{
	char alphab;

	printf("Entrer la lettre: ");
	scanf("%c", &alphab);

	if ( (alphab >= 65 && alphab <= 90) || (alphab >= 97 && alphab <= 122) )
	{
		if ( alphab >= 65 && alphab <= 90 )
		{
			printf ("La lettre est majiscule.\n");
		}
		else 
		{
			printf("La lettre est miniscule.\n");
		}
	}
	else 
	{
		printf("Vous n'avez pas entré une lettre\n");
	}
	return 0;
}

