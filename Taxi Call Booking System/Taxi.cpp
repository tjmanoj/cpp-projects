#include <bits/stdc++.h>
#include<conio.h>
using namespace std;

#include "Customer.h"
#include "Taxi.h"



void Taxi::setTaxiNumber(int num) {
	this->taxi_number = num;
}

void Taxi::setLocation(char location) {
	this->current_location = location;
}

void Taxi::setEarning(float amount) {
	this->earning = amount;
}

void Taxi::setJobEndingTime(int time) {
	this->job_ending_time = time;
}
//Getter Functions

int Taxi::getTaxiNumber() {
	return this->taxi_number;
}

char Taxi::getCurrentLocation() {
	return this->current_location;
}

float Taxi::getEarning() {
	return this->earning;
}

int Taxi::getJobEndingTime() {
	return this->job_ending_time;
}


void Taxi::displayTaxiDetails(vector<Taxi> taxis) {
	for (auto k : taxis) {
		cout << k.getTaxiNumber() << ' ' << k.getCurrentLocation() << " " << k.getEarning() << endl;
	}
}

struct ComparePairs {
	bool operator()(const pair<pair<int, float>, Taxi>& a, const pair<pair<int, float>, Taxi>& b) const {
		
		if (a.first.first != b.first.first) {
			return a.first.first > b.first.first;
		}
		else {
			return a.first.second > b.first.second;
		}
	}
};


//void Taxi::displayFiltered(priority_queue<pair<pair<int, int>, Taxi>, vector<pair<pair<int, int>, Taxi>>> filtertedTaxis) {
//	cout << "Possible Taxis" << endl;
//	while (!filtertedTaxis.empty()) {
//		auto i = filtertedTaxis.top().second;
//		filtertedTaxis.pop();
//		cout << i.getTaxiNumber() << ' ' << i.getCurrentLocation() << ' ' << i.getEarning() << endl;
//	}
//}

void Taxi::BookTaxi(vector<Taxi> &taxis) {
	//                      dist, amount, taxi
	priority_queue<pair<pair<int, int>, Taxi>, vector<pair<pair<int, int>, Taxi>>, ComparePairs> filtertedTaxis;
	
	int id;
	int customer_id, pickupTime;
	char from, to;
	float amount;

	cout << "Enter Customer ID	: ";
	cin >> customer_id;

	cout << "Enter Pickup Point	: ";
	cin >> from;

	cout << "Enter Drop Point	: ";
	cin >> to;

	cout << "Enter Pickup Time	: ";
	cin >> pickupTime;


	for (int i = 0; i<taxis.size(); i++) {
		int distance = abs(taxis[i].getCurrentLocation() - from);
		cout << "Distance" << distance << endl;
		cout << "Amount" << taxis[i].getEarning();
		if (taxis[i].getJobEndingTime() + distance <= pickupTime) {

			filtertedTaxis.push({ {distance,taxis[i].getEarning()},taxis[i]});
		}
	}
		if (filtertedTaxis.size() == 0) {
			cout << "No Taxi Available!" << endl;
			return;
		}


		id = filtertedTaxis.top().second.taxi_number - 1;
		Customer c;
		c.setTaxiNumber(taxis[id].getTaxiNumber());
		c.setCustomerId(customer_id);
		c.setBookingId(customer_id);
		c.setFrom(from);
		c.setTo(to);
		c.setPickUpTime(pickupTime);

		//drop time calculation
		int droptime = pickupTime + abs(to - from);
		c.setDropTime(droptime);

		//Amount calculation
		int travel_distance = abs(to - from);
		amount = ((travel_distance - 5) * 10) + 100.0;
		c.setAmount(amount);

		//Taxi Amount updation
		taxis[id].setEarning(taxis[id].getEarning() + amount);

		//Taxi Current Location Updation
		taxis[id].setLocation(to);
		taxis[id].setJobEndingTime(droptime);

		c.AddBookedCustomer(c, taxis[id]);


		cout << "Possible Taxis" << endl;
		while (!filtertedTaxis.empty()) {
			auto i = filtertedTaxis.top().second;
			filtertedTaxis.pop();
			cout << i.getTaxiNumber() << ' ' << i.getCurrentLocation() << ' ' << i.getEarning() << endl;
		}

}

