 #include <stdio.h>

int main()

{	
	float maksumus;
	int kategooria;
	float hind;
	float kg;
	
	printf("Valige toote kategooria:\n 1 - puuviljad\n 2 - juurviljad\n 3 - marjad\n");
	scanf("%d", &kategooria);
	
	switch(kategooria)
	{
		
		case 1:
			
		int puuviljad;	
		printf("Valige kategooriasse kuluv toode:\n 1 - õunad\n 2- banaanid\n 3 - pirnid\n");
		scanf("%d", &puuviljad);
		
		switch(puuviljad)
		{
			case 1:
				hind = 0.65f;
				break;
				
			case 2:
				hind = 0.47f;
				break;
				
			case 3:
				hind = 0.84f;
				break;
				
			default:
				printf("Tundmatu toode. Proovige uuesti.\n");
				return 0;
		}
			
			break;
		
		case 2:
		
		int juurviljad;
		printf("Valige kategooriasse kuluv toode:\n 1 - tomatid\n 2- kurgid\n 3 - porgandid\n");
		scanf("%d", &juurviljad);
		
		switch(juurviljad)
		{
			case 1:
				hind = 0.93f;
				break;
				
			case 2:
				hind = 0.60f;
				break;
				
			case 3:
				hind = 0.76f;
				break;
				
			default:
				printf("Tundmatu toode. Proovige uuesti.\n");
				return 0;
		}
			break;
		
		
		case 3:
	
		int marjad;
		printf("Valige kategooriasse kuluv toode:\n 1 - maasikad\n 2- vaarikad\n 3 - mustikad\n");
		scanf("%d", &marjad);
		
		switch(marjad)
		{
			case 1:
				hind = 2.59f;
				break;
				
			case 2:
				hind = 3.45f;
				break;
				
			case 3:
				hind = 5.98f;
				break;
				default:
				printf("Tundmatu toode.Proovige uuesti.\n");
				return 0;
		}
			break;
		
		default:
		printf("Tundmatu kategooria. Proovige uuesti.\n");
		return 0;
	}
	
		
	
		
		printf("Kirjutage millises koguses (kilogrammides) Teie toodet soovite:\n");
		scanf("%f", &kg);
		
		
		
		if(kg >= 0)
		{
		maksumus = hind * kg; 
		printf("Teie summa on %.2f euro.\n", maksumus);
		}
		else
		printf("Kaal negatiivne. Proovige uuesti.\n");
	
		
		return 0;
}
