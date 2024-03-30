#include<conio.h>
#include<bits/stdc++.h>
using namespace std;

// Functionalities
// 1. Check Balance
// 2. Cash Withdraw
// 3. Show user details
// 4. Update mobile number
// 5. Exit 


class Atm {
private:
    long long account_no;
    string name;
    string mobile_no;
    double balance;
    int PIN;

public:
    void setData(long long accountNo, string Name, string number, double Balance, int pin){
        account_no = accountNo;
        name = Name;
        mobile_no = number;
        balance = Balance;
        PIN = pin;
    }


    long long getAccountNo(){
        return account_no;
    }

    string getName(){
        return name;
    }
    
    string getMobile(){
        return mobile_no;
    }

    double getBalance(){
        return balance;
    }

    int getPin(){
        return PIN;
    }

    void WithdrowCash(long long cash){
        if(cash <= balance && (balance-cash >= 0)){
            balance -= cash;
            cout << "Available Balance = " << balance << endl;
            _getch();
        }
        else{
            cout << "Insufficient Balance!!" <<endl;
            _getch();
        }
    }

    void UpdateNumber(string oldNum, string newNum){
        if(oldNum == mobile_no){
            mobile_no = newNum;
            cout << "Successfully Updated!" <<endl;
            _getch();
        }
        else{
            cout << "Invalid Old number!" <<endl;
            _getch();
        }
    }
};


int main(){
    Atm user1;
    user1.setData(123456, "Manoj", "79654", 500,8634);
    cout << user1.getBalance();
    long long acc_no;
    int pin_no;

    do{
        system("cls");
        cout << "****Welcome to Tj ATM ****" <<endl;
        cout << "Enter account Number   : " ;
        cin >> acc_no;
        cout << "Enter your PIN         : ";
        cin >> pin_no;
        

        if(acc_no == user1.getAccountNo() && pin_no == user1.getPin()){
            
            int choice;
            long long amt;
            string old_num, new_num;
            do{
                system("cls");
                cout << "****Welcome to Tj ATM ****" <<endl;
                cout << "Select Options" << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Cash Withdraw" << endl;
                cout << "3. Show user details" << endl;
                cout << "4. Update mobile number" << endl;
                cout << "5. Exit" << endl;

                cin >> choice;

                switch(choice){
                    case 1:
                        cout << "Available Balance :"<< user1.getBalance() << endl;
                        _getch();
                    break;
                    
                    case 2:
                        cout << "Enter amount : ";
                        cin >> amt;
                        user1.WithdrowCash(amt);
                        break;

                    case 3:
                        cout << "------------Details-------------" << endl;
                        cout << "Name           : " << user1.getName() <<endl;
                        cout << "Account Number : " << user1.getAccountNo() <<endl;
                        cout << "Mobile Number  : " << user1.getMobile() <<endl;
                        cout << "Balance        : " << user1.getBalance() <<endl;

                        _getch();
                        break;
                    
                    case 4:
                        cout << "Enter old number: ";
                        cin >> old_num;
                        cout << "Enter new number: ";
                        cin >> new_num;
                        user1.UpdateNumber(old_num, new_num);
                        break;

                    case 5:
                        cout << "Happy Journey" <<endl;
                        exit(0);

                    default:
                        cout<< "Invalid choice" << endl;
                        _getch();
                }



            }while(1);
        }
        else{
            cout << "Invalid User Details!!" << endl;
            _getch();
        }

    }while(1);


    return 0;
}