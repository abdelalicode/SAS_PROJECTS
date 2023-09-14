#include <stdio.h>

int main(void)
{
	float F, C;

	printf("Entrer la temperature en Celsius: ");
	scanf("%f", &F);

	C = (F-32)/1.8;

	printf("%.2f°C\n" , C);
	
	if (C > 35)
	{
		printf("Sensation très chaude!\n");

	}
	else if (C <= 35 && C > 20)
	{
		printf("Sensation chaude!\n");
	}
	else if (C <= 20 && C > 5)
	{	
		printf("Sensation froide!\n");
	}
	else
		printf("Sensation très froide!\n");
		
	return (0);
}
