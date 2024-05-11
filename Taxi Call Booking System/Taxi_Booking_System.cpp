#include<bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
#undef max

#include "Taxi.h"
#include "Customer.h"

void displayOptions() {
    cout << "*******Welcome to Call Taxi Booking*******" << endl << endl;
    cout << "Options:" << endl;
    cout << "1.Book a Taxi" << endl;
    cout << "2.Display Taxi Details" << endl;
    cout << "3.Exit" << endl;
}

void generateTaxis(vector<Taxi> &taxis) {
    for (int i = 1; i <= total_taxis; i++) {
        Taxi taxi;
        taxi.setTaxiNumber(i);
        taxis.push_back(taxi);
    }
}

int main()
{
    vector<Taxi> taxis;
    Taxi t;
    Customer c;
    generateTaxis(taxis);

    

    int choice;
    do {
        system("cls");
        displayOptions();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            t.BookTaxi(taxis);
            _getch();
            break; 

        case 2:
            cout << "Printing Details" << endl;
            t.displayTaxiDetails(taxis);
            c.PrintDetails();
            _getch();
            break;
        
        case 3:
            cout << "Thank You !!" << endl;
            Sleep(1000);
            exit(0);

        default:
            cout << "Enter valid choice!" << endl;
            _getch();
            break;
        }

    } while (1);
}
