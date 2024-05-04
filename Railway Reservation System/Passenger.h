#pragma once
#include <bits/stdc++.h>
using namespace std;

class Passenger
{
private:
    string id;
    string name;
    int age;
    char gender;
    char berth;

public:
    Passenger() : id(""), name(""), age(0), gender(' '), berth(' ') {}
    //Setter functions

    void setId(int passenger_count);

    void setName(string name);

    void setAge(int age);

    void setGender(char gender);

    void setBerth(char berth);


    // Getter functions

    string getId();

    string getName();

    int getAge();

    char getGender();

    char getBerth();
};

