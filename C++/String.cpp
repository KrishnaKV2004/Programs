#include <iostream>

using namespace std;

int main()
{
    int i;
    int upp = 0, low = 0, vow = 0, dig = 0;
    const int MAX = 25;
    char str[MAX];

    cout << "\nEnter String : ";
    cin.getline(str, MAX); // Use cin.getline() to read a whole line with spaces

    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            upp++;
        }

        if (str[i]>='a' && str[i]<='z')
        {
            low++;
        }

        if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ||
            str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
        {
            vow++;
        }

        if (str[i]>='0' && str[i]<='9')
        {
            dig++;
        }
    }

    cout << "\nNumber Of Uppercase : " << upp;
    cout << "\nNumber Of Lowercase : " << low;
    cout << "\nNumber Of Vowels : " << vow;
    cout << "\nNumber Of Digits : " << dig;

    return 0;
}