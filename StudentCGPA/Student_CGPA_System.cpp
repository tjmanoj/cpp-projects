#include <conio.h>
#include <bits/stdc++.h>
#include <fstream>
#include <limits>
#include <sstream>
#include <Windows.h>
#undef max                      // for ignore() function
using namespace std;

class Student {
private:
    string roll_number, name;
    float cgpa;
public:
    Student() :roll_number(""), name(""), cgpa(0.0) {}
    
    void setRollnumber(string roll_number) {
        this->roll_number = roll_number;
    }

    void setName(string name) {
        this->name = name;
    }

    void setCgpa(float cgpa) {
        this->cgpa = cgpa;
    }

    string getRollnumber() {
        return roll_number;
    }

    string getName() {
        return name;
    }

    float getCgpa() {
        return cgpa;
    }

};

void displayOptions() {
    cout << "*******Welcome to Student CGPA report*******" << endl;
    cout << "Options:" << endl;
    cout << "1. Add Student Record" << endl;
    cout << "2. Search Student Record" << endl;
    cout << "3. Display All Records" << endl;
    cout << "4. Update Student Record" << endl;
    cout << "5. Delete Student Record" << endl;
    cout << "6. Exit" << endl;
}

void addStudent(Student s) {
    string name, rollNo;
    float cgpa;

    cout << "Enter Student Roll Number  : ";
    cin >> rollNo;
    s.setRollnumber(rollNo);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Student Name         : ";
    getline(cin, name);
    s.setName(name);

    cout << "Enter Student CGPA         : ";
    cin >> cgpa;
    s.setCgpa(cgpa);

    ofstream out("Student.txt", ios::app);
    if (!out) {
        cout << "Cannot open the file";
    }
    else {
        out << setw(15) << left << s.getRollnumber() << setw(20) <<left << s.getName() << setw(15)<< left << s.getCgpa() << endl;
        out.close();
    }
    cout << "Student Record Added Successfully!!";
    _getch();
}

void displayAll() {
    ifstream in("Student.txt", ios::in);
    if (!in) {
        cout << "File not exitst!" << endl;
    }
    else {
        string line;
        cout << setw(15) << left <<"Roll Number" << setw(20) << left << "Name" << setw(15) << left << "GGPA" << endl;
        while (getline(in, line)) {
            cout << line << endl;
        }
    }
    in.close();
    _getch();
}

void searchStudent() {
    string roll;
    cout << "Enter Student Roll Number: ";
    cin >> roll;
    
    ifstream in("Student.txt", ios::in);
    if (!in) cout << "File not exist!";
    else {
        string line;
        bool found = false;
        while (getline(in, line)) {
            if ((int)line.find(roll) != string::npos) {
                cout << setw(15) << left << "Roll Number" << setw(20) << left << "Name" << setw(15) << left << "GGPA" << endl;
                cout << line;
                found = true;
            }
        }
        in.close();
        if (!found) cout << "Student doesn't found!" << endl;
        _getch();
    }
}


void updateRecord() {
    string roll;
    cout << "Enter Student Roll Number: ";
    cin >> roll;

    ifstream in("Student.txt", ios::in);
    if (!in) cout << "File doesn't exist" << endl;

    ofstream out("temp.txt");
    if (!out) cout << "Files doesn't exist" << endl;
    
    string line;
    bool found = false;
    while (getline(in, line)) {
        int pos = (int)line.find(roll);
        if (pos != string::npos) {
            found = true;
            float newcgpa;
            cout << "Enter new GGPA: ";
            cin >> newcgpa;

            stringstream ss;
            ss << newcgpa;
            string cgpa = ss.str();

            line.replace(35, string::npos, cgpa);
            cout << "Record Updated Successfully!";

        }
        out << line << endl;

    }
    if (!found) cout << "Student not found!" << endl;
    in.close();
    out.close();
    remove("Student.txt");
    rename("temp.txt", "Student.txt");
    _getch();
}

void deleteRecord() {
    string roll;
    cout << "Enter Roll Number: ";
    cin >> roll;

    ifstream in("Student.txt", ios::in);
    if (!in) cout << "File not found!" << endl;

    ofstream out("temp.txt");
    if (!out) cout << "File not found!" << endl;

    string line;
    bool found = false;
    while (getline(in, line)) {
        if (line.find(roll) != string::npos) {
            cout << "Student record deleted successfully!" << endl;
            found = true;
            continue;
        }
        else out << line << endl;
    }
    if (!found) cout << "Student not found!" << endl;
    in.close();
    out.close();
    remove("Student.txt");
    rename("temp.txt", "Student.txt");
    _getch();
}

int main()
{   
    int choice;
    Student s;
    do {
        system("cls");
        displayOptions();
        cout << "Enter your choice: ";
        cin >> choice;
  
        switch (choice) {
        case 1:
            addStudent(s);
            break;

        case 2:
            searchStudent();
            break;

        case 3:
            displayAll();
            break;
           
        case 4:
            updateRecord();
            break;
        
        case 5:
            deleteRecord();
            break;

        case 6:
            cout << "Thank You !!" << endl;
            Sleep(1000);
            exit(0);
        
        default:
            cout << "Please Enter a valid choice!";
            break;
        }
    } while (1);
}

