#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    int i=0, d=0, u=0, l=0, s=0;
    const int MAX = 20;
    char str[MAX];
    char dig[MAX], upp[MAX], low[MAX], spc[MAX];

    cout << "\nEnter String : ";
    cin.getline(str, MAX); // Read the entire input string including spaces

    for (i=0; str[i]!='\0'; i++)
    {
        if (isdigit(str[i]))
        {
            dig[d] = str[i];
            d++;
        }
        else if (isupper(str[i]))
        {
            upp[u] = str[i];
            u++;
        }
        else if (islower(str[i]))
        {
            low[l] = str[i];
            l++;
        }
        else
        {
            spc[s] = str[i];
            s++;
        }
    }

    dig[d] = '\0';
    upp[u] = '\0';
    low[l] = '\0';
    spc[s] = '\0';

    cout << "\nSorted String -->\n\n";
    cout << dig << upp << low << spc;

    return 0;
}