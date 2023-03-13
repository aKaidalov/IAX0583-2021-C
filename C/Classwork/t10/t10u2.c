#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TOTAL_LOTTO 10  /* lototroni poolt genereeritavate numbrite arv */
#define TOTAL_USR 6     /* kasutaja poolt sisestavate numbrite arv */

#define BALL_MIN 1      /* vähim lubatud lotonumber */
#define BALL_MAX 25     /* maksimaalne lubatud lotonumber */


void CollectUserNums(int nums[], int len);
int GetUserNumbInRange(int min, int max);
void GenerateLotteryNumbers(int nums[], int len);
int GenerateRandomNum(int min, int max);
void PrintNumbers(int nums[], int len);
int FindMatchCount(int lotteryNumbers[], int lenLottery, int userNumbers[],
                   int lenUser);
bool IsNumInArray(int nums[], int len, int num);

int main(void)
{
    /* 0. Deklareeri kõik oma vajalikud muutujad */
    int userNums[TOTAL_USR], lotteryNums[TOTAL_LOTTO];
    int luckyNums = 0;
    
    /* 1. Kutsu funktsioon kasutaja arvude lugemiseks (CollectUserNums) */
    CollectUserNums(userNums, TOTAL_USR);
    
    /* 2. Kutsu funktsioon lotoarvude genereerimiseks (GenerateLotteryNumbers) */
    GenerateLotteryNumbers(lotteryNums, TOTAL_LOTTO);
    
    /* 3.1. Kutsu funktsioon lotoarvude väljatrükkimiseks (PrintNumbers)*/
    printf("\nLotoarvud on sel korral: \n");
    PrintNumbers(lotteryNums, TOTAL_LOTTO);
    
    /* 3.2. Kutsu funktsioon kasutaja arvude väljatrükkimiseks (PrintNumbers)
     *      See on kasulik enesekontrolliks, et kõik sai korrektselt sisse loetud! */
    printf("\nTeie sisestatud arvud on: \n");
    PrintNumbers(userNums, TOTAL_USR);
    
    /* 4. Kutsu funktsioon kattuvate numbrite leidmiseks ja kuvamiseks (FindMatchCount) */
    printf("\n");
    
    luckyNums = FindMatchCount(lotteryNums, TOTAL_LOTTO, userNums, TOTAL_USR);
    
    printf("\n\n");
    /* 5. Kuva lõppjäreldus - selle võid siin teha või uue funktsiooni luua */
	if (luckyNums == TOTAL_USR)
	{
		printf("Onnitleme peavoidu korral!\n");
	}
	else if(luckyNums == 0)
	{
		printf("Avaldame kaastunnet! Seekord ei kattunud ükski arv.\n");
	}
	else
	{
		printf("Seekord kattus %d/%d arvust.\n", luckyNums, TOTAL_USR);
	}
	
    return 0;
}

/**
 * Funktsioon loeb sisse kasutaja poolt antavad numbrid. Funktsioonis
 * ise lugemiskäske ei ole, vaid funktsioon kutsub esile järgmise funktsiooni
 * GetUserNumbInRange(), et lugeda ÜKS arv sisse ning salvestab tagastatud
 * väärtuse massiivi. Seda tehakse tsüklis len arv kordi.
 */
void CollectUserNums(int nums[], int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		printf("Sisesta arv %d/%d: ", i + 1, len);
		nums[i] = GetUserNumbInRange(BALL_MIN, BALL_MAX);
	}
}

/**
 * Funktsioon loeb kasutajalt ühe arvu. Kontrollitakse, et arv oleks vahemikus
 * min ja max. Otspunktid on mitteranged ehk min ja max on samuti lubatud.
 * Funktsioon küsib arvu senikaua, kuniks sisestus jääb
 * etteantud vahemikku, seejärel tagastab väärtuse.
 */
int GetUserNumbInRange(int min, int max)
{
	int number;
	do
	{
		scanf("%d", &number);
		if (number < min || number > max)
		{
			printf("Viga! Arv peab olema vahemikus %d .. %d \n", min, max);
		}
	}
	while (number < min || number > max);
	return number;
}

/**
 * Funktsioon trükib kaasa antud massiivi (nums) väärtused ühele reale, jättes
 * iga numbri vahele tühiku. Massiivi pikkuseks on len. Numbrite väljatrükile
 * järgneb reavahetus. 
 */
void PrintNumbers(int nums[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
		printf("%d ", nums[i]);
	}
	printf("\n");
}

/**
 * Funktsioon genereerib lotonumbreid ja salvestab need massiivi.
 * Funktsiooni sees ise numbrit ei genereerita, vaid kutsutakse välja vastav
 * järgnev funktsioon GenerateRandomNum(), mis tagastab juhusliku numbri.
 * Tagastatud number salvestatakse massiivi
 *
 * Midagi ekraanile kuvada siin funktsioonis ei tohi.
 */
void GenerateLotteryNumbers(int nums[], int len)
{
	int i;
	srand(time(NULL));
	for(i = 0; i < len; i++)
	{
		nums[i] = GenerateRandomNum(BALL_MIN, BALL_MAX);
	}
}

/**
 * Antud funktsioon genereerib ühe juhuarvu. Juhuarv genereeritakse vahemikus
 * min .. max, kusjuures otspunktid on lubatud. Genereeritud arv tagastatakse.
 *
 * Üldvalem: rand() % unikaalsete_tulemuste_arv + vähim_lubatud_arv
 */
int GenerateRandomNum(int min, int max)
{
	int num;
	//~ srand(time(NULL));
	num = rand() % max + min;

	return num;
}

/**
 * Funktsioon võtab endale 2 massiivi ja nende massiivide pikkused.
 * Funktsiooni eesmärgiks on teada saada mitu numbrit massiivides osutuvad
 * kattuvateks. Ühe massiivi numbri esinemist teises massiivis kontrollitakse
 * kasutades funktsiooni IsNumInArray(). Kattuvuste arv tagastatakse.
 *
 * Kattuvuse leidmisel trükitakse kattuv number välja siin funktsoonis.
 */
int FindMatchCount(int lotteryNumbers[], int lenLottery, int userNumbers[],
                   int lenUser)
{
	int i, j, kattuvused;
	printf("Kattuvad numbrid on: \n");
	
	for (i = 0; i < lenUser; i++)
	{
		if (IsNumInArray(lotteryNumbers, lenLottery, userNumbers[i]))
		{
			printf("%d ", userNumbers[i]);
			kattuvused++;
		} 
		for (j = 0; j < lenLottery; j++)
		{
			if (userNumbers[i] == lotteryNumbers[j])
			{
				lotteryNumbers[j] = 0;
				break;
			}
		}
	}
	
	return kattuvused;
}

/**
 * Järgnev funktsioon kontrollib kas muutuja value väärtus
 * esineb juba massiivis nums või mitte. Nums massiiv pikkus on len.
 * Tagastatakse vastus kas number oli massiivis või mitte.
 *
 * Midagi ekraanile kuvada siin funktsioonis ei tohi.
 */
bool IsNumInArray(int nums[], int len, int value)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (value == nums[i])
		{
			return true;
		}
	}
	
	return false;
}
