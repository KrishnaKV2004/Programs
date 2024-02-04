#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int arr[], int n, int key)
{
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step,n)-1] < key)
    {
        prev = step;
        step += sqrt(n);

        if (prev >= n)
        {
            return -1;
        }
    }

    for (int i=prev; i<min(step,n); i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

int main()
{
    int n;

    cout << "Enter Size Of Array --> ";
    cin >> n;

    int arr[n];
    cout << "Enter Elements In Sorted Order --> ";

    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int key;

    cout << "Enter Key To Search --> ";
    cin >> key;

    int result = jumpSearch(arr, n, key);

    if (result != -1)
    {
        cout << "Element Found At Index --> " << result << endl;
    }
    else
    {
        cout << "Element Not Found !" << endl;
    }

    return 0;
}