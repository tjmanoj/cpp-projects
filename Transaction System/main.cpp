
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#include "Database.h"


int main()
{
    vector<Database> db;
    Database d;
    db.push_back(d);
    string choice;
    bool flag = true;

    while (true) {
        getline(cin, choice);

        string input;
        vector<string> inputs;
        istringstream iss(choice);
        while (iss >> input) inputs.push_back(input);
        
     
        if (inputs[0] == "BEGIN" && inputs.size() == 1 && flag) {
            db.pop_back();
            Database t;
            t.setGlobal(false);
            db.push_back(t);
            flag = false;

        }
        flag = false;

        if (choice == "QUIT") break;

        else if (inputs[0] == "SET" && inputs.size() == 3) db.back().set(inputs[1], inputs[2]);

        else if (inputs[0] == "GET" && inputs.size() == 2) {
            if (db.back().get(inputs[1]) == "null") {
                bool isfound = true;
                for (auto i : db) {
                    if (i.getGlobal()) {
                        cout << i.get(inputs[1]) << endl;
                        isfound = false;
                        break;
                    }
                }
                if (isfound) cout << "null" << endl;
            }
            else cout << db.back().get(inputs[1]) << endl;
        }

        else if (inputs[0] == "UNSET" && inputs.size() == 2) db.back().unset(inputs[1]);

        else if (inputs[0] == "UPDATE" && inputs.size() == 3) db.back().update(inputs[1], inputs[2]);


        else if (inputs[0] == "COUNT" && inputs.size() == 2) {
            bool isfound = true;
            if (db.back().getCount(inputs[1]) == 0) {
                for (auto i : db) {
                    if (i.getGlobal()) {
                        cout << i.getCount(inputs[1]) << endl;
                        isfound = false;
                        break;
                    }
                }
                if (isfound) cout << "null" << endl;
            }
            else cout << db.back().getCount(inputs[1]) << endl;
        }

        else if (inputs[0] == "BEGIN" && inputs.size() == 1) {
            Database t;
            t.setGlobal(false);
            db.push_back(t);
        }
        

        else if (inputs[0] == "ROLLBACK" && inputs.size() == 1) db.pop_back();

        else if (inputs[0] == "COMMIT" && inputs.size() == 1) {
            db.pop_back();
        }

        else cout << "Invalid opeation" << endl;

    }

    cout << "THANK YOU!!" << endl;

    return 0;
}

