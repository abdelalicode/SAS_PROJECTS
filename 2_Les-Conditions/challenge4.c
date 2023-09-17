#include <stdio.h>
#include <math.h>

int main(void)
{
	int delta;
	int a, b, c;
	float result0;
	float result1, result2;
	
	printf("Pour résoudre l'équation aX^2 + bX + c = 0\n");
	printf("Entrer le coefficient de l'équation à resoudre\na = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	printf("c = ");
	scanf("%d", &c);
	
	if (a = 0 && b = 0 && c = 0 

	delta = (b * b) - (4 * a * c);

	if (delta < 0)
	{
		printf("L'équation n'admet pas de solutions en R\n");
	}
	else if (delta == 0)
	{
		result0 = -b / (2 * a);
		printf("L'équation admet un seul résultat X1 = %.2f\n", result0);
	}
	else 
	{
		result1 = ( -b - sqrt(delta) ) / (2 * a);
		result2 = ( -b + sqrt(delta) ) / (2 * a);
		printf("L'équation admet deux résultat X1 = %.2f et X2 = %.2f\n", result1, result2);
	}

	return 0;
}
