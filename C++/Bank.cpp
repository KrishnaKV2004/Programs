#include <iostream>
#include <string>

using namespace std;

class Bank {
private:
    string name;
    string add;

public:
    int amn;
    int acc_v;
    int acc = 1001;
    double bal = 0;

    void info() {
        cin.ignore();
        cout << "\nEnter Name : ";
        getline(cin, name);
        cout << "Enter Address : ";
        getline(cin, add);
    }

    void ch_add() {
        cin.ignore();
        cout << "\nEnter New Address : ";
        getline(cin, add);
    }

    void check() {
        cout << "\nBalance --> " << bal;
    }

    void depo() {
        cout << "\nEnter Amount To Deposit : ";
        cin >> amn;

        bal = bal + amn;

        cout << "New Balance --> " << bal;
    }

    void wdr() {
        cout << "\nEnter Amount To Withdraw : ";
        cin >> amn;

        if (amn <= bal) {
            bal = bal - amn;
            cout << "New Balance --> " << bal;
        } else {
            cout << "Insufficient balance for withdrawal.";
        }
    }

    void show() {
        cout << "\nName : " << name;
        cout << "\nAddress : " << add;
        cout << "\nAcc Number : " << acc;
        cout << "\nBalance : Rs " << bal;
    }
};

int main() {
    int n = 0;
    char choice, con;
    const int MAX = 10;
    Bank dep[MAX];

    while (true) {
        cout << "\nWelcome To HDFC Bank !\n";
        cout << "\nEnter [A] To Add Account";
        cout << "\nEnter [C] To Change Address";
        cout << "\nEnter [B] To Check Balance";
        cout << "\nEnter [D] To Deposit Money";
        cout << "\nEnter [W] To Withdraw Money";
        cout << "\nEnter [S] To Show Information";
        cout << "\n\nEnter Your Choice : ";
        cin >> choice;

        switch (choice) {
            case 'A':
            case 'a':
                dep[n].info();
                cout << "\nAccount Number --> " << dep[n].acc;
                dep[n].acc++;
                n++;
                break;

            case 'C':
            case 'c':
                int acc_v;
                cout << "\nEnter Account Number : ";
                cin >> acc_v;
                if (acc_v >= 1001 && acc_v <= 1000 + n) {
                    dep[acc_v - 1001].ch_add();
                } else {
                    cout << "\nInvalid Account Number.";
                }
                break;

            case 'B':
            case 'b':
                cout << "\nEnter Account Number : ";
                cin >> acc_v;
                if (acc_v >= 1001 && acc_v <= 1000 + n) {
                    dep[acc_v - 1001].check();
                } else {
                    cout << "\nInvalid Account Number.";
                }
                break;

            case 'D':
            case 'd':
                cout << "\nEnter Account Number : ";
                cin >> acc_v;
                if (acc_v >= 1001 && acc_v <= 1000 + n) {
                    dep[acc_v - 1001].depo();
                } else {
                    cout << "\nInvalid Account Number.";
                }
                break;

            case 'W':
            case 'w':
                cout << "\nEnter Account Number : ";
                cin >> acc_v;
                if (acc_v >= 1001 && acc_v <= 1000 + n) {
                    dep[acc_v - 1001].wdr();
                } else {
                    cout << "\nInvalid Account Number.";
                }
                break;

            case 'S':
            case 's':
                cout << "\nEnter Account Number : ";
                cin >> acc_v;
                if (acc_v >= 1001 && acc_v <= 1000 + n) {
                    dep[acc_v - 1001].show();
                } else {
                    cout << "\nInvalid Account Number.";
                }
                break;

            default:
                cout << "\nInvalid Input !";
                break;
        }

        cout << "\n\nDo You Want To Continue ? [Y/N] : ";
        cin >> con;

        if (con != 'y' && con != 'Y') {
            break;
        }
    }

    return 0;
}