#include <stdio.h>

int main()
{
	float number;
	scanf("%f", &number);
	printf("%.f", number);
	int a;
	char euro[] = "hind";
	char kg[] = "kaal";
	
	a = 0;
	if (a == 0)
	{
		printf("Sisestage %s (%d/%.f): ", euro,  1, number);
	}
	a = 1;
	if (a == 1)
	{
		printf("Sisestage %s (%d/%.f): ", kg, 2, number);
	}
	return 0;
}



int a;
	char euro[] = "hind";
	char kg[] = "kaal";
	
	a = 0;
	if (a == 0)
	{
		printf("Sisestage %s (%d/%d): ", euro[], i + 1, massiivideSuurus);
	}
	a = 1;
	if (a == 1)
	{
		printf("Sisestage %s (%d/%d): ", kg[], i + 1, massiivideSuurus);
	}
	
// Loeb hind
	printf("\n");
	int i = 0;
	float hind[massiivideSuurus]; // mb nuzen float v funktsijah
	float kaal[massiivideSuurus];
	
	int a;
	char euro[] = "hind";
	char kg[] = "kaal";
	a = 0;
	if (a == 0)
	{
		while (i < massiivideSuurus)
		{
			printf("Sisestage %s (%d/%d): ", euro, i + 1, massiivideSuurus);
			scanf("%f", &hind[i]);
			i++;
		}
	}
	
	printf("\n");
	a = 1;
	if (a == 1)
	{
		i = 0;
		while (i < massiivideSuurus)
		{
			printf("Sisestage %s (%d/%d): ", kg, i + 1, massiivideSuurus);
			scanf("%f", &kaal[i]);
			i++;
		}
	}
