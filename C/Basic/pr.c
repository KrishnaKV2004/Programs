/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section - J

    Input n characters in an array and replace the characters
    as per the given instructions :
    
    1. Replace all capital vowels with symbol $.
    2. Replace all the capital consonant with symbol #.
    3. Replace all small letter vowels with symbol *.
    4. Replace all the small letter consonant with symbol +.
    5. Replace all special symbols with spaces.
    6. Replace all spaces with digit 5.
    7. Replace all digits with @
*/

#include <stdio.h>

void main()
{
  int n;
  printf("\t\t\t***** INPUT *****\n\n");
  printf("Enter The Number Of Elements : ");
  scanf("%d", &n);

  char ch[n];
  printf("Enter %d Characters as String : ", n);
  scanf("%s", ch);

  for (int i = 0; i < n; i++)
  {
    if (ch[i] >= 'A' && ch[i] <= 'Z')
    {
      if (ch[i] == 'A' || ch[i] == 'E' || ch[i] == 'I' || ch[i] == 'O' || ch[i] == 'U')
      {
        ch[i] = '$';
      } else
      {
        ch[i] = '#';
      }
    } else if (ch[i] >= 'a' && ch[i] <= 'z')
    {
      if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u')
      {
        ch[i] = '*';
      } else {
        ch[i] = '+';
      }
    } else if (ch[i] >= '0' && ch[i] <= '9')
    {
      ch[i] = '@';
    } else if (ch[i] == ' ')
    {
      ch[i] = '5';
    } else {
      ch[i] = ' ';
    }
  }
  printf("\t\t\t***** OUTPUT *****\n\n");
  printf("Modified Characters --> %s\n", ch);
}