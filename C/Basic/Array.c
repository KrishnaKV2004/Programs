/*
    Array -->
    A Collection of Similar Data Type Stored At Contiguous Memory Locations.
*/

#include <stdio.h>

void main()
{
    //  Syntax -->

    //  DataType Identifier[ Size ] = { Array };     -->    Initialize Array
    //  DataType Identifier[ Size ];                 -->    Declaration Of Array

    //  scanf("%d", &Identifier[ Position ]);        -->    Input Array
    //  printf("%d", Identifier[ Position ]);        -->    Output Array

    // int marks[] = {54, 68, 86};
    // printf("%d\n%d\n%d\n", marks[0], marks[1], marks[2]);

    int Mark[3];
    
    printf("Enter Marks In Physics : ");
    scanf("%d", &Mark[0]);

    printf("Enter Marks In Chemistry : ");
    scanf("%d", &Mark[1]);

    printf("Enter Marks In Maths : ");
    scanf("%d", &Mark[2]);

    printf("Physics = %d\nChemistry = %d\nMaths = %d\n", Mark[0], Mark[1], Mark[2]);

    /*  Examples Of Different Data Types -->
        
        int name[size];
        char name[size];
        float name [size];
    */
}