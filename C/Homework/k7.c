#include <stdio.h>

#define SORTING_FACILITY_SIZE 25

int main(void)
{
	int i, j, temp, totalInSorting = 0;
	int storageA[] = {9, 4, 15, 2, 16, 4}; 
	int storageB[] = {11, 3, 8, 5, 10};
	int sortingFacility[SORTING_FACILITY_SIZE];
	int totalA = sizeof(storageA) / sizeof(int);
	int totalB = sizeof(storageB) / sizeof(int);
	
	printf("Warehouse A contains:\n");
	for (i = 0; i < totalA; i++)
	{
		printf("%d ", storageA[i]);
	}
	
	printf("\n\nWarehouse B contains:\n");
	for (i = 0; i < totalB; i++)
	{
		printf("%d ", storageB[i]);
	}
	
	if (totalA + totalB <= SORTING_FACILITY_SIZE)
	printf("\n\nAll %d items will be shipped to sorting!", totalA + totalB);
	
	else
	printf("\n\nOnly %d / %d items will be shipped to sorting!",
								SORTING_FACILITY_SIZE, totalA + totalB);
	
	for (i = 0; i < totalA && totalInSorting < SORTING_FACILITY_SIZE; i++)
	{
		sortingFacility[totalInSorting] = storageA[i];
		totalInSorting++;
	}
	
	for (i = 0; i < totalB && totalInSorting < SORTING_FACILITY_SIZE; i++)
	{
		sortingFacility[totalInSorting] = storageB[i];
		totalInSorting++;
	}					
	
	printf("\n\nEntry order to the sorting facility:\n");
	for (i = 0; i < totalInSorting; i++)
	{
		printf("%d ", sortingFacility[i]);
	}
	
	for (i = 0; i < totalInSorting; i++)
	{
		for (j = 0; j < totalInSorting - 1 - i; j++)
		{
			if (sortingFacility[j] > sortingFacility[j + 1])
			{
				temp = sortingFacility[j];
				sortingFacility[j] = sortingFacility[j + 1];
				sortingFacility[j + 1] = temp;
			}
		}
	}	
	
	printf("\n\nExit order to the sorting facility:\n");
	for (i = totalInSorting - 1; i >= 0; i--)
	{
		printf("%d ", sortingFacility[i]);
	}
	
	
	return 0;
}
