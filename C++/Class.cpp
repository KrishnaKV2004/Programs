/*
    Class -->

    A class is a user-defined data type that represents a blueprint for creating objects.
    It defines the attributes (data members) and behaviors (member functions) that the objects of that class will possess.
*/
//  Syntax -->
/*
    class classname
    {
        private :
        data members
        function members

        protected :
        data members
        function members

        public :
        data members
        function members
    };
*/
/*  
    Members -->

    Instance Members
    Static Members
*/
/*
    Object -->

    An object is an instance of a class. It’s a concrete representation of a particular entity or concept.
*/
//  Program To Calculate Tax -->

#include <iostream>

using namespace std;
class Tax_calc
{
    private:

        string name;
        int empcode;
        double tax;

    public :

        double income;
        
        void info()
        {
            cout << "\nEnter Name : ";
            cin >> name;

            cout << "Enter Employee Code : ";
            cin >> empcode;

            cout << "Enter Income : ";
            cin >> income;
        }

        void calctax()
        {
            if (income>=500000)
            {
                tax = (income*0.05);
            }
            else
            {
                tax = 0.0;
            }
        }

        void showInfo()
        {
            cout << "\nName = " << name << endl;
            cout << "Employee Code = " << empcode << endl;
            cout << "Income = " << income << endl;
            cout << "Tax = " << tax << endl;
        }
};

int main()
{
    int i, n;
    Tax_calc obj[10];

    cout << "\nNumber Of Employees ? : ";
    cin >> n;

    for (i=0; i<n; i++)
    {
        obj[i].info();
        obj[i].calctax();
    }

    cout << "\nTax Payers -->\n";

    for (i=0; i<n; i++)
    {
        if (obj[i].income>=500000)
        {
            obj[i].showInfo();
        }
    }

    cout << "\nNot Paying Tax -->\n";

    for (i=0; i<n; i++)
    {
        if (obj[i].income<=500000)
        {
            obj[i].showInfo();
        }
    }

    return 0;
}