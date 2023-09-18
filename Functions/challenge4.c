#include <stdio.h>

int Max_2(int a, int b)
{
	int max;
	if (a > b)
	{
		max = a;
	}
	else 
		max = b;

	return max;
}

int Max_4(int a, int b, int c, int d)	
{
	int maximum;

	int max1 = Max_2(a, b);
	int max2 = Max_2(c, d);
	
	// Comparer les deux maximums
	maximum = Max_2(max1, max2);

	return maximum;	

}

int main()
{
	int num1, num2, num3, num4;
	printf("Entrer 4 nombres à comparer:\n");
	scanf("%d%d%d%d", &num1, &num2, &num3, &num4);

	int maxi = Max_4(num1 , num2, num3, num4);
	
	printf("Le max des nombres est: %d\n", maxi);

	return 0;
}
