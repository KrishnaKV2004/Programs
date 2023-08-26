#include <iostream>

using namespace std;

void comp(int);
void smd(int);

int main()
{
	int num,ch;

    cout << "\nEnter Number : ";
    cin >> num;

    cout << "\nEnter [1] To Check If Number Is Composite";
    cout << "\nEnter [2] To Find Smallest Digit Of Integer";
    cout << "\n\nEnter Choice : ";
    cin >> ch;

    switch (ch)
    {
    case 1:
        comp(num);
        break;

    case 2:
        smd(num);
        break;
    
    default:
        cout << "Invalid Choice";
        break;
    }

	return 0;
}

void comp(int num)
{
    int i = 1;
	int count = 0;

	while (i<num)
	{
		if (num%i==0)
		{
			count++;
		}
		
		i++;
	}

	if (count!=1)
	{
		cout << "\nComposite Number";
	}

	else
	{
		cout << "\nNot A Composite Number";
	}
}

void smd(int num)
{
    int ld;
    int small = num % 10;

    while(num>9)
    {
        num = num / 10;
        ld = num % 10;
        
        if (ld<small)
        {
            small = ld;
        }
    }

    cout << "\nSmallest Digit = " << small;
}