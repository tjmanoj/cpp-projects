#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "GiftCard.hpp"

class Customer
{
private:
	int CustId;
	int AccountNo;
	string Name;
	float balance;
	string password;
	//bool isGiftCard;
	//GiftCard gift;

public:
	Customer() : CustId(0), AccountNo(0), Name(""), balance(0.0), password("") {}

	Customer(int id, int accno, string name, float bal, string pass) : CustId(id), AccountNo(accno), Name(name), balance(bal), password(pass) {}

	// Setter methods
	/*void updateGiftCardStatus(bool status);

	void updategiftcard(int& cardNumber, int& PIN, float& amt);*/

	//Getter methods
	int getCusId();
	int getAccNo();
	string getName();
	float getBalance();
	string getPassword();
};

