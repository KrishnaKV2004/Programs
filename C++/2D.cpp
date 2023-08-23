#include <iostream>

using namespace std;

int main()
{
    int i,j,m,n,sum=0;

    cout << "\nEnter Number Of Rows : ";
    cin >> m;
    cout << "Enter Number Of Columns : ";
    cin >> n;

    int a[m][n];

    cout << "\nEnter Elements -->\n";

    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "\nOriginal Matrix -->\n";

    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }

    cout << "\nRotated Matrix -->\n";

    for (j=0; j<m; j++)
    {
        for (i=n-1; i>=0; i--)
        {
            cout << a[i][j];
        }
        cout << endl;
    }

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            if ((i==0 || i==n-1) && (j==0 || j==m-1))
            {
                sum = sum + a[i][j];
            }
        }
    }

    cout << "\nSum = " << sum;

    return 0;
}