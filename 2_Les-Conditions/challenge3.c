#include <stdio.h>

int main(void)
{
	int num1, num2;
	int somme;

	printf("Entrer 2 nombres entiers:\n");
	scanf("%d %d", &num1, &num2);
	
	somme = num1 + num2;

	if ( num1 == num2 )
	{
		printf("le triple des somme est: %d\n", somme * somme * somme );
	}
	else 
	{	
		printf("La somme est: %d\n", somme);
	}
	return 0;
}
	
