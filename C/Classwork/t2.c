#include <stdio.h>

int main ()
{
	float accountBalance = 144.20f;
	const int pinCodeDebitCard = 1234;
	float purchaseTotal;
	int loyaltyCardPresented;
	int applyExtraDiscount;
	
	
	printf("Enter purchase total: ");
	scanf("%f", &purchaseTotal);
	
	printf("Did client present loyalty card?\n1 - yes\n2 - no\n ");
	scanf("%d", &loyaltyCardPresented);

	int i = 0;
	while (i < 1)
{
	if (loyaltyCardPresented == 1 || loyaltyCardPresented == 2)
{
		i++;
}
	else{
		printf("You have only two options. Try one more time.\n");
		scanf("%d", &loyaltyCardPresented);
	}
}
	
	
	printf("Apply extra discount?\n1 -yes\n2 - no\n");
	scanf("%d", &applyExtraDiscount);
	
	i = 0;
	while (i < 1)
{
	if (applyExtraDiscount == 1 || applyExtraDiscount == 2)
		i++;
		
	else
	{
		printf("You have only two options. Try one more time.\n");
		scanf("%d", &applyExtraDiscount);
	}
}
	
	if (loyaltyCardPresented == 1 && applyExtraDiscount == 1)
{
	purchaseTotal *= 0.8;	
}
	else if (loyaltyCardPresented == 1 && applyExtraDiscount == 2)
{
	purchaseTotal *= 0.9;	
}
	else
	purchaseTotal = purchaseTotal;
	
	printf("Invoice total: %.2f\n", purchaseTotal);
	
	
	int pinCodeEntered;
	printf("Enter your pin code.\n");
	scanf("%d", &pinCodeEntered);
	if (pinCodeEntered == pinCodeDebitCard)
{
	printf("Pin number is correct.\n");
}
	else
{
	#define ATTEMPT 3
	int i = 2;
	while (i < 4)
{
	printf("Pin number is incorrect. Try one more time. %d/%d\n", i, ATTEMPT);
	scanf("%d",  &pinCodeEntered);
	
	if (pinCodeEntered == pinCodeDebitCard)
{
		i += 3;
		printf("Pin number is correct.\n");
}
	
	else
	i++; 
		if (i == 4)
{	
	printf("Your card has been blocked.\n");
	return 0;
}
} 				
}
	
	if (accountBalance >= purchaseTotal)
		printf("You are all set.\n");
	
	else
{
			printf("Unfortunately there is not enough money on Your bank account.\n");
			return 0;
}
	
	accountBalance -= purchaseTotal;
	printf("Your account balance now: %.2f", accountBalance);
	
	
	return 0;	
}
