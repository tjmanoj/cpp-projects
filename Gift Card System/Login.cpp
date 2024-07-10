#include "Login.hpp"
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

void Login::getCredentials(unordered_map<int, Customer>& db) {
	int id;
	string pass;
	cout << "Enter customer id: ";
	cin >> id;

	bool isCus = this->authenticateId(id,db);

	if (isCus) {
		cout << "Enter your Password: ";
		cin >> pass;
		
		string oldPass = db[id].getPassword();

		bool isValidPassword = this->authenticatePass(decrypt(oldPass), pass);

		if (isValidPassword) {
			this->LoginPage(db[id]);
			return;
		}
		else {
			cout << "Incorrect Password!" << endl;
			return;
		}
	}
	else {
		cout << "Customer Not Found!" << endl;
		return;
	}
	return;
}

bool Login::authenticateId(int id, unordered_map<int, Customer>& db) {
	for (auto i : db) {
		if (i.first == id) return true;
	}
	return false;
}

string Login::decrypt(string password) {
	string pass = password;
	for (int i = 0; i < pass.size(); i++) {
		char c = pass[i] - 1;
		pass[i] = c;
	}
	return pass;
}

bool Login::authenticatePass(string original, string entered) {
	return original == entered;
}


void Login::DisplayCustomerDetails(Customer &cus) {
	cout << "Customer Id	: " << cus.getCusId() << endl;
	cout << "Account No	: " << cus.getAccNo() << endl;;
	cout << "Name		: " << cus.getName() << endl;;
	cout << "Balance		: " << cus.getBalance() << endl;;
	return;
}

void Login::DisplayOptions() {
	cout << "OPTIONS" << endl;
	cout << "1.Create a new Gift Card" << endl;
	cout << "2.Top Up the existing Card" << endl;
	cout << "3.Show Gift Card Transaction History" << endl;
	cout << "4.Block the existing Card" << endl;
	cout << "5.Logout" << endl;
	return;
}

void Login::LoginPage(Customer &cus) {
	system("cls");
	this->DisplayCustomerDetails(cus);
	cout << "Login Successful !!";
	_getch();

	int choice;
	do {
		system("cls");
		this->DisplayOptions();
		cin >> choice;

		switch (choice) {
			case 1:
				/*GiftCard g;
				g.generateGiftCard(cus);*/
				cout << "Created";
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				cout << "Logged Out!" << endl;
				return;
				break;
			default:
				cout << "Invalid choice!";
				_getch();
				break;
		}
	} while (1);
	return;
}