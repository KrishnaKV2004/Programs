#include <stdio.h>

void namaste();
void bonjour();

int main()
{
    char nat;
    printf("Type I for India and F for French : ");
    scanf("%c", &nat);
    if (nat=='I') {
        namaste();
    } else if (nat == 'F') {
        bonjour();
    } else {
        printf("Invalid Input");
    }
    return 0;
}

void namaste() {
    printf("Namaste\n");
}

void bonjour() {
    printf("Bonjour\n");
}