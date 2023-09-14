/* 
    1 3 5 7 9
    3 5 7 9 1
    5 7 9 1 3
    7 9 1 3 5
    9 1 3 5 7
*/

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