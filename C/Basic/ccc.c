#include <windows.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    // Replace "whatsapp://" with the correct protocol registered by WhatsApp
    const wchar_t *whatsappProtocol = L"whatsapp";

    system("cls");
    printf("Taking You To Whatsapp --> ");
    sleep(2);

    // Use ShellExecute to open WhatsApp
    HINSTANCE result = ShellExecute(NULL, L"open", whatsappProtocol, NULL, NULL, SW_SHOWNORMAL);

    system("cls");

    return 0;
}