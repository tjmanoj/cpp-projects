#include "Customer.hpp"


int Customer::getCusId() {
	return this->CustId;
}

int Customer::getAccNo() {
	return this->AccountNo;
}

string Customer::getName() {
	return this->Name;
}

float Customer::getBalance() {
	return this->balance;
};

string Customer::getPassword() {
	return this->password;
};


//void Customer::updateGiftCardStatus(bool status) {
//	this->isGiftCard = true;
//}
//
//void Customer::updategiftcard(int& cardNumber, int& PIN, float& amt) {
//	this->gift.setCardNumber(cardNumber);
//	this->gift.setPin(PIN);
//	this->gift.setBalance(amt);
//}