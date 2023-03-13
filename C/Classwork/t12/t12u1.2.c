#include <stdio.h>
#include <string.h>

#define SUURUS 100
#define PASWORD_LEN 14

void StringInput (char str2[], int n);
void ParooliKontroll (char str1[], char str2[], int n);
int TahemarkiSisaldus (char str3[], int n);
void Otsis6naLeidmine (char str3[], char str4[], int n);
void LauseKombineerimine (char str5[], char str6[], char str7[], char str8[], int n);
 
int main(void)
{
	int mitu;
	char parool[] = "Sanja";	//str1
	char proov[SUURUS];	//str2
	char lause[SUURUS];	// str3
	char otsiS6na[SUURUS];	//str4
	char esimeneS6na[SUURUS];	//str5
	char teineS6na[SUURUS];	//str6
	char uusLause[] = " tahan ";	//str7
	char uusLause2[3 * SUURUS];	//str8
	
	printf("Sisestage salasõna: ");
	ParooliKontroll(parool, proov, SUURUS);
	printf("Sisestage lause: ");
	mitu = TahemarkiSisaldus (lause, SUURUS);
	printf("Lause sisaldab %d tähemärki.", mitu);
	printf("\nSisestage otsisõna: ");
	Otsis6naLeidmine (lause, otsiS6na, SUURUS);
	LauseKombineerimine (esimeneS6na, teineS6na, uusLause, uusLause2, SUURUS);

	 return 0;
}

void StringInput (char str2[], int n)
{
	int i;
	fgets(str2, n, stdin);
		for (i = 0; i < n; i++)
		{
			if (str2[i] == '\n')
			{
				str2[i] = '\0';
				break;
			}
		}
}

void ParooliKontroll (char str1[], char str2[], int n)
{
	do
	{
		StringInput(str2, n);
		if (strcmp(str1, str2) != 0)
		{
			printf("Vale salasõna! Sisestage salasõna uuesti: ");
		}
	} while (strcmp(str1, str2) != 0);
}

int TahemarkiSisaldus (char str3[], int n)
{
	int i, a = 0;
	fgets(str3, n, stdin);
	for (i = 0; i < n; i++)
	{
		if (str3[i] == '\n')
		{
			str3[i] = '\0';
			break;
		}
		if ( str3[i] > 64 && str3[i] < 91)
		{
			a++;
		}
		
		if (str3[i] > 96 && str3[i] < 123)
		{
			a++;
		}
	}
	return a;
}

void Otsis6naLeidmine (char str3[], char str4[], int n)
{
	StringInput (str4, n);
	if (strstr(str3, str4) != NULL)
	{
		printf("Vastavust on leitud!");
	}
	else
	{
		printf("Vastavust ei ole leitud!");
	}
}

void LauseKombineerimine (char str5[], char str6[], char str7[], char str8[], int n)
{
	printf("\nSisesta esimene sõna: ");
	StringInput(str5, n);
	printf("Sisesta teine sõna: ");	
	StringInput(str6, n);
	
	strcpy(str8, str5);
	strcat(str8, str7);
	strcat(str8, str6);
	
	
	printf("Teie lause: %s", str8);
}
// dve problemõ: 1. Kogda ischet slovo iz predlozenija, ne razlichaet
// bolshuju i malujju bukvu.
