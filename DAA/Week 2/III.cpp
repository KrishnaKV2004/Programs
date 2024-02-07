#include <iostream>

using namespace std;

int main()
{
    int i,j,n,target;

    cout << "\nNumber Of Elements : ";
    cin >> n;

    int A[n];

    cout << "\nEnter Elemets -->\n\n";

    for (i=0; i<n; i++)
    {
        cin >> A[i];
    }

    cout << "\nEnter Target Difference : ";
    cin >> target;

    cout << "\nPair Of Elements Whose Difference Is " << target << " -->\n";

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (A[i] - A[j] == target || A[j] - A[i] == target)
            {
                cout << "\n";
                cout << A[i] << " - " << A[j] << " = " << target;
            }
        }
    }

    return 0;
}