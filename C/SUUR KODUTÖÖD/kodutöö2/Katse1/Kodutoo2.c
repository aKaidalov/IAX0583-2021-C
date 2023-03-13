#include <stdio.h>

int main(void)
{
	int massiivideSuurus;
	printf("Massiivide suurus: ");
	scanf("%d", &massiivideSuurus);
	if (massiivideSuurus < 1 || massiivideSuurus > 15)
	{
		printf("\nViga! Massiivi suurus peab olema vahemikus 1...15! ");
		return 0;
	}
	
//----------------------------------------------------------------------
	printf("\n");
	int i = 0;
	float hind[massiivideSuurus]; // mb nuzen float v funktsijah
	float kaal[massiivideSuurus];
	
	while (i < massiivideSuurus)
    {
		printf("Sisestage hind (%d/%d): ", i + 1, massiivideSuurus);
		scanf("%f", &hind[i]);
		i++;
	}
	
	printf("\n");
	i = 0;
	while (i < massiivideSuurus)
    {
		printf("Sisestage kaal (%d/%d): ", i + 1, massiivideSuurus);
		scanf("%f", &kaal[i]);
		i++;
	}
	
	printf("\n");
	float kgHind[massiivideSuurus];
	for (i = 0; i < massiivideSuurus; i++)
	{
		kgHind[i] = hind[i] / kaal[i];
		printf("PAKKUMINE%02d: ", i + 1);
		printf("%3.f %3.f %6.2f", hind[i], kaal[i], kgHind[i]);
		printf("\n");
	}
	
	
//----------------------------------------------------------------------	
	// Hinnatolerantsus
	printf("\n\n");
	float tol;
	printf("Maksimaalne kilo hind: ");
	scanf("%f", &tol);
//----------------------------------------------------------------------	
	int pikkus = 0;
	for (i = 0; i < massiivideSuurus; i++)
	{
		if (kgHind[i] <= tol)
		{
			pikkus++;
		}
	}
	printf("Leitud %d kriteeriumile vastavat pakkumist.", pikkus);
//----------------------------------------------------------------------	
	
	int j;
	int pos[pikkus];
	
	for (i = 0, j = 0; i < massiivideSuurus; i++)
	{
		if (kgHind[i] <= tol)
		{
			pos[j] = i + 1;
			j++;
		}
	}
	
	printf("\n");
	printf("Sobivad pakkumised on: ");
	for(j = 0; j <= pikkus; j++)
	{
		if (j == pikkus)
		{
			printf(".");
			break;
		}
		printf(" PAKKUMINE%02d", pos[j]);
		if (j < pikkus - 1)
		{
			printf(",");
		}

	}
	
	
	return 0;
}
