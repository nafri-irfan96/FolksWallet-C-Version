/*
Welcome to the official documentation on FolksWallet, the real Folks Wallet! =D 
This is an implementation of the application's functionality in C language.
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
struct wallet
{
	float ce;
	float *dues;
};
int main()
{
	int numberOfPersons;
	printf_s("Enter the number of persons in the transaction\n");
	scanf_s("%d", &numberOfPersons);
	float perIndividual = 0;
	float transAmount = 0;
	int payee;
	int i = 0;
	int j = 0;
	int k = 0;
	int check;
	struct wallet *FolksWallet;
	FolksWallet = (struct wallet*)malloc(sizeof(struct wallet)*numberOfPersons);
	for (i = 0; i < numberOfPersons; i++)
	{
		FolksWallet[i].ce = 0;
		FolksWallet[i].dues = (float*)malloc(sizeof(float)*(numberOfPersons));
		for (j = 0; j < numberOfPersons; j++)
		{
			FolksWallet[i].dues[j] = 0;
		}
	}
	i = j = 0;
	do
	{
		printf_s("*********Transaction #%d*********\n", i + 1);
		printf_s("Enter transaction amount: ");
		scanf_s("%f", &transAmount);
		perIndividual = transAmount / numberOfPersons;
		printf_s("Enter the payee's ID: ");
		scanf_s("%d", &payee);
		for (j = 0; j < numberOfPersons; j++)
		{
			FolksWallet[j].ce += perIndividual;
			if (j == payee)
			{
				for (k = 0; k < numberOfPersons; k++)
				{
					if (k == payee)
						continue;
					FolksWallet[j].dues[k] -= perIndividual;
				}
			}
			else
			{
				FolksWallet[j].dues[payee] += perIndividual;
			}
		}
		i++;
		printf_s("Press: 1 to enter more transactions\n       Any other key to view the dues\n*****************");
		scanf_s("%d", &check);
	} while (check == 1);
	for (i = 0; i < numberOfPersons; i++)
	{
		printf_s("The cumilative expenditure of Person #%d = Rs. %f\n", i, FolksWallet[i].ce);
		for (j = 0; j < numberOfPersons; j++)
		{
			if (i == j)
				continue;
			if (FolksWallet[i].dues[j] < 0)
			{
				printf_s("Person %d should receive an amount of %f from Person %d\n", i, -1 * FolksWallet[i].dues[j], j);
			}
			else
			{
				printf_s("Person %d should give an amount of %f to Person %d\n", i, FolksWallet[i].dues[j], j);
			}
		}
	}
	getchar();
}
