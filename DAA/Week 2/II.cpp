#include <iostream>

using namespace std;

void findIndices(int arr[], int n)
{
    for (int k = n - 1; k >= 0; k--)
    {
        int i = 0, j = k - 1;

        while (i < j)
        {
            int sum = arr[i] + arr[j];

            if (sum == arr[k])
            {
                cout << i << " " << j << " " << k << endl;
                return;
            } else if (sum < arr[k])
            {
                i++;
            } else
            {
                j--;
            }
        }
    }
    cout << "No sequence found" << endl;
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        findIndices(arr, n);
    }
    return 0;
}