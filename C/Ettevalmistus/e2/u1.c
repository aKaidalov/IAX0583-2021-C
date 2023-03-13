#include <stdio.h>

int main(void)
{
	int n;
	int i;
	
	printf("Sisestage suurus n\n");
	scanf("%d", &n);
	
	int koodid[n];
	float kaalud[n];
	float suhemin[n];
	float suhemax[n];
	
	for(i = 0; i < n; i++)
	{
		printf("\nSisestage %d. arv massiivi KOODID: ", i+1);
		scanf("%d", &koodid[i]);
		printf("Sisestage %d. arv massiivi KAALUD: ", i+1);
		scanf("%f", &kaalud[i]);
	}

	float min = kaalud[0];
	float max = kaalud[0];
	
	for (i = 1; i < n; i++){
		if (min > kaalud[i])
		{
			min = kaalud[i];
		} else if (max < kaalud[i])
		{
			max = kaalud[i];
		}
	}
		
	for (i = 0; i < n; i++) {
		suhemin[i] = kaalud[i]/min;
		suhemax[i] = kaalud[i]/max;			
	}	
	printf("\n");
	for(i = 0; i < n; i++) {
		printf("%d, %.1f, %.2f, %.1f\n", koodid[i], kaalud[i], suhemin[i], suhemax[i]);	
	}
		
	return 0;
}
