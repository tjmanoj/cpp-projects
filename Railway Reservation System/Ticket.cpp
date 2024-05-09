#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

#include "Ticket.h"
#include "Passenger.h"

bool Ticket::checkTicketsAvailable() {
    int total = this->lower_berth_tickets + this->middle_berth_tickets + this->upper_berth_tickets + this->rac_tickets + this->waiting_tickets;

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
    
    if (age < 5) {
        p.setBerth('C');
        p.setId(++this->childrenId);
        p.setBerth(berth);
        cout << "Ticked Booked Successfully!" << endl;
        confirmed_tickets.push_back({ p.getId(),p });
        _getch();
        return;
    }

    if (!checkTicketsAvailable()) {
        cout << "No Tickets Available" << endl;
        _getch();
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
    
    cout << "Ticked Booked Successfully!" << endl;
    confirmed_tickets.push_back({ p.getId(),p });
    _getch();
}


void Ticket::PrintBookedTickets(deque<pair<string, Passenger>> passengers) {
    while (!passengers.empty()) {
        auto it = passengers.front();
        Passenger p1 = it.second;

        cout << setw(10) << left << "Name       : " << p1.getName() << endl;
        cout << setw(10) << left << "Ticket Id  : " << p1.getId() << endl;
        cout << setw(10) << left << "Age        : " << p1.getAge() << endl;
        cout << setw(10) << left << "Gender     : " << p1.getGender() << endl;
        cout << setw(10) << left << "Berth      : " << p1.getBerth() << endl;

        passengers.pop_front();
        cout << "---------------------------" << endl;
    }

    cout << "Total Booked Tickets: " << this->confirmed_tickets + this->waiting_tickets + this->rac_tickets << endl;

    
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
            p.setBerth('L');
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
            p.setBerth('L');
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

void Ticket::PrintAvailableTickets() {
    cout << "----Available Tickets------" << endl;
    cout << "Lower Berths Tickets       : " << total_lower_berths - this->lower_berth_tickets << endl;
    cout << "Middle Berths Tickets      : " << total_middle_berths - this->middle_berth_tickets << endl;
    cout << "Upper Berths Tickets       : " << total_upper_berths - this->upper_berth_tickets << endl;
    cout << "RAC Tickets                : " << total_rac_tickets - this->rac_tickets << endl;
    cout << "Waiting List Tickets       : " << total_waiting_tickets - this->waiting_tickets << endl;
    _getch();
}


void Ticket::CancelTicket(deque<pair<string, Passenger>>& confirmed_tickets) {
    string id;
    bool found = false;
    cout << "Enter Ticket Id: ";
    cin >> id;
    char berth;
    auto it = confirmed_tickets.begin();
    while (it != confirmed_tickets.end()) {
        if (it->first == id) {
            found = true;
            berth = it->first[1];
            DecrementTickets(it->first);
            confirmed_tickets.erase(it);
            cout << "Ticket Cancelled Successfully!" << endl;
            break;
        }
        it++;
    }
    if (!found) cout << "Ticket Not Found!" << endl;
    if (this->rac_tickets > 0) ReorderRackTickets(confirmed_tickets, berth);
    if (this->waiting_tickets > 0 && this->rac_tickets < total_rac_tickets) ReorderWaitingTickets(confirmed_tickets, berth);
    _getch();
}

void Ticket::DecrementTickets(string ticketId) {
    if (ticketId[1] == 'L') {
        this->lower_berth_tickets -= 1;
        this->confirmed_tickets -= 1;
    }
    else if (ticketId[1] == 'M') {
        this->middle_berth_tickets -= 1;
        this->confirmed_tickets -= 1;
    }
    else if (ticketId[1] == 'U') {
        this->upper_berth_tickets -= 1;
        this->confirmed_tickets -= 1;
    }
    else if (ticketId[1] == 'R') {
        this->rac_tickets -= 1;
    }
    else if (ticketId[1] == 'W') {
        this->waiting_tickets -= 1;
    }
}

void Ticket::ReorderRackTickets(deque<pair<string, Passenger>>& confirmed_tickets, char &berth) {
        
    Passenger temp,p1;
    auto it = confirmed_tickets.begin();
    while (it != confirmed_tickets.end()) {
        if (it->first[1] == 'R') {
            temp = it->second;
            confirmed_tickets.erase(it);
            this->rac_tickets--;
            break;
        }
        it++;
    }
    
    p1.setName(temp.getName());
    p1.setAge(temp.getAge());
    p1.setGender(temp.getGender());
    p1.setBerth(berth);

    // To get the proper id according to the berth
    if (berth == 'L') p1.setId(++this->lower_berth_tickets);
    else if (berth == 'M') p1.setId(++this->middle_berth_tickets);
    else p1.setId(++this->upper_berth_tickets);

    confirmed_tickets.push_back({ p1.getId(),p1 });
    this->confirmed_tickets++;
}

void Ticket::ReorderWaitingTickets(deque<pair<string, Passenger>>& confirmed_tickets, char& berth) {
    Passenger temp, p1;
    auto it = confirmed_tickets.begin();
    while (it != confirmed_tickets.end()) {
        if (it->first[1] == 'W') {
            temp = it->second;
            confirmed_tickets.erase(it);
            this->waiting_tickets--;
            break;
        }
        it++;
    }

    p1.setName(temp.getName());
    p1.setAge(temp.getAge());
    p1.setGender(temp.getGender());
    p1.setBerth('R');
    p1.setId(++this->rac_tickets);

    confirmed_tickets.push_back({ p1.getId(),p1 });
}
