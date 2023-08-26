//  Calculates The Price With GST And Print Total -->

#include <stdio.h>

void main()
{
    float price[3];

    printf("Enter Price : \n");
    scanf("%f", &price[0]);
    scanf("%f", &price[1]);
    scanf("%f", &price[2]);

    printf("Item 1 : %f\n", price[0] + (0.18 * price[0]));
    printf("Item 1 : %f\n", price[1] + (0.18 * price[1]));
    printf("Item 1 : %f\n", price[2] + (0.18 * price[2]));

    float Item_1 = price[0] + (0.18 * price[0]);
    float Item_2 = price[1] + (0.18 * price[1]);
    float Item_3 = price[2] + (0.18 * price[2]);

    printf("Total Cost : %f", Item_1 + Item_2 + Item_3);
}