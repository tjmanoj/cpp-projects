#include "Database.h"
#include <bits/stdc++.h>
using namespace std;

void Database::set(string key, string value) {
	this->transaction[key] = value;
}

void Database::update(string key, string value) {
	if (this->transaction.find(key) == this->transaction.end()) cout << "No variable named " << key << endl;
	else this->transaction[key] = value;
}

void Database::unset(string key) {
	this->transaction.erase(key);
}


string Database::get(string key) {
	if (this->transaction.find(key) == this->transaction.end()) return "null";
	return this->transaction[key];
}


int Database::getCount(string value) {
	int count = 0;
	for (auto i : this->transaction) {
		if (i.second == value) count++;
	}
	return count;
}

void Database::setBegin(bool val) {
	this->isbegin = val;
}

void Database::setCommit(bool val) {
	this->iscommit = val;
}

void Database::setGlobal(bool val) {
	this->isglobal = val;
}

bool Database::getBegin() {
	return this->isbegin;
}

bool Database::getGlobal() {
	return this->isglobal;
}

bool Database::getCommit() {
	return this->iscommit;
}