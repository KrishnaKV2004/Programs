/* 
            1
          1 2 1
        1 2 3 2 1
      1 2 3 4 3 2 1
*/

#include <iostream>

using namespace std;

int main()
{
    int i,j,k,l,n;

    cout << "\nEnter Limit : ";
    cin >> n;

    for (i=1; i<n; i++)
    {
        for (j=1; j<n-i; j++)
        {
            cout << " ";
        }
        for (k=1; k<=i; k++)
        {
            cout << k;
        }
        for (l=i-1; l>=1; l--)
        {
            cout << l;
        }

        cout << endl;
    }

    return 0;
}