/***************************************************************************************/
/********************************  ABDELRAHMAN SAYED **********************************/
/***************************************************************************************/
/****** This file is developed by ABDELRAHMAN SAYED, All copyrights are reserved ******/
/***************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include <string.h>

#include "Client.h"
#include "Admin.h"

extern node* head;

#define		NOT_EXIST		0
#define		EXIST			1

u8 clientMode(node ** ExistingAccount)
{
	u32 accountID;
	u8 password[20];
	system("cls");
	system("cls");
	printf("/***************************************************************************************/\n");
	printf("/**************************  ITI Bank System -- Client Mode ****************************/\n");
	printf("Please Enter your Account ID:");
	openExistingAccount(ExistingAccount);	//Search for The Account ID
	if (*ExistingAccount != NULL)		//If The Account ID is Found
	{	
		printf("\nPlease Enter your Password:");
		scanf("%s",&password);
		if(strcmp((*ExistingAccount)->data.accountPassword,password))	//IF The Password Entered is Wrong
		{	
			printf("Wrong Password");
			printf("Press any key........");
			getchar();
			getchar();
			return NOT_EXIST;
		}
		else
		{
			displayData(*ExistingAccount);
			return EXIST;
		}
	}
	else
	{
		printf("There is no such account");
		printf("Press any key........");
		getchar();
		getchar();
		return NOT_EXIST;
	}
} 
void changeAccountPass(node* ExistingAccount)
{
	u8 password[20];
	printf("\nPlease Enter your Password:");
	scanf("%s",&password);
	if(strcmp(ExistingAccount->data.accountPassword,password))
	{	
		printf("Wrong Password");
		printf("Press any key........");
		getchar();
		getchar();
	}
	else
	{
		printf("Correct Password");
		getchar();
		printf("\nPlease Enter your  New Password:");
		scanf("%s",&password);
		strcpy(ExistingAccount->data.accountPassword,password);
	}
	
}
	