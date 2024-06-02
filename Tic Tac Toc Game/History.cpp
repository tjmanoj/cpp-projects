#include "History.h"
#pragma warning(disable : 4996)				// to use the time
#include <bits/stdc++.h>
#include <conio.h>
#include <ctime>
using namespace std;

void History::setuser1(string name) {
	this->user1 = name;
}

void History::setuser2(string name) {
	this->user2 = name;
}

void History::setWinner(string name) {
	this->winner = name;
}

void History::setTime() {
	time_t now = time(0);
	char* date = ctime(&now);
	this->Time = date;
}

void History::setMode(int mode) {
	string s = "";
	s += (mode + '0');
	s += "x";
	s += (mode + '0');
	this->mode = s;
}


string History::getuser1() {
	return this->user1;
}

string History::getuser2() {
	return this->user2;
}

string History::getWinner() {
	return this->winner;
}

string History::getTime() {
	return this->Time;
}

string History::getMode() {
	return this->mode;
}

void History::getPlayerDetails(History &p) {
	string user1, user2;
	cout << "Player 1 Name: ";
	cin >> user1;
	p.setuser1(user1);


	cout << "Player 2 Name: ";
	cin >> user2;
	p.setuser2(user2);


	p.setTime();

}

void History::SaveDetails(History &p) {
	ofstream out("Game.txt", ios::app);
	if (!out) "Cannot open file";
	else {
		out << setw(20) << left << p.getuser1() << setw(20) << left << p.getuser2() << setw(10) << left << p.getMode() << setw(15) << left << p.getWinner() << p.getTime() ;
	}

	out.close();
}

void History::DisplayHistory() {
	ifstream in("Game.txt", ios::in);
	if (!in) cout << "File not exist!" << endl;
	else {
		string line;
		cout << setw(20) << left << "Player 1" << setw(20) << left << "Player 2" << setw(10) << left << "Mode" << setw(15) << left << "Winner" << "Played Time" << endl;
		while (getline(in, line)) {
			cout << line << endl;
		}
	}
	in.close();
}