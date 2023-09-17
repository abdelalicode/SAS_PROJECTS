#include <stdio.h>

int main(void)
{
	int n;

	printf("Entrer le nombre à vérifier: ");
	scanf("%d", &n);
	
	int iter = 0;

	for (int i = 2 ; i < n ; i++)
	{

		if ( n % i == 0 )
		{
			iter++;	
		}
	}

	if ( iter == 0)
	{
		printf("Le nombre est premier\n");
	}
	else 
	{
		printf("Le nombre n'est pas premier.\n");

 	}

	return 0;

}


