#include "Customer.h"
#include <bits/stdc++.h>
using namespace std;

#include "Taxi.h"
vector<pair<Customer,Taxi>> BookedDetails;

void Customer::setTaxiNumber(int num) {
	this->taxi_number = num;
}

void Customer::setCustomerId(int id) {
	this->customer_id = id;
}

void Customer::setBookingId(int id) {
	this->booking_id = id;
	this->customer_id = id;
}

void Customer::setFrom(char location) {
	this->from = location;
}

void Customer::setTo(char location) {
	this->to = location;
}

void Customer::setPickUpTime(int time) {
	this->pickup_time = time;
}

void Customer::setDropTime(int time) {
	this->drop_time = time;
}

void Customer::setAmount(float amount) {
	this->amount = amount;
}

//Getter funcitons

int Customer::getTaxiNumber() {
	return this->taxi_number;
}

int Customer::getBookingId() {
	return this->booking_id;
}

int Customer::getCustomerId() {
	return this->customer_id;
}

char Customer::getFrom() {
	return this->from;
}

char Customer::getTo() {
	return this->to;
}

int Customer::getPickUpTime() {
	return this->pickup_time;
}

int Customer::getDropTime() {
	return this->drop_time;
}

float Customer::getAmount() {
	return this->amount;
}

void Customer::AddBookedCustomer(Customer &c,Taxi &t) {
	BookedDetails.push_back({c,t});
	cout << "Taxi can be allotted." << endl;
	cout << "Taxi-" << t.getTaxiNumber() << " is allotted." << endl;
	return;
}

void Customer::PrintDetails() {
	for (auto i : BookedDetails) {
		auto it = i.first;
		cout << it.getCustomerId() << endl;
		cout << it.getTaxiNumber() << endl;
		cout << it.getAmount() << endl;
		cout << "--------------" << endl;
	}
}

