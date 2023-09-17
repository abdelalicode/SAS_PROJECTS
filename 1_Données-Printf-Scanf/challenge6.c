#include <stdio.h>
#include <math.h>

int main(void)
{
	double rayon, circon;

	printf("Entrer le rayon du cercle: ");
	scanf("%lf", &rayon);

	circon = 2 * M_PI * rayon;
	
	printf("La circonférence du cercle est %lf\n", circon);

	return 0;
}
