#include <iostream>

using namespace std;

int main()
{
    int num,ld,copy;
    int sum=0,prd=1;

    cout << "\nEnter Number : ";
    cin >> num;

    copy = num;

    while(copy>0)
    {
        ld = copy % 10;
        sum = sum + ld;
        prd = prd * ld;
        copy = copy / 10;
    }

    if (num==(sum+prd))
    {
        cout << "\nSpecial Number";
    }
    else
    {
        cout << "\nNot A Special Number";
    }

    return 0;
}