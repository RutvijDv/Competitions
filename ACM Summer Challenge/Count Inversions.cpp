#include <bits/stdc++.h>

using namespace std;

// Merge two sorted subarrays `arr[low … mid]` and `arr[mid+1 … high]`
int Merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;
    int inversionCount = 0;

    // while there are elements in the left and right runs
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            aux[k++] = arr[i++];
        }
        else
        {
            aux[k++] = arr[j++];
            inversionCount += (mid - i + 1); // NOTE
        }
    }

    // copy remaining elements
    while (i <= mid)
    {
        aux[k++] = arr[i++];
    }

    /* no need to copy the second half (since the remaining items
       are already in their correct position in the temporary array) */

    // copy back to the original array to reflect sorted order
    for (int i = low; i <= high; i++)
    {
        arr[i] = aux[i];
    }

    return inversionCount;
}

int MergeSort(int arr[], int aux[], int low, int high)
{
    if (high == low)
    {
        return 0;
    }

    int mid = (low + ((high - low) >> 1));
    int inversionCount = 0;

    inversionCount += MergeSort(arr, aux, low, mid);

    inversionCount += MergeSort(arr, aux, mid + 1, high);

    inversionCount += Merge(arr, aux, low, mid, high);

    return inversionCount;
}

int main()
{
    int n, q, x, y;
    cin >> n >> q;

    int v[n], b[n], c[n], count = 0, temp;

    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
    {
        b[i] = v[i];
        c[i] = v[i];
    }

    count = MergeSort(b, c, 0, n - 1);

    for (int i = 0; i < q; i++)
    {
        temp = 0;

        cin >> x >> y;
        x--;
        y--;

        int l = min(x, y);
        int r = max(x, y);
        if (l == r)
            cout << count << endl;
        else
        {
            if (v[r] > v[l])
                temp++;
            if (v[r] < v[l])
                temp--;
            for (int j = l + 1; j < r; j++)
            {
                if (v[j] > v[r])
                    temp--;
                if (v[j] < v[r])
                    temp++;

                if (v[j] > v[l])
                    temp++;
                if (v[j] < v[l])
                    temp--;
            }

            cout << count + temp << endl;
        }
    }
    return 0;
}