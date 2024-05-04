#include <bits/stdc++.h>
#include <conio.h>
#include <Windows.h>
#include "Passenger.h"
using namespace std;

#undef max

#define total_confirmed_tickets 63
#define total_rac_tickets 18
#define total_waiting_tickets 10
#define total_lower_berths 21
#define total_middle_berths 21
#define total_upper_berths 21



void displayOptions() {
    cout << "*******Welcome to Railway Reservation System*******" << endl;
    cout << "Options:" << endl;
    cout << "1.Book" << endl;
    cout << "2.Cancel" << endl;
    cout << "3.Print Booked Tickets" << endl;
    cout << "4.Print Available Tickets" << endl;
    cout << "5.Exit" << endl;
}


void BookTicket(Passenger p, deque<pair<string, Passenger>> &confirmed, int passenger_count) {
    string name;
    int age;
    char gender, berth;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << setw(15) << left << "Enter Name: ";
    getline(cin,name);
    p.setName(name);

    cout << setw(15) << left << "Enter Age: ";
    cin >> age;
    p.setAge(age);

    cout << setw(15) << left << "Enter Gender (M/F): ";
    cin >> gender;
    p.setGender(gender);
    
    cout << setw(15) << left << "Enter Berth (L/M/U): ";
    cin >> berth;
    p.setBerth(berth);

    p.setId(passenger_count);

    confirmed.push_back({ p.getId(),p });
    _getch();
}


void PrintBookedTickets(deque<pair<string,Passenger>> passengers) {
    while (!passengers.empty()) {
        auto it = passengers.front();
        Passenger p1 = it.second;

        cout << setw(10) << left << "Name   : " << p1.getName() << endl;
        cout << setw(10) << left << "Id     : " << p1.getId() << endl;
        cout << setw(10) << left << "Age    : " << p1.getAge() << endl;
        cout << setw(10) << left << "Gender : " << p1.getGender() << endl;
        cout << setw(10) << left << "Berth  : " << p1.getBerth() << endl;

        passengers.pop_front();
        cout << "-----------------------------------------" << endl;
    }
    _getch();
}
int main()
{
    deque < pair<string, Passenger>> confirmed;
    int passenger_count = 0;
      
    int choice;
    Passenger p;
    do {
        system("cls");
        displayOptions();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            BookTicket(p,confirmed, ++passenger_count);
            break;

        case 3:
            PrintBookedTickets(confirmed);
            break;

        case 5:
            cout << "Thank You !!" << endl;
            Sleep(1000);
            exit(0);

        default:
            cout << "Enter valid choice!" << endl;
            break;
        }
        

    } while (1);
}

