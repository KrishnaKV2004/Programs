#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    // Replace "path_to_your_shortcut.lnk" with the actual path to your shortcut file
    const char *shortcutPath = "C:/Users/krish/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Brave Apps/YouTube.lnk";

    // Construct the command to execute the target of the shortcut
    char command[256];
    snprintf(command, sizeof(command), "start \"\" \"%s\"", shortcutPath);

    system("cls");
    printf("Taking You To Youtube --> ");
    sleep(1);

    // Use the system function to execute the command
    int result = system(command);

    system("cls");

    return 0;
}