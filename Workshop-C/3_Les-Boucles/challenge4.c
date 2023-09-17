#include <stdio.h>

int main(void)
{
	int num;
	int somme = 0; 
	int max = 0;

	do
	{
		printf("Entrer un nombre positive: ");
		scanf("%d", &num);

		if ( num < 100 )
		{	
			somme = num + somme;
			
			

			if ( num > max )
			{
				max = num;
			}

		}


	} while (num > 0);
	
	printf("La somme des nombres =  %d\n", somme);
	printf("Le maximum des nombres = %d\n", max);
	
	return 0;
}

