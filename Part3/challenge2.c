#include <stdio.h>

int main(void)
{
	int n;

	printf("Enter le nombre de ligne à dessiner: ");
	scanf("%d", &n);


	for (int i = 0; i < n; i++)
	{
		for(int j = n; j >= i ; j--)
		{
			printf(" ");
		}
		
		for(int k = 0; k <= 2 * i; k++)
		{
			printf("*");
		}
		printf("\n");
	}	
}
