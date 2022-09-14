/***************************************************************************************/
/********************************  ABDELRAHMAN SAYED **********************************/
/***************************************************************************************/
/****** This file is developed by ABDELRAHMAN SAYED, All copyrights are reserved ******/
/***************************************************************************************/

#ifndef _PRIVATE_H
#define _PRIVATE_H

enum Status{
	Restricted=2,
	Active=1,
	Closed=3
};

typedef struct 		//The Structure Containing all The Account Data 
{
	u64 nationalID;
	u32 accountID;
	u32 guardianID;
	u32 balance;
	u8 fullName[4][20];
	u8 fullAddress[6][20];
	u8 age;
	enum Status accountStatus;
	u8 accountPassword[20];
}user;

typedef struct Node_type node;

struct Node_type{
    user data;
    node *Next;
};

#endif