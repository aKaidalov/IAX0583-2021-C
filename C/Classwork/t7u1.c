#include <stdio.h>
#include <inttypes.h>

#define SIZE 7

int main(void)
{
	int i, j, summa = 0;
	int64_t korrutis = 1;
	int suurim;
    int matrix[SIZE][SIZE] = {{10, 9, 8, 0, -10, 8, 5},
                              {7, 6, 9, 1, -7, -9, 4},
                              {-5, 5, -5, 5, -5, 5, -5},
                              {8, 7, 6, 5, 4, 3, 2},
                              {1, 2, 3, 4, 5, 6, 7},
                              {-1, -2, -3, -4, -3, -2, -1},
                              {0, 0, 0, 0, 0, 0, 0}};
           
                              
      for (i = 0; i < SIZE; i++)
      {
			suurim = matrix[i][0];
			
			for (j = 0; j < SIZE; j++)
			{
				printf("%4d", matrix[i][j]); 
				
				 if (i == j && matrix[i][j] < 0)  
				 {
					summa += matrix[i][j]; 
				 }
				 
				 if (i + j < SIZE - 1 && matrix[i][j] > 0)  
				 {
					korrutis *= matrix[i][j]; 
				 } 
				
				 if (matrix[i][j] > suurim)
				 {			 
					suurim = matrix[i][j];
				 }
				 
			}
				printf("\n");
				printf("\n%d rea suurim arv oli: %d\n\n", i + 1, suurim);
				
	  }        
	  
	  
	  
	  
	  printf("\nPeadiagonaali negatiivsete elementide summa on: %d", summa);  
	  printf("\nKõrvaldiagonaali kohal olevate positiivsete arvude korrutis on: %" PRId64 "",
																		korrutis);             
	 //~ for (i = 0; i < SIZE; i++)
	  //~ printf("\n%d rea suurim arv oli: %d", i + 1, suurim);
	
	
    return 0;
}
