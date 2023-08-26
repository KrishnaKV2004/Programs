#include <iostream>

using namespace std;

void arrSort(int [], int [], int, int);

int main()
{
    int i,j,p,q;

    cout << "\nElements In Array A : ";
    cin >> p;
    cout << "Elements In Array B : ";
    cin >> q;

    int A[p], B[q];

    cout << "\nEnter Elements In A -->\n\n";

    for (i=0; i<p; i++)
    {
        cin >> A[i];
    }

    cout << "\nEnter Elements In B -->\n\n";

    for (i=0; i<q; i++)
    {
        cin >> B[i];
    }

    arrSort(A, B, p, q);

    return 0;
}

void arrSort(int A[], int B[], int p, int q)
{
    int i,j,tmp;
    int merged[p+q];

    for (i=0; i<p; i++)
    {
        merged[i] = A[i];
    }

    for (i=p,j=0; i<(p+q); i++,j++)
    {
        merged[i] = B[j];
    }

    for (i=0; i<(p+q); i++)
    {
        for (j=i+1; j<(p+q); j++)
        {
            if (merged[i] > merged[j])
            {
                tmp = merged[i];
                merged[i] = merged[j];
                merged[j] = tmp;
            }
        }
    }

    cout << "\nSorted Arrays -->\n\n";

    cout << "A --> ";

    for (i=0; i<p; i++)
    {
        cout << merged[i];
    }

    cout << endl;

    cout << "B --> ";

    for (i=p; i<(p+q); i++)
    {
        cout << merged[i];
    }

    cout << endl;
}