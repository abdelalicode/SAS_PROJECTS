#include <stdio.h>

int main(void)
{
	char phrs[30] = "Quel sinistre mot!";
	int positionm, positions, positionlet;
	char lettre;
	int iter = 0;
	
	// Trouver m et quelle position
	for (int i = 0; phrs[i] != '\0'; i++)
	{
		if (phrs[i] == 'm')
		{
			positionm = i;
			printf("la lettre m se trouve au %de position\n", positionm + 1);
		}	
		
	}

	// Trouver s et quelle position
	for (int i = 0; phrs[i] != '\0'; i++)
	{
		if (phrs[i] == 's')
		{
			positions = i;
			printf("la lettre m se trouve au %de position\n", positions + 1);
			break;
		}

	}

	//Permutation
	int temp;
	temp = phrs[positionm];
	phrs[positionm] = phrs[positions];
	phrs[positions] = temp;
	
	printf("Le texte modifié: ");

	//Affichage du tableau apres permutation
	for (int i = 0; phrs[i] != '\0'; i++)
	{
		printf("%c", phrs[i]);
	}
	printf("\n");
	

	printf("Entrer une lettre à rechercher:\n");
	scanf("%c", &lettre);

	for (int i = 0; phrs[i] != '\0'; i++)
	{
		if (lettre == phrs[i])
		{
			positionlet = i;
			printf("la lettre saisie se trouve au %de position\n", positionlet + 1);
			iter++;
		}
	}
	if (iter == 0)
		printf("Erreur! Aucun résultat du lettre saisie\n");


	return 0;
}
