:#include <stdio.h>

int main(void)
{
	char firstname[55];
	char lastname[55];
	int age;
	char genre[55];
	long number;
	
	printf("Entrer ton nom: ");
	scanf("%s", firstname);
	printf("Entrer ton prénom: ");
	scanf("%s", lastname);
	printf("Entrer ton age: ");
	scanf("%d", &age);
	printf("Entrer le sexe: ");
	scanf("%s", genre);
	printf("Entrer numero: ");
	scanf("%ld", &number);

	printf("Nom: %s\n", firstname);
	printf("Prenom: %s\n", lastname);
	printf("Age: %d\n", age);
	printf("Sexe: %s\n", genre);
	printf("Numero: %ld\n", number);

	return(0);
}
