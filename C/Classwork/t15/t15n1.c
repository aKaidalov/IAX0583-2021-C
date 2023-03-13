#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 128

int main(void)
{
	//~ FILE *fi;
	
	//~ int temp;
	//~ char inputFile[] = {"numbers.txt"};
	
	//~ fi = fopen(inputFile, "r");
	//~ while (fscanf(fi, "%d", &temp) != EOF)
	//~ {
		//~ printf("Got: %d\n", temp);
	//~ }
	//~ fclose(fi);
	//---------------------------------------
	//~ FILE *fi;
	
	//~ int temp;
	//~ char nimi[NAME_LEN];
	
	//~ fi = fopen("andmed.txt", "r");
	
	//~ if (fi == NULL)
	//~ {
		//~ printf("Sisendfail ei avanenud!\n");
		//~ exit(1);
	//~ }
	
	//~ while (fscanf(fi, "%s %d", nimi, &temp) == 2)
	//~ {
		//~ printf("Got: %s %d\n", nimi, temp);
	//~ }
	//~ fclose(fi);
	
	int temp;
	FILE *fi;
	fi = fopen("numbers.txt", "r");
	if (fi == NULL)
	{
		printf("Sisendfail ei avanenud!\n");
		exit(1);
	}
	
	FILE *fo = fopen("result.txt", "w");
	if (fo == NULL)
	{
		printf("Väljundfail ei avanenud!\n");
		fclose(fi);
		exit(1);
	}	 
	
	while (fscanf(fi, "%d", &temp) != EOF)
	{
		printf("Sain %d\n", temp);
		fprintf(fo, "Sain %d\n", temp);
	}
	fclose(fi);
	fclose(fo);
	return 0;
}
