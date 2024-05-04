#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

#include "Ticket.h"
#include "Passenger.h"

bool Ticket::checkTicketsAvailable() {
    int total = this->confirmed_tickets + this->lower_berth_tickets + this->middle_berth_tickets + this->upper_berth_tickets + this->rac_tickets + this->waiting_tickets;

    if (total < total_tickets) return true;
    return false;
}

void Ticket::BookTicket(Passenger &p, deque<pair<string, Passenger>>& confirmed_tickets) {
    string name, hasChildren;
    int age;
    char gender, berth;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Name                         : " ;
    getline(cin, name);
    p.setName(name);

    cout << "Enter Age                          : ";
    cin >> age;
    p.setAge(age);

    cout << "Enter Gender (M/F)                 : ";
    cin >> gender;
    p.setGender(gender);

    if (gender == 'F' && age > 18) {
    cout << "Do you have children? (Yes/No)     : ";
        cin >> hasChildren;
    }



    //Berth
    cout << "Enter Berth (L/M/U)                : ";
    cin >> berth;
    
    if (!checkTicketsAvailable()) {
        cout << "No Tickets Available" << endl;
        return;
    }

    if (age < 5) {
        p.setBerth('C');
        p.setId(++this->childrenId);
        p.setBerth(berth);
        confirmed_tickets.push_back({ p.getId(),p });
        return;
    }

    if (age > 60 || gender == 'F' && hasChildren == "Yes") {        // checking condition to allocate lower berths
        if (this->lower_berth_tickets < total_lower_berths) {       // checking if lower berths available
            p.setBerth('L');
            this->lower_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->lower_berth_tickets);
        }
        else {
            AllocateTicket(p, berth);
        }
    }

    else {
        AllocateTicket(p, berth);
    }
    
    confirmed_tickets.push_back({ p.getId(),p });
    _getch();
}


void Ticket::PrintBookedTickets(deque<pair<string, Passenger>> passengers) {
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

    cout << "Lower Berths Tickets       : " << this->lower_berth_tickets << endl;
    cout << "Middle Berths Tickets      : " << this->middle_berth_tickets << endl;
    cout << "Upper Berths Tickets       : " << this->upper_berth_tickets << endl;
    cout << "RAC Tickets                : " << this->rac_tickets << endl;
    cout << "Waiting List Tickets       : " << this->waiting_tickets << endl;
    cout << "Total confirmed Tickets    : " << this->confirmed_tickets << endl;
    _getch();
}


void Ticket::AllocateTicket(Passenger &p, char &berth) {
   
    if (berth == 'L') {
        if (this->lower_berth_tickets < total_lower_berths) {
            p.setBerth(berth);
            this->lower_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->lower_berth_tickets);
        }

        else if (this->middle_berth_tickets < total_middle_berths) {
            p.setBerth('M');
            this->middle_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->middle_berth_tickets);
        }

        else if (this->upper_berth_tickets < total_upper_berths) {
            p.setBerth('U');
            this->upper_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->upper_berth_tickets);
        }

        else if (this->rac_tickets < total_rac_tickets) {
            p.setBerth('R');
            this->rac_tickets++;
            p.setId(this->rac_tickets);
        }

        else {
            p.setBerth('W');
            this->waiting_tickets++;
            p.setId(this->waiting_tickets);
        }
        
    }
    else if (berth == 'M') {
        if (this->middle_berth_tickets < total_middle_berths) {
            p.setBerth(berth);
            this->middle_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->middle_berth_tickets);
        }

        else if (this->lower_berth_tickets < total_lower_berths) {
            p.setBerth(berth);
            this->lower_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->lower_berth_tickets);
        }

        else if (this->upper_berth_tickets < total_upper_berths) {
            p.setBerth('U');
            this->upper_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->upper_berth_tickets);
        }

        else if (this->rac_tickets < total_rac_tickets) {
            p.setBerth('R');
            this->rac_tickets++;
            p.setId(this->rac_tickets);
        }

        else {
            p.setBerth('W');
            this->waiting_tickets++;
            p.setId(this->waiting_tickets);
        }
    }

    else {
        if (this->upper_berth_tickets < total_upper_berths) {
            p.setBerth(berth);
            this->upper_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->upper_berth_tickets);
        }

        else if (this->lower_berth_tickets < total_lower_berths) {
            p.setBerth(berth);
            this->lower_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->lower_berth_tickets);
        }

        else if (this->middle_berth_tickets < total_middle_berths) {
            p.setBerth('M');
            this->middle_berth_tickets++;
            this->confirmed_tickets++;
            p.setId(this->middle_berth_tickets);
        }

        else if (this->rac_tickets < total_rac_tickets) {
            p.setBerth('R');
            this->rac_tickets++;
            p.setId(this->rac_tickets);
        }

        else {
            p.setBerth('W');
            this->waiting_tickets++;
            p.setId(this->waiting_tickets);
        }
    }

};