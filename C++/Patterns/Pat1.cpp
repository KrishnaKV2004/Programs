/*  
    A B C D E
    F G H I
    J K L
    M N
    O
*/

#include <iostream>

using namespace std;

int main()
{
    int n,i,j;
    char ch = 'A';

    cout << "Enter Limit : ";
    cin >> n;

    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n-i+1;j++)
        {
            cout << ch;
            ch++;
        }
        cout << "\n";
    }

    return 0;
}