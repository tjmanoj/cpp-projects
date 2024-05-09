#pragma once
#include <bits/stdc++.h>
#include "Passenger.h"
using namespace std;

#define total_tickets 7
#define total_confirmed_tickets 5
#define total_lower_berths 2
#define total_middle_berths 2
#define total_upper_berths 1
#define total_rac_tickets 1
#define total_waiting_tickets 1

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

	void PrintAvailableTickets();

	void CancelTicket(deque<pair<string, Passenger>>& confirmed_tickets);

	void DecrementTickets(string ticketId);

	void ReorderRackTickets(deque<pair<string, Passenger>>& confirmed_tickets, char &berth);
	void ReorderWaitingTickets(deque<pair<string, Passenger>>& confirmed_tickets, char &berth);

};

