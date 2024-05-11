#pragma once
#include <bits/stdc++.h>
#define total_taxis 4

#include "Taxi.h"

class Taxi
{
private:
	int taxi_number;
	char current_location;
	float earning;
	int job_ending_time;

public:
	Taxi() :taxi_number(0),current_location('A'), earning(0.0),job_ending_time(0) {}

	//Setter functions
	
	void setTaxiNumber(int num);

	void setLocation(char location);

	void setEarning(float amount);
	
	void setJobEndingTime(int time);
	//Getter Functions

	int getTaxiNumber();

	char getCurrentLocation();

	float getEarning();

	int getJobEndingTime();

	// Functionalities
	void BookTaxi(vector<Taxi> &taxis);

	void displayTaxiDetails(vector<Taxi> taxis);



};

