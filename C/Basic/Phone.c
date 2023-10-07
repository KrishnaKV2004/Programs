#include <stdio.h>
#include <string.h>

typedef struct contacts
{
    char name[25];
    char phone[20];
} person;

int main()
{
    int i;
    char user[25];
    person per[2] = {{"Krishna", "+91-7906400988"}, {"Devansh", "+91-8473874394"}};

    printf("\nEnter Name : ");
    gets(user);

    for (i=0; i<2; i++)
    {
        if (strcmp(per[i].name, user) == 0)
        {
            printf("\nContact Found !");
            printf("\nPhone Number : %s", per[i].phone);
            return 0;
        }
    }
    printf("\nContact Not Found !");
    return 0;
}