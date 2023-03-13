#include <stdio.h>

void DebugPrint(char str[]);
void ReadString(char str[], int n);

#define LEN_STR 64

int main(void)
{
	char a[LEN_STR] = "";
	
	printf("Sisesta a: ");
	ReadString(a, LEN_STR);
	DebugPrint(a);
	return 0;
}

void ReadString(char str[], int n)
{
	//int lineFeedPosition;
	fgets(str, n, stdin);
	//lineFeedPosition = strlen(str - 1)
	//str[lineFeedPosition] = ...
	//str[strlen(str) - 1] = -- kompaktne viis
}

void DebugPrint(char str[])
{
	int i = 0;
	printf("str = <%s>\n", str);
	while (str[i])
	{
		printf("%c %3d\n", str[i], str[i]);
		i++;
	}
}
