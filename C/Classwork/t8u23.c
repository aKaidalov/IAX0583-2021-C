#include <stdio.h>
#include <stdbool.h>

#define SORTING_FACILITY_SIZE 10

void MassiiviValjatrukkimine(int arvud[],int pikkus);
void MahubSorteerimiskeskusse(int kokku, int suurus);
int LadudeUmbert6stmine (int suurusA, int suurusB, int sortingArr[],
														int aArr[], int bArr[]);
void SorteerimineMulsordiMeetodil(int totalIntSorting, int arvudArr[]);

int main(void)
{
	int totalCargo;
    
    int storageA[] = {17, 4, 9, 15, 2, 11, 44};
    int storageB[] = {15, 9, 2, 13, 1};
    int sortingFacility[SORTING_FACILITY_SIZE];
    
    int totalA = sizeof(storageA) / sizeof(int);
    int totalB = sizeof(storageB) / sizeof(int);

	totalCargo = totalA + totalB;
	
	printf("Warehouse A contains:\n");
	MassiiviValjatrukkimine(storageA, totalA);
	printf("Warehouse B contains:\n");
	MassiiviValjatrukkimine(storageB, totalB);
	
	MahubSorteerimiskeskusse(totalCargo, SORTING_FACILITY_SIZE);
	
	int a = LadudeUmbert6stmine (totalA, totalB, sortingFacility, storageA,
																	storageB);
	
	SorteerimineMulsordiMeetodil(a, sortingFacility);
  
    return 0;
}

	
void MassiiviValjatrukkimine(int arvud[],int pikkus)
{
	int i;
	for (i = 0; i < pikkus; i++)
    {
        printf("%d ", arvud[i]);
    }
    printf("\n\n");
}

void MahubSorteerimiskeskusse(int kokku, int suurus)
{
	 if (kokku < suurus)
    {
        printf("All %d item(s) will be shipped to sorting", kokku);
    }
    else
    {
        printf("Only %d / %d items will be shipped to sorting",
            suurus, kokku);
    }
    printf("\n\n");
}

int LadudeUmbert6stmine (int suurusA, int suurusB, int sortingArr[],
														int aArr[], int bArr[])
{
	int i, kokku = SORTING_FACILITY_SIZE;
	int totalInSorting = 0;
    for (i = 0; i < suurusA && totalInSorting < kokku; i++)
    {
        sortingArr[totalInSorting] = aArr[i];
        totalInSorting++;
    }
    for (i = 0; i < suurusB && totalInSorting < kokku; i++)
    {
        sortingArr[totalInSorting] = bArr[i];
        totalInSorting++;
    }
    return totalInSorting;
}

void SorteerimineMulsordiMeetodil(int totalInSorting, int arvudArr[])
{
	int i, j, temp;
	bool sorted;
	for (i = 0, sorted = false; !sorted; i++)
    {
        /* assume that the array is sorted unless any swaps happen */
        sorted = true;
        
        for (j = 0; j < totalInSorting - 1 - i; j++)
        {
            if (arvudArr[j] < arvudArr[j + 1])
            {
                temp = arvudArr[j];
                arvudArr[j] = arvudArr[j + 1];
                arvudArr[j + 1] = temp;
                /* since we had to swap something, it was not sorted */
                sorted = false;
            }
        }
    }
    printf("Exit order to the sorting facility:\n");
    MassiiviValjatrukkimine(arvudArr, totalInSorting);

}
