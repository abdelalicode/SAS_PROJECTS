#include <stdio.h>

int main(void)
{
	int n;
	int multipl;

	printf("Entrer le nombre à afficher: ");
	scanf("%d", &n);

	for (int i = 1; i <= 10 ; i++)
	{
		multipl = i * n;
		printf("%d x %d = %d", n, i, multipl);
		printf("\n");
	}
	return 0;
}

