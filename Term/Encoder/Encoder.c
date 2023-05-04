//  Including Libraries -->
#include <stdio.h>
#include <string.h>

void main()
{
    //  Declaring Variables And Arrays -->
    FILE *fptr_e, *fptr_d;
    int i;
    char choice, f_choice, w_pass_choice;
    char data[100], data_en[100], data_de[100], pass_u[8];
    char pass[8] = {'K','V','2','0','0','4','!','\0'};

    printf("\nJai Shree Ram !");
    
    menu :  //  Printing Menu -->
        printf("\n\nWhat's Your Task ?\n");
        printf("\nEncode --> [E] :");
        printf("\nDecode --> [D] :");
        printf("\n\nYour Task ? : ");
        scanf(" %c",&choice);

    //  Selecting Function To Perform As Per The Choice -->
    switch (choice)
    {Jai Shree Ram  Mod

    case 'E' :
    case 'e' :

        fptr_e = fopen("Encoded.txt","a");

        printf("\nYou Want To Encode !\n");
        printf("\nEnter Password To Verify --> ");
        fflush(stdin);
        fgets(pass_u,8,stdin);

        if (strcmp(pass,pass_u)==0)
        {
            printf("\nVerification Done !\n");
            printf("\nEnter Data To Encode --> ");
            fflush(stdin);
            fgets(data,100,stdin);

            for (i=0; data[i]!='\0'; i++)
            {
                if (i%2==0)
                {
                    data_en[i] = data[i] - 67;
                }
                else
                {
                    data_en[i] = data[i] + 27;
                }
            }

            printf("\nEncoded Data --> ");
            puts(data_en);
            printf("\n");

            fprintf(fptr_e, "%s\n", data_en);
            fclose(fptr_e);

            goto c_menu;
        }
        else
        {
            printf("\nInvalid Password !\n");
            goto w_pass;
        }
        break;

    case 'D' :
    case 'd' :

        fptr_d = fopen("Decoded.txt","a");

        printf("\nYou Want To Decode !\n");
        printf("\nEnter Password To Verify --> ");
        fflush(stdin);
        fgets(pass_u,8,stdin);

        if (strcmp(pass,pass_u)==0)
        {
            printf("\nVerification Done !\n");
            printf("\nEnter Data To Decode --> ");
            fflush(stdin);
            fgets(data,100,stdin);

            for (i=0; data[i]!='\0'; i++)
            {
                if (i%2==0)
                {
                    data_de[i] = data[i] + 67;
                }
                else
                {
                    data_de[i] = data[i] - 27;
                }
            }

            printf("\nDecoded Data --> ");
            puts(data_de);
            printf("\n");

            fprintf(fptr_d, "%s\n", data_de);
            fclose(fptr_d);

            goto c_menu;
        }
        else
        {
            printf("\nInvalid Password !\n");
            goto w_pass;
        }
    
    default:
        break;

        c_menu :
            printf("Do You Want To Continue ? [Y/N] : ");
            scanf(" %c",&f_choice);

            if (f_choice == 'Y' || f_choice == 'y')
            {
            goto menu;
            }
            else
            {
                goto end;
            }

        w_pass :
            printf("\nEnter Choice -->\n");
            printf("\nTry Again ! [R] :");
            printf("\nQuit ! [Q] :");
            scanf(" %c",&w_pass_choice);

            if (w_pass_choice == 'R' || w_pass_choice == 'r')
            {
                goto menu;
            }
            else if (w_pass_choice == 'Q' || w_pass_choice == 'q')
            {
                goto end;
            }
            else
            {
                printf("\nInvalid Input !");
                goto end;
            }

        end :
            printf("\nJai Shree Ram !\n\n");
    }
}