#include <stdio.h>

int main(void)
{
//----------------------------------------------------------------------
// leab arvude kogus

	int arvudeKogus;
	printf("Sisestage arvude kogus: ");
	scanf("%d", &arvudeKogus);
	do
	{
		if (arvudeKogus < 2 || arvudeKogus > 64)
		{
			printf("\nViga! Sisestage arvude kogus uuesti: ");
			scanf("%d", &arvudeKogus);
		}
	} while (arvudeKogus < 2 || arvudeKogus > 64);
	
//----------------------------------------------------------------------
// paneb massiivisse väärtused (mitu = arvudeKogus)

	int i = 0; // lokaalsed muutujad
	int arvud[arvudeKogus];
	do
	{
		printf("Sisestage arv (%d / %d): ", i + 1, arvudeKogus);
		scanf("%d", &arvud[i]);
		i++;
	} while (i < arvudeKogus);
	
//----------------------------------------------------------------------
// unikaalsete leidmine

	int leitud, j = 0; // lokaalsed muutujad + int i
	int unikaalseteArv = 0, unikaalsed[unikaalseteArv];
	for (i = 0; i < arvudeKogus; i++)
	{
		leitud = 0;
		for (j = 0; j < unikaalseteArv; j++)
		{
			if (arvud[i] == unikaalsed[j])
			{
				leitud = 1; 
			}
		}
		if (leitud == 0)
		{
			unikaalsed[unikaalseteArv] = arvud[i];
			unikaalseteArv++;
		}
	}
//----------------------------------------------------------------------

	printf("\nUnikaalsed arvud:");
	for (j = 0; j < unikaalseteArv; j++)
	{
		printf(" %d ", unikaalsed[j]);
	}

	printf("\nArvude kogus: %d", arvudeKogus);
	printf("\nUnikaalsete arvude kogus: %d", unikaalseteArv);
	
	float uus = unikaalseteArv; // chtobõ poluchit "float" nuzno, 
	float protsent;				// chtobõ odin iz mnozitilei bõl float
	protsent = (uus / arvudeKogus) * 100;
	printf("\nUnikaalseid arvu on %.f protsenti", protsent);
	
	
	return 0;
}
