#include <iostream>

using namespace std;

int main()
{
    int i,j,m,n;

    cout << "\nEnter Rows : ";
    cin >> m;
    cout << "Enter Columns : ";
    cin >> n;

    int A[m][n];

    cout << "\nEnter Elements In Matrix -->\n\n";

    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            cout << "Enter " << i << " " << j << " : ";
            cin >> A[i][j];
        }
    }

    cout << "\nOriginal Matrix -->\n\n";

    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            cout << A[i][j] << " ";
        }

        cout << endl;
    }

    cout << "\nUpdate Elements -->\n\n";

    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            if (i+j==m-1)
            {
                continue;
            }
            else
            {
                cout << "Enter " << i << " " << j << " : ";
                cin >> A[i][j];
            }
        }
    }

    cout << "\nUpdated Matrix -->\n\n";

    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            cout << A[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}