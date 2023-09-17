#include <stdio.h>

int main(void)
{
	char lettre;

	printf("Entrer la lettre: ");
	scanf("%c", &lettre);

	if ((lettre >= 65 && lettre <= 90) || (lettre >= 97 && lettre <= 122))
	{
		if (lettre >= 65 && lettre <= 90)
			lettre = lettre + 32;

			
		switch (lettre) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'y':
				printf("La lettre est une voyelle\n");
				break;
			default:
				printf("La lettre n'est pas une voyelle\n");
		}
	}
	else 
		printf("Vous n'avez pas entré une lettre\n");

	return 0;
}


