#include <iostream>

using namespace std;

int main()
{
    int i,j;
    int A[10], B[5];

    cout << "\nEnter 10 Elements Of A -->\n\n";

    for (i=0; i<10; i++)
    {
        cin >> A[i];
    }

    cout << "\nElements In B Are -->\n\n";

    for (i=0; i<10; i=i+2)
    {
        B[i] = A[i] + A[i+1];
        cout << B[i] <<" ";
    }

    return 0;
}