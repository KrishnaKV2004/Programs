#include <iostream>

using namespace std;

int main()
{
	int num1;
	int num2;
	int i = 1;
	int count1 = 0;
	int count2 = 0;

	cout << "\nEnter Number 1 : ";
	cin >> num1;

	cout << "Enter Number 2 : ";
	cin >> num2;

	while (i<=num1 || i<=num2)
	{
		if (num1%i==0)
		{
			count1++;
		}
		if (num2%i==0)
		{
			count2++;
		}
		i++;
	}

	if (count1==2 && count2==2 && (num2-num1==2 || num1-num2== 2))
	{
		cout << "\nTwin Prime";
	}

	else
	{
		cout << "\nNot Twin Prime";
	}

	return 0;
}
