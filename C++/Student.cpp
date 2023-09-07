#include <iostream>

using namespace std;
class student
{
    private :

        string name;
        string course;
        int roll;
        double sub1;
        double sub2;
        double sub3;
        char grade;

    public :

        double perc;

        void info()
        {
            cin.ignore();

            cout << "\nStudent Name : ";
            getline(cin, name);
            cout << "Course : ";
            getline(cin, course);

            cout << "Roll Number : ";
            cin >> roll;
            cout << "Marks In Logic Design : ";
            cin >> sub1;
            cout << "Marks In Data Structures : ";
            cin >> sub2;
            cout << "Marks In Machine Learning : ";
            cin >> sub3;
        }

        void grade_calc()
        {
            perc = ((sub1+sub2+sub3)/300)*100;

            if (perc>=90)
            {
                grade = 'A';
            }
            else if (perc>=80)
            {
                grade = 'B';
            }
            else if (perc>=60)
            {
                grade = 'C';
            }
            else if (perc>=40)
            {
                grade = 'D';
            }
            else
            {
                grade = 'F';
            }
        }

        void show()
        {
            cout << "\nName : " << name;
            cout << "\nCourse : " << course;
            cout << "\nRoll Number : " << roll;
            cout << "\nMarks In Logic Design : " << sub1;
            cout << "\nMarks In Data Structures : " << sub2;
            cout << "\nMarks In Machine Learning : " << sub3;
            cout << "\nPercentage : " << perc;
            cout << "\nGrade : " << grade;
            cout << endl;
        }
};

int main()
{
    int i,n;
    const int MAX = 10;
    student std[MAX];

    cout << "\nNumber Of Students ? : ";
    cin >> n;

    for (i=0; i<n; i++)
    {
        std[i].info();
        std[i].grade_calc();
    }

    for (i=0; i<n; i++)
    {
        std[i].show();
    }

    return 0;
}