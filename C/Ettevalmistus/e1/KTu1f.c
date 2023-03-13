#include <stdio.h>

int LeiabArvudeKogus ();
void MassiiviVaartused (int kogus, int arrArvud[]);
int UnikaalseteLeidmineArr (int kogus, int arrArvud[]);
int UnikaalseteLeidmineArv (int kogus, int arrArvud[]);
void Valjaprintimine (int uniArv, int arrUni[]);


int main(void)
{
	int arvudeKogus = LeiabArvudeKogus();
	int arvud[arvudeKogus];
	int unikaalseteArv = 0;
	int unikaalsed[unikaalseteArv];
	float uus = 0; 				// chtobõ poluchit "float" nuzno, 
	float protsent;				// chtobõ odin iz mnozitilei bõl float!
	
	MassiiviVaartused(arvudeKogus, arvud);
	unikaalseteArv = UnikaalseteLeidmineArv (arvudeKogus, arvud);
	unikaalsed[unikaalseteArv] = UnikaalseteLeidmineArr (arvudeKogus, arvud);
	uus = unikaalseteArv;
	printf("\nUnikaalsed arvud:");
	Valjaprintimine (unikaalseteArv, unikaalsed);

	printf("\nArvude kogus: %d", arvudeKogus);
	printf("\nUnikaalsete arvude kogus: %d", unikaalseteArv);
	
	protsent = (uus / arvudeKogus) * 100;
	printf("\nUnikaalseid arvu on %.f protsenti", protsent);
	
	return 0;
}

int LeiabArvudeKogus ()
{
	printf("Sisestage arvude kogus: ");
	int kogus;
	scanf("%d", &kogus);
	do
	{
		if (kogus < 2 || kogus > 64)
		{
			printf("\nViga! Sisestage arvude kogus uuesti: ");
			scanf("%d", &kogus);
		}
	} while (kogus < 2 || kogus > 64);
	return kogus;
}

void MassiiviVaartused (int kogus, int arrArvud[])
{
	int i = 0; // lokaalsed muutujad
	do
	{
		printf("Sisestage arv (%d / %d): ", i + 1, kogus);
		scanf("%d", &arrArvud[i]);
		i++;
	} while (i < kogus);
}

int UnikaalseteLeidmineArv (int kogus, int arrArvud[])
{
	int uniArv = 0;
	int arrUni[uniArv];
	int leitud, j, i; // lokaalsed muutujad
	//int unikaalseteArv = 0, unikaalsed[unikaalseteArv];
	for (i = 0; i < kogus; i++)
	{
		leitud = 0;
		for (j = 0; j < uniArv; j++)
		{
			if (arrArvud[i] == arrUni[j])
			{
				leitud = 1; 
			}
		}
		if (leitud == 0)
		{
			arrUni[uniArv] = arrArvud[i];
			uniArv++;
		}
	}
	return uniArv;
}

int UnikaalseteLeidmineArr ( int kogus, int arrArvud[])
{
	int uniArv = 0;
	int arrUni[uniArv];
	int leitud, j, i; // lokaalsed muutujad
	//int unikaalseteArv = 0, unikaalsed[unikaalseteArv];
	for (i = 0; i < kogus; i++)
	{
		leitud = 0;
		for (j = 0; j < uniArv; j++)
		{
			if (arrArvud[i] == arrUni[j])
			{
				leitud = 1; 
			}
		}
		if (leitud == 0)
		{
			arrUni[uniArv] = arrArvud[i];
			uniArv++;
		}
	}
	return arrUni[uniArv];
}

void Valjaprintimine (int uniArv, int arrUni[])
{
	int j;
	for (j = 0; j < uniArv; j++)
	{
		printf(" %d ", arrUni[j]);
	}
}
