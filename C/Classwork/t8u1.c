#include <stdio.h>

#define N 5


int LoeArvud(int i);
void ArvudArr(int arvud[], int pikkus);
void TrykiArvud(int arvud[], int pikkus);
int AritmeetilineKeskmine(int arvud[], int pikkus);
	
int main(void)
{
	int arvud[N];
	ArvudArr(arvud, N);
	TrykiArvud(arvud, N);
	printf("\nMassiivi aritmeetiline keskmine on: %d",
											   AritmeetilineKeskmine(arvud, N));
	printf("\n");
		
	return 0;
}
	
//~ void LoeArvud(int arvud[], int pikkus)	
//~ {
	//~ int i;	
	//~ for(i = 0; i < pikkus; i++)
	//~ {
		//~ printf("Anna arv %d / %d: ", i + 1, pikkus);
		//~ scanf("%d", &arvud[i]);
		//~ if (arvud[i] < -100 || arvud[i] > 100)
		//~ {
			//~ do
			//~ {
				//~ printf("Arv peab olema -100 .. 100 vahel! Proovige uuesti: ");
				//~ scanf(" %d", &arvud[i]);
			//~ } while (arvud[i] < -100 || arvud[i] > 100);
		//~ }	
	//~ }
	//~ printf("\n");
//~ }
int LoeArvud(int i)	
{
	int arv;
	printf("Sisesta arv %d / %d: ", i + 1, 5);
	scanf("%d", &arv);
	if (arv < -100 || arv > 100)
	{
		do
		{
			printf("Arv peab olema -100 .. 100 vahel! Proovige uuesti: ");
			scanf(" %d", &arv);
		} while (arv < -100 || arv > 100);
	}	
	return arv;
}


void ArvudArr(int arvud[], int pikkus)
{
	int i;	
	for(i = 0; i < pikkus; i++)
	{
		arvud[i] = LoeArvud(i);
	}
	printf("\n");
}

void TrykiArvud(int arvud[], int pikkus)
{
	int i;
	printf("Arvud massiivis on: ");
	for(i = 0; i < pikkus; i++)
	{
		printf("%d ", arvud[i]);
	}
	printf("\n");
}

int AritmeetilineKeskmine(int arvud[], int pikkus)
{
	int i, summa = 0, vastus;
	for(i = 0; i < pikkus; i++)
	{
		summa += arvud[i];
	}
	vastus = summa / pikkus;
	return vastus;
}
