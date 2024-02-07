#include <iostream>
using namespace std;

int binarySearch(int array[], int low, int high, int key, int &comparisons)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        comparisons++;

        if (key == array[mid])
        {
            return mid;
        }

        if (key > array[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int n;

    cout << "Enter The Size Of Array --> ";
    cin >> n;

    int Array[n];

    cout << "Enter Elements In Array In Sorted Order --> " << endl;

    for (int i=0; i<n; i++)
    {
        cout << "Element " << i+1 << ": ";
        cin >> Array[i];
    }

    int key;

    cout << "Enter Key Element To Search --> ";
    cin >> key;

    int comparisons = 0;

    int result = binarySearch(Array, 0, n - 1, key, comparisons);

    if (result == -1)
    {
        cout << "Element Not Found !" << endl;
    }
    else
    {
        cout << "Element Found At Index " << result << endl;
    }

    cout << "Total Number Of Comparisons --> " << comparisons << endl;

    return 0;
}