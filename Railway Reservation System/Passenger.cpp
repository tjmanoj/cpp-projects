#include "Passenger.h"
#include <bits/stdc++.h>
using namespace std;

//Setter functions

void Passenger::setId(int passenger_count) {
    this->id = to_string(passenger_count) + this->berth;
}

void Passenger::setName(string name) {
    this->name = name;
}

void Passenger::setAge(int age) {
    this->age = age;
}

void Passenger::setGender(char gender) {
    this->gender = gender;
}

void Passenger::setBerth(char berth) {
    this->berth = berth;
}


// Getter functions

string Passenger::getId() {
    return this->id;
}

string Passenger::getName() {
    return this->name;
}

int Passenger::getAge() {
    return this->age;
}

char Passenger::getGender() {
    return this->gender;
}

char Passenger::getBerth() {
    return this->berth;
}
