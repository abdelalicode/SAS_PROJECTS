#include <stdio.h>

int main(void)
{
	int a, b, c, d;
	int somme, moyen;

	printf("Entrer 4 nombres: \n");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	somme = a + b + c + d;
	moyen = somme / 4;

	printf("Somme = %d\n", somme);
	printf("Moyenne = %d\n", moyen);
	
	return 0;
}	


	
