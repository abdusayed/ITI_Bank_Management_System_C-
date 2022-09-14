/***************************************************************************************/
/********************************  ABDELRAHMAN SAYED **********************************/
/***************************************************************************************/
/****** This file is developed by ABDELRAHMAN SAYED, All copyrights are reserved ******/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "Client.h"
#include "Admin.h"

#include <stdio.h>
#include <stdlib.h>

extern node  head;
extern u8 ListLength;

#define NOT_OPR		'0'
#define	ADMIN_MODE	'1'
#define	CLIENT_MODE	'2'

#define	CRT_NEW_ACC	'1'
#define	OPN_EXS_ACC	'2'
#define	EXT_SYS		'3'
#define	PRT_ALL_IDS	'4'

#define	MK_TRANS	'1'
#define	CHG_ACC_ST	'2'
#define	CHG_ACC_PW	'2'
#define	GET_CASH	'3'
#define	MK_DPST		'4'
#define	RT_MA_MNU	'5'

#define		TRUE     1
#define		FALSE    0

void main(void)
{
	u8 Selector = NOT_OPR;
	u8 EXT_Sys = NOT_OPR;
	node * ExistingAccount = NULL;					
	while(EXT_Sys!=EXT_SYS)
	{
		Selector = NOT_OPR;
		while (Selector != ADMIN_MODE && Selector != CLIENT_MODE&&EXT_Sys!=EXT_SYS)
		{
			system("cls");
			printf("/***************************************************************************************/\n");
			printf("/****************************  Welcome to ITI Bank System ******************************/\n");
			printf("Press \n\t1 Admin Mode \t\t\t\t\t2 Client Mode \n\n\t\t:");
			scanf("%c",&Selector);
			
		}
		switch(Selector)
		{
			case ADMIN_MODE :   //admin mode
			Selector = NOT_OPR;
				if(adminMode()==TRUE)
				{
					printf("WRONG DATA\n");
					printf("Press any key.......");
					getchar();
					getchar();			
				}
				else 
				{	
					printf("\t\t\t\t\tCORRECT DATA\n");
					printf("Press any key.......");
					getchar();
					getchar();
					while(Selector != EXT_SYS)
					{		
						Selector = NOT_OPR;
						while (Selector != CRT_NEW_ACC && Selector != OPN_EXS_ACC && Selector != EXT_SYS)
						{
							system("cls");
							printf("/***************************************************************************************/\n");
							printf("/***************************  ITI Bank System -- Admin Mode ****************************/\n");
							printf("Press \n\t1 Create a new Account \t\t\t\t2 Open an Existing Account  \n\t3 Exit The System\t\t\t\t4 Display All Existing Account\n\t\t:");
							scanf("%c",&Selector);
						}
							if(Selector==EXT_SYS)
							{
								Selector = NOT_OPR;
								break;
							}
							switch(Selector)
							{
								case CRT_NEW_ACC:
								createNewAccount();
								break;
								case OPN_EXS_ACC:
								if(ListLength==0)
								{
									printf("There is no Accounts yet\n");
									printf("Press Any Key .......");
									getchar();
									getchar();
									break;
								}
								else{
								printf("Enter The Account ID: ");
								openExistingAccount(&ExistingAccount);
								if(ExistingAccount != NULL)
								{
									while(TRUE)
									{
										Selector = NOT_OPR;
										while (Selector != MK_TRANS && Selector != CHG_ACC_ST && Selector != GET_CASH	&& Selector != MK_DPST && Selector != RT_MA_MNU)
										{
										system("cls");
										printf("/***************************************************************************************/\n");
										printf("/***************************  ITI Bank System -- Admin Mode ****************************/\n");
										printf("Press \n\t1 Make a Transaction \t\t\t\t\t2 Change Account Status   \n\t3 Get Cash\t\t\t\t\t\t4 Make a Deposit\n\t5 Return to Main Menu\n\t:");
										scanf("%c",&Selector);
										}
										if(Selector==RT_MA_MNU)
										{
											Selector = NOT_OPR;
											break;
										}
										switch(Selector)
										{
											case MK_TRANS://makeTransaction
											makeTransaction(ExistingAccount);
											break;
											case CHG_ACC_ST://change account status
											changeAccountStatus(ExistingAccount);
											break;									
											case GET_CASH://get cash
											getCash(ExistingAccount);
											getCash(ExistingAccount);
											break;
											case MK_DPST://deposit  in account
											makeDeposit(ExistingAccount);
											break;
										}
									
									}
								}
								break;
								case PRT_ALL_IDS:
								ExistingAccount = &head;
								while(ExistingAccount)
								{
									printf("%lu\n",ExistingAccount->data.accountID);
									ExistingAccount = ExistingAccount->Next;	
								}
								printf("%d\n",ListLength);
								printf("Press Any Key.......");
								getchar();
								getchar();				
								break;
								}
							}
				}
				}
			break;
			case CLIENT_MODE :  //client mode
			ExistingAccount = NULL;
				if(clientMode(&ExistingAccount)==FALSE)
				{
					printf("WRONG DATA\n");
					printf("Press any key...........");
					getchar();
					getchar();			
				}
				else 
				{	
					printf("\t\t\t\t\tCORRECT DATA\n");
					printf("Press any key...........");
					getchar();
					getchar();
					while(TRUE)
					{		
						Selector = NOT_OPR;
						while (Selector != MK_TRANS && Selector != CHG_ACC_PW	&& Selector != GET_CASH	&& Selector != MK_DPST && Selector != RT_MA_MNU)
						{
							system("cls");
							printf("/***************************************************************************************/\n");
							printf("/***************************  ITI Bank System -- Client Mode ****************************/\n");
							printf("Press \n\t1 Make a Transaction \t\t\t2 Change Account Password  \n\t3 Get Cash\t\t\t\t4 Deposit in Account\n\t5 Return to Main Menu\n\t\t:");
							scanf("%c",&Selector);
						}
							if(Selector==RT_MA_MNU)
							{
								Selector = NOT_OPR;
								break;
							}
							switch(Selector)
							{
								case MK_TRANS://make transaction
								makeTransaction(ExistingAccount);
								break;
								case CHG_ACC_PW:// change account password
								changeAccountPass(ExistingAccount);
								break;
								case GET_CASH:// get cash
								getCash(ExistingAccount);
								break;
								case MK_DPST://make a deposit
								makeDeposit(ExistingAccount);
								break;
							}
						
					}
				}
			break;
			
			default :
			break;
			
		}
	}
}
