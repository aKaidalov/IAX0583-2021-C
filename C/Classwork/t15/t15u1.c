#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	
	int temp;
	FILE *fi;
	fi = fopen("numbers.txt", "r");
	if (fi == NULL)
	{
		printf("Sisendfail ei avanenud!\n");
		exit(1);
	}
	
	FILE *fo = fopen("even.txt", "w");
	if (fo == NULL)
	{
		printf("Väljundfail ei avanenud!\n");
		fclose(fi);
		exit(1);
	}	
	
	FILE *fp = fopen("odd.txt", "w");
	if (fp == NULL)
	{
		printf("Väljundfail ei avanenud!\n");
		fclose(fi);
		fclose(fo);
		exit(1);
	}	
	
	while (fscanf(fi, "%d", &temp) == 1)
	{
		if (temp > 0)
		{
			printf("Sain %d\n", temp);
			
			if (temp % 2 == 0)
			{
				fprintf(fo, "Sain %d\n", temp);
			}
			else
			{
				fprintf(fp, "Sain %d\n", temp);
			}
		}
	}
	
	fclose(fi);
	fclose(fo);
	fclose(fp);
	return 0;
}
