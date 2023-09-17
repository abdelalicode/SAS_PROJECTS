#include <stdio.h>

int main(void)
{
	int decimal;

	printf("Entrer le nombre entier: ");
	scanf("%d", &decimal);

	printf("Le nombre entier %d en octal est: %o\n", decimal, decimal);
	printf("Le nombre entier %d en hexadecimal est: %x\n", decimal, decimal);

	return (0);
}
