#include <stdio.h>

int main(void)
{
	int nombres[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	printf("nombres[] = ");

	for(int i = 0; i < 10; i++)
	{
		printf("%d", nombres[i]);
		
		if(i < 9)
		       printf(", ");	
	}
	printf("\n");

	return 0;
}

