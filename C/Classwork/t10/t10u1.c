/**
 * File:        kp_base.c
 * Author:      Risto Heinsar
 * Created:     05.10.2015
 * Edited:      07.04.2022
 *
 * Description: This is the basecode for the date verification lab task
 *              with functions. It is intended to be used through stream
 *              redirection, but can also be used from the keyboard. To
 *              use entry from the keyboard, press Ctrl+D (end of file
 *              signal) at any point during input.                 
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

#define DATE_INVALID 0
#define DATE_VALID 1

bool IsLeapYear(int year);
int GetDaysInMonth(int month, int year);
int ValidateDate(int day, int month, int year);
int ReadDates(int day[], int month[], int year[], int max);
void PrintDates(int day[], int month[], int year[], int n);

int main(void)
{
    int day[MAX], month[MAX], year[MAX];
    int totalDates;
    
    totalDates = ReadDates(day, month, year, MAX);
    PrintDates(day, month, year, totalDates);
    return 0;
}


/**
 * Description:    Reads in the dates to the day month and year arrays.
 *                 The same index in each of the arrays are used for the
 *                 same date.
 * 
 * Parameters:     day, int array, an array of day values
 *                 month, int array, an array of month values
 *                 year, int array, an array of year values
 *                 max, integer, the maximum size of the arrays.
 * 
 * Return:         none
 */
int ReadDates(int day[], int month[], int year[], int max)
{
    int i = 0;
    int checkVal;
    // kuni massiivi mahub, niikaua tohime lugeda
    while (i < max)
    {
		checkVal = scanf("%2d%2d%4d", &day[i], &month[i], &year[i]);
		
		if (checkVal != 3)
		{
			break;
		}
		
		i++;
	}
    
    return i; // tagastan loetud kuupäevade arvu
}


/**
 * Description:    Prints the dates in the arrays, assumes dates with
 *                 the same index in all three arrays are related.
 * 
 * Parameters:     day, int array, an array of day values
 *                 month, int array, an array of month values
 *                 year, int array, an array of year values
 * 
 * Return:         none
 */
void PrintDates(int day[], int month[], int year[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%02d.%02d.%04d ", day[i], month[i], year[i]);
		if (ValidateDate(day[i], month[i], year[i]) == DATE_VALID)
		{
			printf("OK!");
		}
		else
		{
			printf("Invalid date!");
		}
		printf("\n");
	}
}


/**
 * Description:    Function checks wheather the passed year is a leap year.
 * 
 * Parameters:     year, integer, the year to check
 * 
 * Return:         boolean, true for leap year, false for normal year.
 */
bool IsLeapYear(int year)
{
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/**
 * Description:    Function finds and returns the number of days in a month.
 *                 Month is given as an integer, starting from 1 (january).
 *                 Function handles leap years.
 * 
 * Parameters:     month, integer, month number starting from 1.
 *                 year, integer, the year of the date
 * 
 * Return:         Integer. For valid dates, it returns the number of days
 *                 in a month. For invalid dates, it returns 0.
 * 
 */
int GetDaysInMonth(int month, int year)
{
    int days;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || 
    month == 10 || month == 12)
    {
		days = 31;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		days = 30;
	}
	else if (month == 2 && IsLeapYear(year))
	{
		days = 29;
	}
	else if (month == 2)
	{
		days = 28;
	}
	
	return days;   
}


/**
 * Description:    Function finds if the date passed is valid or not.
 * 
 * Parameters:     day, integer, the day value.
 *                 month, integer, month number starting from 1.
 *                 year, integer, the year of the date
 * 
 * Return:         Integer. For valid dates, it returns DATE_VALID (0),
 *                 for invalid dates it returns DATE_INVALID (1).
 */
int ValidateDate(int day, int month, int year)
{
    if (year < 1900 || year > 2099)
    {
		return DATE_INVALID;
	}
	else if (month < 1 || month > 12) 
	{
		return DATE_INVALID;
	}
	else if (day < 1 || day > GetDaysInMonth(month, year))
	{
		return DATE_INVALID;
	}

    return DATE_VALID;
}
