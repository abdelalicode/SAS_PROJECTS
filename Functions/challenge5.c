#include <stdio.h>

void Permuter(float a, float b)
{
	int c;

	c = a;
	a = b;
	b = c;
	printf("> Après pérmutation.\n num1 = %.2f\n num2 = %.2f\n", a, b);

}

int main(void)
{
	float num1, num2;

	printf("Entrer deux nombres à permuter.\n");
	printf("Entrer num1: ");
	scanf("%f", &num1);
	printf("Entrer num2: ");
	scanf("%f", &num2);

	printf("> Avant pérmutation.\n num1 = %.2f\n num2 = %.2f\n", num1, num2);
	Permuter(num1, num2);
	
	return 0;
}
