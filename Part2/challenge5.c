#include <stdio.h>

int main(void)
{
	int an;
	long long secs;
          
	printf("Entrer l'année:\n");
	scanf("%d", &an);

	secs = (long long)an * 365 * 24 * 60 * 60;
	 
	printf("les mois equivalents: %d mois\n" , an * 12);
	printf("les jours equivalents: %d jours\n", an * 365);
	printf("les heures equivalents: %d heures\n", an * 365 * 24);
	printf("les minutes equivalents: %d minutes\n", an * 365 * 24 * 60);
	printf("les secondes equivalents: %lld secondes\n", secs);

	return 0;
}
