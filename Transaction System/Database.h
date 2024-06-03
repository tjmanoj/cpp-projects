#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#pragma once


class Database
{
private:
	unordered_map <string, string> individual_transaction;
	unordered_map <string, string> transaction;
	bool isbegin = false;
	bool iscommit = false;
	bool isglobal = true;

public:

	// Setter functions
	void set(string key, string value);

	void update(string key, string value);

	void unset(string key);

	void setBegin(bool);

	void setCommit(bool);

	void setGlobal(bool);

	// Getter functions

	string get(string key);

	int getCount(string value);

	bool getBegin();

	bool getCommit();

	bool getGlobal();








	// Functionalities

	void begin();

	void commit();

	void rollback();


};

