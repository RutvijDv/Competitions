#include <bits/stdc++.h>
using namespace std;

long long int solve(vector<long long> &arr, int n)
{
    long long int res = 1;

    for (int i = 0; i < n && arr[i] <= res; i++)
        res = res + arr[i];

    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> arr(n, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        long long int res = solve(arr, n);
        cout << res << "\n";
    }

    return 0;
}