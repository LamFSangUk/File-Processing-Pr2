#ifndef __PROG_PURCHASESYSTEM__
#define __PROG_PURCHASESYSTEM__

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include"class_member.h"
#include"conio.h"

using namespace std;

void purchasesystem();
void AdminMode();
void UserMode(string);
void PurchaseUser(string user_id);
void MyInfoAdmin(string user_id);
void MemberFileCompaction();
void StockFileCompaction();
void PurchaseFileCompaction();

#endif