#include <stdio.h>
#include <string.h>

#define SUURUS 100
#define PASWORD_LEN 14
 
int main(void)
{
	char parool[] = "Sanja";
	char proov[SUURUS];
	char lause[SUURUS];
	char otsiS6na[SUURUS];
	char esimeneS6na[SUURUS];
	char teineS6na[SUURUS];
	char uusLause[] = "tahan";
	
// Parooli kontroll ---------------------------------------
	
	int i;
	printf("Sisestage salasõna: ");
	do
	{
		fgets(proov, SUURUS, stdin);
		for (i = 0; i < SUURUS; i++)
		{
			if (proov[i] == '\n')
			{
				proov[i] = '\0';
				break;
			}
		}
		if (strcmp(parool, proov) != 0)
		{
			printf("Vale salasõna! Sisestage salasõna uuesti: ");
		}
	} while (strcmp(parool, proov) != 0);
	
// Tähemärki sisaldus ----------------------------------------
	// int i;
	int a = 0;
	printf("Sisestage lause: ");
	fgets(lause, SUURUS, stdin);
	for (i = 0; i < SUURUS; i++)
	{
		if (lause[i] == '\n')
		{
			lause[i] = '\0';
			break;
		}
		if ( lause[i] > 64 && lause[i] < 91)
		{
			a++;
		}
		
		if (lause[i] > 96 && lause[i] < 123)
		{
			a++;
		}
	}
	printf("Lause sisaldab %d tähemärki.", a);
	
// Otsisõna leidmine -----------------------------------------
	printf("\nSisestage otsisõna: ");
	fgets(otsiS6na, SUURUS, stdin);
	for (i = 0; i < SUURUS; i++)
	{
		if (otsiS6na[i] == '\n')
		{
			otsiS6na[i] = '\0';
			break;
		}
	}
	if (strstr(lause, otsiS6na) != NULL)
	{
		printf("Vastavust on leitud!");
	}
	else
	{
		printf("Vastavust ei ole leitud!");
	}
	
// Lause kombineerimine --------------------------------------
	
	printf("\nSisesta esimene sõna: ");
	fgets(esimeneS6na, SUURUS, stdin);
	for (i = 0; i < SUURUS; i++)
		{
			if (esimeneS6na[i] == '\n')
			{
				esimeneS6na[i] = '\0';
				break;
			}
		}
		
	printf("Sisesta teine sõna: ");	
	fgets(teineS6na, SUURUS, stdin);
	for (i = 0; i < SUURUS; i++)
		{
			if (teineS6na[i] == '\n')
			{
				teineS6na[i] = '\0';
				break;
			}
		}
	strcat(esimeneS6na, uusLause);
	strcat(esimeneS6na, teineS6na);
	
	printf("Teie lause: %s", esimeneS6na);
	 return 0;
}
