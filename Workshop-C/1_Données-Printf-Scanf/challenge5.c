#include <stdio.h>
#include <math.h>

int main(void)
{
	int x1, y1;
	int x2, y2;
	int distance;

	printf("Entrer les coordonées x y du premier point: ");
	scanf("%d %d", &x1, &y1);
	printf("Entrer les coordonées x y du deuxième point: ");
	scanf("%d %d", &x2, &y2);

	distance = sqrt( (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) );

	printf("La distance entre les 2 points est: %d\n", distance);

	return 0;
}
