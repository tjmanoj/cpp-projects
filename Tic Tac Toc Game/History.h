#pragma once
#include <bits/stdc++.h>
using namespace std;

class History
{
private:
	string user1;
	string user2;
	string winner;
	string Time;
	string mode;


public:
	History() : user1(""),user2(""),winner(""),Time(""), mode("") {}

	//setter functions

	void setuser1(string name);

	void setuser2(string name);

	void setWinner(string winner);

	void setTime();

	void setMode(int mode);

	//getter functions

	string getuser1();

	string getuser2();
	
	string getWinner();

	string getTime();

	string getMode();






	void getPlayerDetails(History &p);

	void SaveDetails(History &p);

	void DisplayHistory();
};

