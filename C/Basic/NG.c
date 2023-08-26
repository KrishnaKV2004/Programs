/*
    Name - Krishna Verma
    University Roll No - 2021811
    Section - J

    Input a matrix of order m x n and print the square of the
    elements in the principal diagonal and cube of the elements
    in the secondary diagonal.
*/

#include <stdio.h>

void main()
{
    int arr[50];
    int n, i, target;
    int near_g = 0;
    int near_s = 0;
    int diff_g = 50;
    int diff_s = 50;

    printf("\t\t\t***** INPUT *****\n\n");
    printf("Number Of Elements In The Array: ");
    scanf("%d", &n);

    printf("Enter The Elements Of The Array: \n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter The Target Element: ");
    scanf("%d", &target);

    for (i = 0; i < n; i++)
    {
        
        if (arr[i] > target)
        {
            
            if (arr[i] - target < diff_g)
            {
                near_g = arr[i];
                diff_g = arr[i] - target;
            }
        }
        else if (arr[i] < target) 
        {
            if (target - arr[i] < diff_s)
            {
                near_s = arr[i];
                diff_s = target - arr[i];
            }
        }
    }
    printf("\t\t\t***** OUTPUT *****\n\n");
    printf("The Nearest Greater Element Is %d\n", near_g);
    printf("The Nearest Smaller Element Is %d\n", near_s);
}