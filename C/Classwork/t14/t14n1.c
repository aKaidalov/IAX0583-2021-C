#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//argumentide seaded
#define ARG_COUNT 4
#define ARG_POS_OPERAND_1 1
#define ARG_POS_OPERAND_2 3

//veakoodid
#define ERR_INVALID_ARG_CNT 0

void InputError(int code);
void AirDebugPrint(int argc, char **argv);
int CheckAndConvert(char operand[]);


int main (int argc, char *argv[])
{
	AirDebugPrint(argc, argv);
	int operand1, operand2;
	double answer;
	
	if (argc != ARG_COUNT)
	{
		InputError(ERR_INVALID_ARG_CNT);
	}
	
	operand1 = CheckAndConvert(argv[ARG_POS_OPERAND_1]);
	operand2 = CheckAndConvert(argv[ARG_POS_OPERAND_2]);
	
	answer = operand1 + operand2;
	
	printf(">%.2f\n", answer);
	
	return EXIT_SUCCESS;
}

void InputError(int code)
{
	printf("Error %d!\n", code);
	exit(EXIT_FAILURE);
}

int CheckAndConvert(char operand[])
{
	int i;
	for (i = 0; i < strlen(operand); i++)
	{
		//
	}
	return atoi(operand);
}

void AirDebugPrint(int argc, char **argv)
{
	int i;
	printf("Argumentide arv programmile: %d\n", argc);
	
	for (i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	
	//~ int j;
	//~ for (i = 0; i < argc; i++)
	//~ {
		//~ for (j = 0; j < strlen(argv[i]); j++)
		//~ {
			//~ printf("%c ", argv[i][j]);
		//~ }
		//~ printf("\n");
	//~ }
}
