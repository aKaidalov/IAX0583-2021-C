#include <stdio.h>
#include <math.h>

int main(void) {
	
	int i, j; //Deklareerime loendurid 
	int sumPos = 0;
	int A[6][7] = {
	{8,  6, -9,  5,  6,  2,  6},
    {2, -8, -7,  6, -5,  3,  3},
    {1, -7,  3, -4,  1, -2,  2},
    {8,  2, -6,  4,  8,  2,  9},
    {1,  5,  2,  6, -2,  5, -7},
    {5,  6,  1,  9,  2,  6, -8},
    }; //Meie maatriks
	
	i = 0;
	j = 5;
	while(j >= 0){
		if (A[i][j] > 0){
			sumPos = sumPos + A[i][j];
			printf("%d\n", A[i][j]);		// Neprevilno sdelannoe zadanie.											
		}									// Nuzno cikl v cikle (for)
		i++;								// Valesti tehtud. Vaata ulesanne kinosaaliga. 7. tund.
		j--;
	}
		
	printf("Maatriskis positiivsete arvude summa on: %d\n", sumPos);
	
	return 0;
}
