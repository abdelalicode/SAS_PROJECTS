#include <stdio.h>

int main(void)
{
	int num, lastd;
	int iter = 0;

	printf("Entrer le nombre à inverser: ");
	scanf("%d", &num);


	while (num >= 10)
	{
		lastd = num / 10;
		num = lastd;
		iter++;
	}

	printf("%d\n", iter + 1);
	printf("%d\n", lastd);

	return 0;
}
