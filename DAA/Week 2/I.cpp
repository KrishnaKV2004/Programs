#include <iostream>

using namespace std;

int binarySearch(int arr[], int low, int high, int key, int& count_duplicates)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (key == arr[mid])
        {
            count_duplicates = 1;

            int left = mid - 1;
            while (left >= low && arr[left] == key)
            {
                count_duplicates++;
                left--;
            }

            int right = mid + 1;
            while (right <= high && arr[right] == key)
            {
                count_duplicates++;
                right++;
            }

            return mid;
        }
        else if (key > arr[mid])
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

    cout << "\nEnter The Size Of Array --> ";
    cin >> n;

    int Array[n];

    cout << "\nEnter Elements In Array In Sorted Order --> \n" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> Array[i];
    }

    int key;

    cout << "\nEnter Key Element To Search --> ";
    cin >> key;

    int count_duplicates = 0;
    int result = binarySearch(Array, 0, n - 1, key, count_duplicates);

    if (result == -1)
    {
        cout << "\nElement Not Found !" << endl;
    }
    else
    {
        cout << "\nElement Found At Index " << result << endl;
        cout << "\nNumber of Duplicates: " << count_duplicates - 1 << endl;
    }

    return 0;
}