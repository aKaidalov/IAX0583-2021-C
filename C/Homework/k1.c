#include <stdio.h>
#include <stdlib.h>


int main()
{
	int algus;
	printf("Mis kell Teie töö algab (24h)? Vastake täisnumbriga.\n");
	scanf("%d", &algus);
	
	int l6pp;
	printf("Mis kell Teie töö lõppeb (24h)? Vastake täisnumbriga.\n");
	scanf("%d", &l6pp);
	
	int toopaevad;
	printf("Mitu tööpaeva on Teie kalendrikuus? Vastake täisnumbriga.\n");
	scanf("%d", &toopaevad);
	
	int tunnipalk;
	printf("Mis on Teie tunnipalk? Vastake täisnumbriga.\n");
	scanf("%d", &tunnipalk);
	
	
	int paevas = abs(l6pp - algus) * tunnipalk;
	printf("Teie paevapalk on %d\n'", paevas);
	
	int kuupalk;
	kuupalk = paevas * toopaevad;
	printf("Teie kuupalk on %d\n", kuupalk);
	
	int brutopalk;
	brutopalk = 1563; // Eesti keskmine brutopalk
	
	if (kuupalk < brutopalk) 
	{
		printf("Teie palk on vähem kui Eesti keskmine brutopalk.\n");
	} 
	else if (kuupalk > brutopalk)
	 {
		printf("Teie palk on suurem kui Eesti keskmine brutopalk.\n");
	}
	else 
	 {
		printf("Teie palk on täpselt nagu Eesti keskmine brutopalk.\n");
	}


	return 0;
	}
