#include <iostream>

using namespace std;

void insertionSort(int arr[], int n)
{
    int i,j,k;
    int temp;

    for(i=1; i<n; i++)
    {
        j=i-1;
        temp = arr[i];

        while (j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;

        cout << "Step " << i << " : ";

        for(k = 0; k < n; k++)
        {
            cout << arr[k] << "\t";
        }

        cout << endl;
    }
}

int main()
{
    int i,n;

    cout << "\nNumber Of Elements In Array ? --> ";
    cin >> n;

    int arr[n];

    cout << "\nEnter Elements In Array -->\n" << endl;

    for(i=0; i<n; i++)
    {
        cout << "Enter Element " << i+1 << " : ";
        cin >> arr[i];
    }

    cout << endl;

    insertionSort(arr, n);

    cout << "\nSorted Array --> ";
    for(i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}