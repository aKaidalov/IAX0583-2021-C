#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define NUM_OF_ROWS 14
#define NUM_OF_COLS 17

#define SEAT_OCCUPIED 2
#define SEAT_FREE 1
#define SEAT_MISSING 0


int main(void)
{
	int i, j, a;
	uint8_t hallCinema[NUM_OF_ROWS][NUM_OF_COLS];
	uint8_t cinemaHall[NUM_OF_ROWS][NUM_OF_COLS] = 
			{{2, 1, 1, 1, 1, 1, 2, 2, 2, 1, 2, 2, 1, 1, 1, 1, 1},
			 {0, 0, 1, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 1, 1},
			 {0, 0, 1, 1, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 1, 1},
			 {0, 0, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1},
			 {0, 0, 1, 1, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 1, 1, 1},
			 {0, 0, 1, 1, 2, 2, 1, 1, 1, 2, 2, 1, 1, 2, 1, 1, 0},
			 {0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 2, 2, 1, 1, 0},
			 {0, 0, 1, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 0},
			 {0, 0, 1, 1, 1, 1, 2, 2, 1, 2, 2, 1, 1, 1, 1, 0, 0},
			 {0, 0, 1, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 0, 0},
			 {0, 0, 1, 1, 1, 1, 2, 2, 1, 2, 2, 2, 1, 1, 1, 0, 0},
			 {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
			 {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
			 {0, 0, 0, 2, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0}};
		
	 int uusJ;
	 
	 for (i = 0; i < NUM_OF_ROWS; i++)
      {	
		int placeNumber = 0;
		a = NUM_OF_ROWS - i;
		printf("%2d", a);
		for (j = 0; j < NUM_OF_COLS; j++)
		{
			if (cinemaHall[i][j] == 0)
			{
				printf("    ");
			}
			else
			{
				placeNumber++;
				if (cinemaHall[i][j] == 2)
				{
				printf("\033[0;31m");
				printf("   X");
				}
				if (cinemaHall[i][j] == 1)
				{
				printf("\033[0;32m");
				printf("%4d", placeNumber);
				} 
				uusJ = placeNumber;
				hallCinema[i][uusJ] = cinemaHall[i][j];
			}					
		}	
		printf("\033[0m");
		printf("\n");			
	  }        
	  
	printf("\n				S C R E E N");  

	printf("\n\n\nEnter row and seat number: ");
	scanf("%d  %d", &i, &uusJ);

	//printf("\n%d", hallCinema[NUM_OF_ROWS - i][uusJ]);
	if (hallCinema[NUM_OF_ROWS - i][uusJ] == 1)
	{
		printf("\033[0;32m");
		 printf("\n\nSuccess! Ticket purchased!!\nEnjoy the movie!");
	}
	else if (hallCinema[NUM_OF_ROWS - i][uusJ] == 2)
	{
		printf("\033[0;31m");
		printf("\nSelected seat is already booked!");
	}
	printf("\033[0m");
	
	
	
	 
	return 0;
}
