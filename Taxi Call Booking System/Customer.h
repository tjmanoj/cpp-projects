#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "Taxi.h"

class Customer
{
private:
	int taxi_number;
	int customer_id;
	int booking_id;
	char from;
	char to;
	int pickup_time;
	int drop_time;
	float amount;

public:

	// Setter functions

	void setTaxiNumber(int num);

	void setCustomerId(int id);

	void setBookingId(int id);

	void setFrom(char location);

	void setTo(char location);

	void setPickUpTime(int time);

	void setDropTime(int time);

	void setAmount(float amount);

	//Getter funcitons

	int getTaxiNumber();

	int getBookingId();

	int getCustomerId();

	char getFrom();

	char getTo();

	int getPickUpTime();

	int getDropTime();

	float getAmount();

	void AddBookedCustomer(Customer &c, Taxi &t);

	void PrintDetails();


};

