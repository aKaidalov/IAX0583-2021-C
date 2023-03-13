#include <stdio.h>

int MassiiviSuuruseLeidmine();
void MassiivideSisestus(int mSuurus, float euro[], float kg[]);
void HinnaArvutamine(int mSuurus,float euro[],float kg[],float kiloHind[]);//Kiloo hinna arvutamise funktsioon
void MassiivideValjaPrintimine(int mSuurus, float kiloHind[], float euro[], float kg[]);
int MituToodetSobisid(int mSuurus, float kiloHind[], float tolerants);
void SobivatePakkumisteTooteValjaprintimine(int suurus, int mSuurus,
float kiloHind[], float tolerants);

int main(void)
{
	int massiivideSuurus = MassiiviSuuruseLeidmine();//Leib massiivi suuruse, loeb esinesmt arvu filist
	float hind[massiivideSuurus], kaal[massiivideSuurus];
	float kgHind[massiivideSuurus];
	float hinnatolerants;
	int pikkus;
	 
	MassiivideSisestus(massiivideSuurus, hind, kaal);
	//~ printf("massiivi arv on : %d\n",massiivideSuurus);
	HinnaArvutamine(massiivideSuurus,hind,kaal,kgHind);//Arvutab kilo hinnad
	MassiivideValjaPrintimine(massiivideSuurus, kgHind, hind, kaal);//prindib hinna ja kaalu ja kg hinna
	printf("\n\n");
	printf("Sisesta maksimaalne kilo hind: ");//Kysib kasutajal maksimaalselt kilohinda
	scanf("%f", &hinnatolerants);
	printf("\nMaksimaalne kilohind : %.2f\n",hinnatolerants);//Printib maksimaale kilohinna
	pikkus = MituToodetSobisid(massiivideSuurus, kgHind, hinnatolerants);
	SobivatePakkumisteTooteValjaprintimine(pikkus, massiivideSuurus,
												kgHind, hinnatolerants);
 
	return 0;
}

int MassiiviSuuruseLeidmine()
{
	int mSuurus;
	printf("Massiivide suurus: ");
	scanf("%d", &mSuurus);
	if (mSuurus < 1 || mSuurus > 15)
	{
		printf("\nViga! Massiivi suurus peab olema vahemikus 1...15! ");
		return 0;//Tagastab nulli kui suurus, ei ole 1 ja 15-ne vahel
	}
	return mSuurus;//Tagastab kasutaja poolt antud suuruse
}

void MassiivideSisestus(int mSuurus, float euro[], float kg[])
{
	//~ printf("\n");
	int i = 0;
	while (i < mSuurus)
    {
		printf("Sisestage hind  ja kilo (%d/%d): ", i + 1, mSuurus);
		scanf("%f %f", &euro[i],&kg[i]);
		
		i++;
	}
}

//Kilto hinna arvutamise funktsioon
void HinnaArvutamine(int mSuurus,float euro[],float kg[],float kiloHind[])
{
	int i = 0;
	while(i < mSuurus)
	{
		kiloHind[i] = euro[i] / kg[i];
		i++;
	}
}

void MassiivideValjaPrintimine(int mSuurus, float kiloHind[], float euro[], float kg[])
{
	printf("\n");
	int i;
	for (i = 0; i < mSuurus; i++)
	{
		//~ kiloHind[i] = euro[i] / kg[i];
		printf("PAKKUMINE%02d: ", i + 1);
		printf("%3.f %3.f %6.2f", euro[i], kg[i], kiloHind[i]);//Loeb andmeid jarjest alustades koige esimesest numbrist.
		printf("\n");
	}
}

int MituToodetSobisid(int mSuurus, float kiloHind[], float tolerants)
{
	int i;
	int suurus = 0;
	for (i = 0; i < mSuurus; i++)
	{
		if (kiloHind[i] <= tolerants)
		{
			suurus++;
		}
	}
	printf("Leitud %d kriteeriumile vastavat pakkumist.", suurus);
	return suurus;
}

void SobivatePakkumisteTooteValjaprintimine(int suurus, int mSuurus,
 float kiloHind[], float tolerants)
{
		
	int i, j;
	int pos[suurus];
	
	for (i = 0, j = 0; i < mSuurus; i++)
	{
		if (kiloHind[i] <= tolerants)
		{
			pos[j] = i + 1;
			j++;
		}
	}
	
	printf("\n");
	printf("Sobivad pakkumised on: ");
	for(j = 0; j <= suurus; j++)
	{
		if (j == suurus)
		{
			printf(".");
			break;
		}
		printf(" PAKKUMINE%02d", pos[j]);
		if (j < suurus - 1)
		{
			printf(",");
		}

	}
}
