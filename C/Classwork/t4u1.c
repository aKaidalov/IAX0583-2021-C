#include <stdio.h>

#define  ARVUDE_KOGUS 6

int main (void)
{
	int i, suurim, vahim,arvud[5]; //p, a;
	
	for (i = 0; i < ARVUDE_KOGUS; i++)
	{
			printf("Sisestage arv %d / %d:\n", i + 1, ARVUDE_KOGUS);
			scanf("%d", &arvud[i]);
	}
		
	suurim = arvud[0];
	vahim = arvud[0];
	for (i = 1; i < ARVUDE_KOGUS; i++)
	{
		if (suurim < arvud[i])
		{
			suurim = arvud[i];
			//p = i;
		}
		
		if (vahim > arvud[i])
		{
			vahim = arvud[i];
			//a = i;
		}
	}
	
	
	int loendur = 0;
	
	printf("Suurim arv on %d ja tema positsioonid: ", suurim);
	
	for (i = 0; i < ARVUDE_KOGUS; i++)
	{
		if (arvud[i] == suurim){
			printf("%d ", i + 1);
			loendur++;
			
		}
	}
	printf("\nMitu korda suurim element kordus: %d\n\n", loendur);
	
 	loendur = 0;
	printf("Vähim arv on %d ja tema positsioonid: ", vahim);
	
	for (i = 0; i < ARVUDE_KOGUS; i++)
	{
		if (arvud[i] == vahim){
			printf("%d ", i + 1);
			loendur++;
			
		}
	}
	printf("\nMitu korda vähim element kordus: %d", loendur);
	
	
	
	
	//~ for (i = 0; i < ARVUDE_KOGUS; i++)
	//~ {
		//~ if (arvud[i] == vahim)
		//~ c[i] = i + 1;
	//~ }
	
	//~ vahim = arvud[0];
	//~ for (i = 1; i < ARVUDE_KOGUS; i++)
	//~ {
		//~ if (vahim > arvud[i])
		//~ {
			//~ vahim = arvud[i];
		//~ }
	//~ }
	
	
	//~ printf("Suurim arv on %d ja tema positsioon on %d.\n", suurim, p + 1);
	//~ printf("Vähim arv on %d ja tema positsioon on %d.\n", vahim, a + 1);
	

	
	return 0;
}
