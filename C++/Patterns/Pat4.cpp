#include <iostream>

using namespace std;

int main()
{
    int i,j,n;

    cout << "\nEnter Limit : ";
    cin >> n;

    for (i=1; i<=n; i++)
    {
        for (j=i; j<i+5; j++)
        {
            cout << ((2*j-1)%10);
        }
        
        cout << endl;
    }

    return 0;
}