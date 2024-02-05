#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    // GitHub repository link
    const char *githubLink = "https://github.com/KrishnaKV2004";

    // Construct the command to open the link in Microsoft Edge in fullscreen mode on Windows
    char command[1000];
    #ifdef _WIN32
        sprintf(command, "start %s --start-fullscreen", githubLink);
    #else
        sprintf(command, "xdg-open %s", githubLink);
    #endif

    system("cls");
    printf("\nTaking You To Github --> \t");
    sleep(1.5);

    // Execute the command
    int result = system(command);

    // Check if the command execution was successful
    system("cls");

    return 0;
}