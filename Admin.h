/***************************************************************************************/
/********************************  ABDELRAHMAN SAYED **********************************/
/***************************************************************************************/
/****** This file is developed by ABDELRAHMAN SAYED, All copyrights are reserved ******/
/***************************************************************************************/

#ifndef _ADMIN_H
#define _ADMIN_H

u8	 adminMode(void);					// This Function Checks for Admin Username & Password
void createNewAccount(void);			// This Function Creates a New Account then adds it to the Linked List


void openExistingAccount(node **);		// THis Function Scans Account ID and search for it in the Linked List
void addData(node * Client);				// THis Function Scans The Account Data from the user and stores it in the Account


void displayData(node * Client);			// THis Function Displays The Data of the Account
void makeTransaction(node * Client);		// THis Function makes Transaction Between Two Accounts 


void changeAccountStatus(node * Client);	// THis Function Changes the status of the Account
void getCash(node * Client);				// THis Function Withdraw Cash from The Account


void makeDeposit(node * Client);			// THis Function Deposits Cash to the Account

#endif