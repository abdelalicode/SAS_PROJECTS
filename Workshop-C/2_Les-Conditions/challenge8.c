#include <stdio.h>

int main(void)
{
	int moyen;

	printf("Entrer la moyenne: ");
	scanf("%d", &moyen);

	if ( moyen >= 0 && moyen < 10 )
		printf("Recalé.\n");
	else if ( moyen >= 10 && moyen < 12 )
		printf("Mention Passable.\n");
	else if ( moyen >= 12 && moyen < 14 )
		printf("Mention Assez Bien.\n");
	else if ( moyen >= 14 && moyen < 16 )
		printf("Mention Bien.\n");
	else if ( moyen >= 16 && moyen <= 20)
		printf("Mension très bien.\n");
	else 
		printf("Vous n'avez pas entré une note!\n");

}


	
