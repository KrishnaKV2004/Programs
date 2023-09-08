#include <iostream>

using namespace std;
class Bank
{
    private :

        string name;
        string add;

    public :

        int amn;
        int acc_v;
        int acc = 1001;
        double bal = 0 ;

        void info()
        {
            cin.ignore();
            cout << "\nEnter Name : ";
            getline(cin, name);
            cout << "Enter Address : ";
            getline(cin, add);
        }

        void ch_add()
        {

        }

        void check()
        {
            cout << "\nBalance --> " << bal;
        }

        void depo()
        {
            cout << "\nEnter Account Number : ";
            cin >> acc_v;
            cout << "\nEnter Amount To Deposit : ";
            cin >> amn;

            depo[acc_v-1000].bal = depo[acc_v-1000].bal + amn;
            bal = bal + amn;

            cout << "New Balance --> " << bal;
        }

        void wdr()
        {
            cout << "\nEnter Amount To Withdraw : ";
            cin >> amn;

            bal = bal - amn;
            cout << "New Balance --> " << bal;
        }

        void show()
        {
            cout << "\nName : " << name;
            cout << "\nAddress : " << add;
            cout << "\nAcc Number : " << acc;
            cout << "\nBalance : Rs " << bal;          
        }
};

int main()
{
    int i=0, n=0, acc_v;
    char choice, con;
    const int MAX = 10;
    Bank dep[MAX];

    menu :

        cout << "\nWelcome To HDFC Bank !\n";
        cout << "\nEnter [A] To Add Account";
        cout << "\nEnter [C] To Change Address";
        cout << "\nEnter [B] To Check Balance";
        cout << "\nEnter [D] To Deposit Money";
        cout << "\nEnter [W] To Withdraw Money";
        cout << "\n\nEnter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
            case 'A':
            case 'a':
                dep[n].info();
                cout << "\nAccount Number --> " << dep[n].acc;
                n++;
                dep[n].acc++;
                break;

            case 'C':
            case 'c':
                dep[i].ch_add();
                break;

            case 'B':
            case 'b':
                cout << "\nEnter Account Number : ";
                cin >> acc_v;
                dep[i].check();
                break;

            case 'D':
            case 'd':
                dep[i].depo();
                break;

            case 'W':
            case 'w':
                dep[i].wdr();
                break;

            default:
                cout << "\nInvalid Input !";
                goto menu;
        }

        cout << "\n\nDo You Want To Continue ? [Y/N] : ";
        cin >> con;

        if (con=='y' || con=='Y')
        {
            goto menu;
        }

    return 0;
}