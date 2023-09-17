#include <stdio.h>

int main(void)
{
	int an;
	long long secs;
	int choix;
          
	printf("Entrer l'année:\n");
	scanf("%d", &an);
	
	printf("Entrer votre choix  de conversion:\n");
	printf(" * En mois entrer 1:\n");
	printf(" * En jours entrer 2:\n");
	printf(" * En heures entrer 3:\n");
	printf(" * En minute entrer 4:\n");
	printf(" * En mois entrer 5:\n");
	scanf("%d", &choix);

	//check if it's a leap year or nor 

	if ( (( an % 4 == 0) && ( an % 100 == 0 )) || ( an % 400 == 0) ) 
	{
		
		secs = (long long)an * 366 * 24 * 60 * 60;

		switch (choix) {
			case 1:
				printf("les mois equivalents: %d mois\n" , an * 12);
				break;
			case 2:
				 printf("les jours equivalents: %d jours\n", an * 366);
				 break;
			case 3:
				 printf("les heures equivalents: %d heures\n", an * 366 * 24);
				 break;
			case 4:
				 printf("les minutes equivalents: %d minutes\n", an * 366 * 24 * 60);
				 break;
			case 5:
				 printf("les secondes des equivalents: %lld secondes\n", secs);
				 break;
			default:
				 printf("Choix entré invalable\n");
			}
	}
	else
	{	
		secs = (long long)an * 365 * 24 * 60 * 60;

		switch (choix) {
			case 1:
				printf("les mois equivalents: %d mois\n" , an * 12);
				break;
			case 2:
				printf("les jours equivalents: %d jours\n", an * 365);
				break;
			case 3:
				printf("les heures equivalents: %d heures\n", an * 365 * 24);
				break;
			case 4:
				printf("les minutes equivalents: %d minutes\n", an * 365 * 24 * 60);
				break;
			case 5:
				printf("les secondes des equivalents: %lld secondes\n", secs);
				break;
			default:
				printf("Choix entré invalable\n");
			}
	}

	return 0;
}
