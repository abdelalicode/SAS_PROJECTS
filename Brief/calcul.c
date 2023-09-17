#include <stdio.h>

int main(void)
{
	int num1, num2;
	char operat;
	
	do
	{	

		printf("Entrer l'opération souhaité:\n");
		printf("> Pour Addition Appuyez +\n"); 
		printf("> Pour Substraction Appuyez -\n"); 
		printf("> Pour Multiplication Appuyez *\n"); 
		printf("> Pour Division Appuyez /\n");
		printf("> Pour Quitter Appuyez #\n");
		scanf(" %c", &operat);

		if (operat == '#')
		{
			break;
		}
		
		else if (operat == '+' || operat == '-' || operat == '*' || operat == '/')
		{
		 	printf("Entrer le premier nombre: ");
		        scanf("%d", &num1);
			printf("Entrer le deuxième nombre: ");
			scanf("%d", &num2);

			switch (operat) {

				case '+' :
					printf("%d + %d = %d\n", num1, num2, num1 + num2);
					break;
				case '-' :
					printf("%d - %d = %d\n", num1, num2, num1 - num2);
					break;
				case '*' :
					printf("%d * %d = %d\n", num1, num2, num1 * num2);
					break;
				case '/' :
					printf("%d / %d = %d\n", num1, num2, num1 / num2);
					break;
				}
			
				
		} 
		else
			printf("Choix non valide!\n");

	} while (1);
	
	return 0;
}
