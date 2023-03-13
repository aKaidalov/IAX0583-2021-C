#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Write your constants here */
#define LIMIT_ROWS 20
#define LIMIT_COLS 20
#define RAND_LOWER 0
#define RAND_UPPER 99
#define MENU_OPTION_MIN 0
#define MENU_OPTION_MAX 4

/**
 * Write your prototypes here. Some have been made for you. You're allowed to change the existing ones,
 * but not recommended to do so unless certain in yourself!
 *
 * The first two functions (Menu and GetIntInRange) have been completed for you.
 * The next two have only prototypes and comments what you need to do! (look below main() to find them!)
 */
int Menu(void);
int GetIntInRange(int min, int max);
void GenerateMatrix(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols);
void DisplayMatrix(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols);
void switchrows(int matrix[LIMIT_ROWS][LIMIT_COLS], int first, int second, int cols);
void switchcols(int matrix[LIMIT_ROWS][LIMIT_COLS], int first, int second, int rows);

int main(void)
{
    int data[LIMIT_ROWS][LIMIT_COLS] = {{0}}; /* initialize the matrix to zeros */
    int menuSelection;
    int selectedcols, selectedrows, firstrow, secondrow, firstcol, secondcol;
 
	menuSelection = 1;

    do
    {
        switch (menuSelection)
        {
            case 1:
                puts("Case 1: Enter new matrix dimensions and generate matrix");
				printf("Enter the row dimension of the matrix: ");
				selectedrows = GetIntInRange(RAND_LOWER + 1, LIMIT_ROWS);
                printf("Enter the column dimension of the matrix: ");
				selectedcols = GetIntInRange(RAND_LOWER + 1, LIMIT_COLS);
                GenerateMatrix(data, selectedrows, selectedcols);
                break;
               
            case 2:
                puts("Case 2: Print matrix");
                DisplayMatrix(data, selectedrows, selectedcols);
                break;
            case 3:
                puts("Case 3: Switch rows");
                printf("Select first row:\n");
                firstrow = GetIntInRange(RAND_LOWER + 1, selectedrows);
                printf("Select second row:\n");
                secondrow = GetIntInRange(RAND_LOWER + 1, selectedrows);
                switchrows(data, firstrow, secondrow, selectedcols);
                break;
            case 4:
                puts("Case 4: Switch columns");
                printf("Select first col:\n");
                firstcol = GetIntInRange(RAND_LOWER + 1, selectedcols);
                printf("Select second col:\n");
                secondcol = GetIntInRange(RAND_LOWER + 1, selectedcols);
               
                switchcols(data, firstcol, secondcol, selectedrows);
                break;
            case 0:
                puts("Case 0: Exiting");
                break;
            default:
                puts("Case unknown: We didn't understand Your request");
                break;
        }
        menuSelection = Menu();
    }
    while (menuSelection);
    return 0;
}

/**
 * Function:       Menu
 * Description:    Displays the possible menu options to the user,
 *                 allows to select an action to perform.
 *
 * Parameters:     None
 *
 * Return:         Integer, corrensponds to the menu selection from the list
 */
int Menu(void)
{
    int selection;
    putchar('\n');
    puts("Select Your action!");
    puts("1 - Generate new matrix");
    puts("2 - Display matrix");
    puts("3 - Switch rows");
    puts("4 - Switch columns");
    puts("0 - Exit program");
    selection = GetIntInRange(MENU_OPTION_MIN, MENU_OPTION_MAX);
    return selection;
}

/**
 * Function:       GetIntInRange
 *
 * Description:    Asks the user for an integer in between the given limits.
 *                 Repeats until requirements are met and then returns the number.
 *
 * Parameters:     min - integer, lower limit for the user input (inclusive)
 *                 max - integer, upper limit for the user input (inclusive)
 *
 * Return:         Integer, number within the specified limits
 */
int GetIntInRange(int min, int max)
{
    int num;
    do
    {
        printf("> ");
        scanf("%d", &num);
        if (num < min || num > max)
        {
			printf("\nRetry! Input must be in between %d and %d\n", min, max);
		}
    }
    while (num < min || num > max);
    return num;
}

/**
 * Function:       GenerateMatrix
 *
 * Description:    Generates random numbers and stores them into the given matrix. It only
 *                 generates the numbers in the area given by rows and cols, regardless of
 *                 the actual size given by macros.
 *                 The random numbers will be in between RAND_LOWER and RAND_UPPER.
 *
 * Parameters:     matrix - 2-dimensional array to store the numbers into,
 *                 size at declaration is given by macros.
 *                 rows - integer, number of rows to generate regardless of the actual size
 *                 cols - integer, number of columns to generate regardless of the actual size
 *
 * Return:         void
 */
void GenerateMatrix(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols)
{
	int i, j;
	int num;
	srand(time(NULL));

	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			num = rand() % RAND_UPPER + RAND_LOWER;
			matrix[i][j] = num;
		}
	}
}

/**
 * Function:       DisplayMatrix
 *
 * Description:    Displays a matrix that is given to the function. It only prints out the area
 *                 designated by rows and cols, regardless of the actual size given by macros.
 *
 * Parameters:     matrix - 2-dimensional array to be printed, size  at declaration is given by macros.
 *                 rows - integer, number of rows to display regardless of the actual size
 *                 cols - integer, number of columns to display regardless of the actual size
 *
 * Return:         void
 */
void DisplayMatrix(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols)
{
    int i = 0;
    while (i < rows)
    {
		int j = 0;
		while (j < cols)
		{
			printf("%d\t", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void switchrows(int matrix[LIMIT_ROWS][LIMIT_COLS], int first, int second, int cols)
{
	int temp, j;
	first--;
	second--;
	for(j = 0; j < cols; j++)
	{
		temp = matrix[first][j];
		matrix[first][j] = matrix[second][j];
		matrix[second][j] = temp;
	}
}

void switchcols(int matrix[LIMIT_ROWS][LIMIT_COLS], int first, int second, int rows)
{
	int temp, i;
	first--;
	second--;
	for(i = 0; i < rows; i++)
	{		
		temp = matrix[i][first];
		matrix[i][first] = matrix[i][second];
		matrix[i][second] = temp;
	}
}


