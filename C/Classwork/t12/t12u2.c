#include <stdio.h>
#include <string.h>

#define MAX_STR 40

void ProcessPerson(char entry[]);

int main(void)
{
    char data[][MAX_STR] = {"Maria,Kask",
                            "Johanna-Maria,Kask",
                            "Kalev Kristjan,Kuusk"};
    int i;
    int numOfPeople = sizeof(data) / MAX_STR;

    printf("Number of people: %d\n", numOfPeople);
    for (i = 0; i < numOfPeople; i++)
    {
        ProcessPerson(data[i]);
    }
   
    return 0;
}

void ProcessPerson(char entry[])
{
    printf("Processing line: '%s'\n", entry);
   
   int i, j;
   char eesNimi[MAX_STR] = "";
   char pereNimi[MAX_STR] = "";
   char email[MAX_STR] = "";
   char domeen[] = "@ttu.ee";
   
   printf("Nimi: ");
   
   for (i = 0; entry[i] != '\0'; i++)
   {
		if (entry[i] == ',') // mis erinevus on "" ja '' vahel
		{					// '' - odin c (character) "" - string
			printf(" ");
			i++;
	    }
	   printf("%c", entry[i]);
   }
   printf("\n");
   
   i = 0;
   while (entry[i] != ',')
   {
	   if (entry[i] > 64 && entry[i] < 91)
	   {
		   entry[i] += 32;
		   eesNimi[i] = entry[i];
	   }
	   eesNimi[i] = entry[i];
	   //printf("%c", eesNimi[i]);
	   i++;
	   
   }
   
   i++;   
   j = 0;
   while (entry[i] != '\0')
   {
	   if (entry[i] > 64 && entry[i] < 91)
	   {
		   entry[i] += 32;	
		   pereNimi[j] = entry[i];
	   }
	   pereNimi[j] = entry[i];
	   //printf("%c", pereNimi[j]);
	   j++;
	   i++;
   }
      
      //~ printf("\n");
   
   for (i = 0; i < 3; i++)
   {
	   email[i] = eesNimi[i];
   }
   
    for (j = 0; j < 3; i++, j++)
   {
	   email[i] = pereNimi[j];
   }
   
   strcat(email, domeen);
   
   printf("Email: %s\n\n", email);
}

