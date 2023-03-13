//~ Kodutoo_1_Aleksandr_Kaidalov_213394EARB_kood
//~ Nimi: Aleksandr Kaidalov
//~ Tehtud: 13.03.2022




#include <stdio.h>
#include <math.h>
#define KORDUSED 20
#define REA_PIKKUS 15

int main(void)
{
	float algVaartus, alampiir, samm;		// Deklareerin kõik muutujad.
	float xArvud[KORDUSED], yArvud[KORDUSED];
	int i;
	
	
	printf("Funktsiooni y = 1 / (x^2) + x / √(4 + x) väärtuste leidmine.\n\n");
	printf("Sisestage argumenti algväärtus: ");
	scanf("%f", &algVaartus);
	printf("Sisestage funktsiooni alampiir: ");
	scanf("%f", &alampiir);
	printf("Sisestage samm: ");
	
	
	do                             	 // Kontrollin, et samm on suurem nullist.
	{								 // Kui ta on väiksem, tsükel töötab selle 
		scanf("%f", &samm);			 // ajani, et kasutaja sisestaks samm suurem
		if (samm <= 0)				 // kui 0.
		{
			printf("\nSamm peab olema suurem kui 0. Proovige uuesti!\n");
		}
	}
	
	while (samm <= 0);
	
	
	// Märgin ja kuvan X ja Y veerud.
	
	
	printf("\n %*s %*s", REA_PIKKUS, "X", REA_PIKKUS, " Y\n");
	
	
	// Koostan tsüklit, mis töötab 20 korda.
	
	
	for (i = 0; i < KORDUSED; i++)
	{
			
			// Kasutan meetodit, mis oli antud ülesandes. 
		
			xArvud[i] = algVaartus + (samm / (i + 1));
			
			// Y veerus prugramm kirjutab "kompleksarvuline" juhul
			// kui x < -4, kuna ruutjuuri alla me saame vastus "-" märgiga.
					
			if (xArvud[i] < -4)
			{
				printf(" %*.3f  %*s\n",REA_PIKKUS,xArvud[i],
									   REA_PIKKUS, "kompleksarvuline\n");
				continue;
			}
				
			// Y veerus prugramm kirjutab "puudub" juhul
			// kui x = -4 või kui x = 0, kuna funktsiooni lugejas me saame 0. 
				
			else if (xArvud[i] == -4 || xArvud[i] == 0) 
			{
				printf(" %*.3f  %*s\n",REA_PIKKUS,xArvud[i],
										   REA_PIKKUS,"puudub");
				continue;
			}
			
			else
			{
				// Kirjtan vajalikku funktsiooni. 
			
				yArvud[i] = 1 / (pow(xArvud[i], 2)) + 
												xArvud[i] / sqrt(4 + xArvud[i]);
			}
			
				// Kasutan üks põhi tingimustest, et y > Y_MIN (ehk y alampiir).
				
			if (yArvud[i] > alampiir)
			{
					
					
				// Ptogramm kuvab tavalised vastused tabelina,
				// ehk tabuleerib funktsiooni väärtused.
				
				printf(" %*.3f %*.3f\n", REA_PIKKUS, xArvud[i],
										   REA_PIKKUS - 1, yArvud[i]);	
			}
				
			else   // Lõpetab programmi töötamist kui yArvud[i] <= alampiir.
			break;	
	}		
	
	
	
	
	return 0;
}


