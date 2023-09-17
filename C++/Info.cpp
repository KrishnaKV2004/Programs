#include <iostream>
#include <random>

using namespace std;

class person
{
    private :

        string name;
        int age;
        int height;
        double weight;
        string add;
        string dob;
        string email;
        int phone[10];

    public :

        void details()
        {
            cout << "Name : ";
        }

};

int main()
{
    person per;
    char con_choice;

    cout << "\n#----- Temporary Details Generator -----#\n";
    cout << "\nChoose Country / Region -->\n";
    cout << "\n[A] Asia";
    cout << "\n[E] Europe";
    cout << "\n[N] North America";
    cout << "\n\nYour Input --> ";
    cin >> con_choice;

    switch (con_choice)
    {
        case 'A' :
        case 'a' :
            cout << "\n#----- Asian -----#\n";
            cout << "\nName : " << per.name;
            cout << "\nAge : " << per.age;
            break;
    
        default:
            break;
    }

    return 0;
}