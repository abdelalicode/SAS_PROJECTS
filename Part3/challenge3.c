#include <stdio.h>

int main(void)
{
	int n;

	printf("Entrer le nombre à vérifier: ");
	scanf("%d", &n);
	

	for (int i = 2; i <= n / 2 ; i++)
	{
		if ( n % i != 0 )
		{
			printf("Le nombre est premier\n");
			break;

		}
		else 
		{
			printf("Le nombre n'est pas premier.\n");
			break;
		}
	}
	return 0;

}


