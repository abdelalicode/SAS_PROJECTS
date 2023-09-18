#include <stdio.h>

int Somme(int a, int b)
{
	return(a + b);
}

int main(void)
{	
	int num1, num2;
	int result;

	printf("Entrer Deux nombres à calculer:\n");
	scanf("%d\n%d", &num1, &num2); 

	result = Somme(num1, num2);
	printf("%d + %d = %d\n", num1, num2, result);

	return 0;
}
	
	
