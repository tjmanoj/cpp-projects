#pragma once
#include <bits/stdc++.h>
#include "Passenger.h"
using namespace std;

#define total_tickets 91
#define total_confirmed_tickets 63
#define total_rac_tickets 18
#define total_waiting_tickets 10
#define total_lower_berths 21
#define total_middle_berths 21
#define total_upper_berths 21

class Ticket
{
private:
	int confirmed_tickets, rac_tickets, waiting_tickets, lower_berth_tickets, middle_berth_tickets, upper_berth_tickets,childrenId;

public:
	Ticket() : confirmed_tickets(0), rac_tickets(0), waiting_tickets(0), lower_berth_tickets(0), middle_berth_tickets(0), upper_berth_tickets(0),childrenId(0) {}

	void BookTicket(Passenger &p, deque<pair<string, Passenger>>& confirmed);
	
	void PrintBookedTickets(deque<pair<string, Passenger>> passengers);

	void AllocateTicket(Passenger &p, char &berth);

	bool checkTicketsAvailable();
};

