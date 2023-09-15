#include <stdio.h>

int main(void)
{
	int an;
	long long secs;
          
	printf("Entrer l'année:\n");
	scanf("%d", &an);

	secs = an * 365 * 24 * 60 * 60;
	 
	printf("les mois equivalents: %d\n", an * 12);
	printf("les jours equivalents: %d\n", an * 365);
	printf("les heures equivalents: %d\n", an * 365 * 24);
	printf("les minutes equivalents: %d\n", an * 365 * 24 * 60);
	printf("les secondes equivalents: %lld\n", secs);

	return 0;
}
