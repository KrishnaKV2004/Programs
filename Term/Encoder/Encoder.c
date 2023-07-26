//  Encoder And Decoder !

/*
        Assumptions -->

    ∙   File pointer fptr_e to store encoded data
    ∙   File pointer fptr_d to store decoded data
    ∙   Integer variable i for loop conditions
    ∙   Character variable choice for [Encode/Decode]
    ∙   Character variable f_choice for [Continue/End]
    ∙   Character variable w_pass_choice [Try again/End]
    ∙   Goto c_menu to goto printing menu
    ∙   Goto w_pass to try again when password is wrong
    ∙   Goto c_menu to encode and decode again
    ∙   Goto end to quit the program
    ∙   Character array data of size 100 to store data
    ∙   Character array data_en of size 100 to store encoded data
    ∙   Character array data_de of size 100 to store decoded data
    ∙   Character array pass_u of size 8 to store password
*/
/*
        Flow Of Program -->

    ∙   Start
    ∙   Ask for task Encode or Decode
    ∙   Open the files in append mode
    ∙   Verify Password Entered
    ∙   If wrong, ask user to try again or quit
    ∙   If yes, goto c_menu to enter password again
    ∙   If no, goto end to quit
    ∙   If correct, input data to Encode/Decode
    ∙   If Encoding, subtract 67 at even index and add 27 at odd index
    ∙   If Decoding, add 67 at even index and subtract 27 at odd index
    ∙   Display and store the output in respective files
    ∙   Ask if user wants to continue
    ∙   If yes, goto menu to start again
    ∙   If no, goto end to quit
    ∙   Close the files that are opened
    ∙   Stop
*/

//  Including Libraries -->

#include <stdio.h>
#include <string.h>

//  Main Function -->

void main()
{
    //  Declaring Variables And Arrays -->

    FILE *fptr_e, *fptr_d;
    int i;
    char choice, f_choice, w_pass_choice;
    char data[100], data_en[100], data_de[100], pass_u[8];
    char pass[8] = {'K','V','2','0','0','4','!','\0'};

    printf("\nJai Shree Ram !");
    
    menu :  //  Printing Menu
    
        printf("\n\nWhat's Your Task ?\n");
        printf("\nEncode --> [E] :");
        printf("\nDecode --> [D] :");
        printf("\n\nYour Task ? : ");
        scanf(" %c",&choice);

    //  Selecting Function To Perform As Per The Choice -->

    switch (choice)
    {
        
    case 'E' :          //  If Encoding [E/e]
    case 'e' :

        //  Opening File -->

        fptr_e = fopen("Encoded.txt","a");

        //  Asking For Password -->

        printf("\nYou Want To Encode !\n");
        printf("\nEnter Password To Verify --> ");
        fflush(stdin);
        fgets(pass_u,8,stdin);

        if (strcmp(pass,pass_u)==0)         //  Checking For Password
        {
            printf("\nVerification Done !\n");
            printf("\nEnter Data To Encode --> ");
            fflush(stdin);
            fgets(data,100,stdin);

            //  Encoding Data -->

            for (i=0; data[i]!='\0'; i++)
            {
                if (i%2==0)
                {
                    data_en[i] = data[i] - 67;
                }
                if (i%2!=0)
                {
                    data_en[i] = data[i] + 27;
                }
            }

            //  Display Encoded Data -->

            printf("\nEncoded Data --> ");
            puts(data_en);
            printf("\n");

            //  Saving Encoded Data In File -->

            fprintf(fptr_e, "%s\n", data_en);
            fclose(fptr_e);

            goto c_menu;        //  Menu To Continue
        }
        else
        {
            printf("\nInvalid Password !\n");       //  If Password Is Wrong
            goto w_pass;        //  Menu To Try Again
        }
        break;

    case 'D' :          //  If Decoding [D/d]
    case 'd' :

        //  Opening File -->

        fptr_d = fopen("Decoded.txt","a");

        //  Asking For Password -->

        printf("\nYou Want To Decode !\n");
        printf("\nEnter Password To Verify --> ");
        fflush(stdin);
        fgets(pass_u,8,stdin);
        fflush(stdin);

        if (strcmp(pass,pass_u)==0)         //  Checking For Password
        {
            printf("\nVerification Done !\n");
            printf("\nEnter Data To Decode --> ");
            fflush(stdin);
            scanf(" %s",&data);

            //  Decoding Data -->

            for (i=0; data[i]!='\0'; i++)
            {
                if (i%2==0)
                {
                    data_de[i] = data[i] + 67;
                }
                if (i%2!=0)
                {
                    data_de[i] = data[i] - 27;
                }
            }

            //  Display Decoded Data -->

            printf("\nDecoded Data --> ");
            puts(data_de);
            printf("\n");

            //  Saving Decoded Data In File -->

            fprintf(fptr_d, "%s\n", data_de);
            fclose(fptr_d);

            goto c_menu;        //  Menu To Continue
        }
        else
        {
            printf("\nInvalid Password !\n");       //  If Password Is Wrong
            goto w_pass;        //  Menu To Try Again
        }
    
    default:
        break;

        //  To Continue Encoding/Decoding Data -->

        c_menu :
            printf("Do You Want To Continue ? [Y/N] : ");
            scanf(" %c",&f_choice);

            if (f_choice == 'Y' || f_choice == 'y')
            {
            goto menu;  //  Goto Menu
            }
            else
            {
                goto end;   //  Goto End
            }

        //  If Password Is Wrong -->

        w_pass :
            printf("\nEnter Choice -->\n");
            printf("\nTry Again ! [R] :");
            printf("\nQuit ! [Q] :");
            scanf(" %c",&w_pass_choice);

            if (w_pass_choice == 'R' || w_pass_choice == 'r')
            {
                goto menu;  //  Goto Menu
            }
            else if (w_pass_choice == 'Q' || w_pass_choice == 'q')
            {
                goto end;   //  Goto End
            }
            else
            {
                printf("\nInvalid Input !");
                goto end;   //  Goto End
            }

        //  To Quit -->
            
        end :
            printf("\nJai Shree Ram !\n\n");
    }
}