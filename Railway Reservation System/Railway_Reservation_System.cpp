#include <bits/stdc++.h>
#include <conio.h>
#include <Windows.h>
using namespace std;
#undef max

#include "Passenger.h"
#include "Ticket.h"


void displayOptions() {
    cout << "*******Welcome to Railway Reservation System*******" << endl;
    cout << "Options:" << endl;
    cout << "1.Book" << endl;
    cout << "2.Cancel" << endl;
    cout << "3.Print Booked Tickets" << endl;
    cout << "4.Print Available Tickets" << endl;
    cout << "5.Exit" << endl;
}

int main()
{
    deque < pair<string, Passenger>> confirmed_tickets;
    Ticket t;
      
    int choice;
    Passenger p;
    do {
        system("cls");
        displayOptions();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            t.BookTicket(p, confirmed_tickets);
            break;

        case 3:
            t.PrintBookedTickets(confirmed_tickets);
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

