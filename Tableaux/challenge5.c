#include <stdio.h>

int main(void)
{
	char name[50];
	printf("Entrer votre nom:\n");
	scanf("%s", name);

	int i = 0; 
	
	while (name[i] != '\0')
	{
		i++;
	}

	printf("Le nombre des caractères est: %d\n", i);

	return 0;
}
