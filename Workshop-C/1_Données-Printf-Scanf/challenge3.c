#include <stdio.h>

int main(void)
{
	int a, b;
	int somme, subs, prod, div, mod;

	printf("Entrer un nombre entier a : ");
	scanf("%d", &a);
	printf("Entrer un nombre entier b : ");
	scanf("%d", &b);
	
	if (b != 0)
	{
		somme = a + b;
		subs = a - b;
		prod = a * b;
		div = a / b;
		mod = a % b;
	
		printf("a + b = %d\n", somme);
		printf("a - b = %d\n", subs);
		printf("a * b = %d\n", prod);
		printf("a / b = %d\n", div);
		printf("a %% b = %d\n", mod);
	}
	else 
		printf("Le diviseur ne peut pas égal à zero\n");

	return 0;
}
