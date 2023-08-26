#include <iostream>
using namespace std;

int fac(int);

int main()
{
	int num,fact;

	cout << "\nEnter Number : ";
	cin >> num;

	fact = fac(num);

	cout << "\nFactorial of " << num << " is " << fact;

	return 0;
}

int fac(int n)
{
	int fact;

	if (n==0 || n==1)
	{
		return 1;
	}

	fact = fact * fac(n-1);

	return fact;
}
