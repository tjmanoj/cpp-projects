#include <bits/stdc++.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

#include "game.h"
#include "history.h"

void displayOptions() {
    cout << "----------Tic Tac Toe Game----------" << endl << endl;
    cout << "Options" << endl;
    cout << "1. Play" << endl;
    cout << "2. History" << endl;
    cout << "3. Quit" << endl;
}

void Start() {
    game g;
    g.getUserDetails();
    g.StartGame();
    _getch();
}

int main()
{
    int choice;
    History h;
    
    do {
        system("cls");
        displayOptions();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            Start();
            break;

        case 2:
            h.DisplayHistory();
            _getch();
            break;

        case 3:
            cout << "Thanks for playing...";
            Sleep(2000);
            exit(0);

        default:
            cout << "Invalid Choice!";
            _getch();
        }
    } while (1);
}

