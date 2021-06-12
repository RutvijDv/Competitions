

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m, k;
        cin >> n >> m >> k;
        if (m != 1)
        {
            long long res = 0;
            while (n > k)
            {
                n = n / m;
                res++;
            }
            if (n)
                res++;

            cout << res << endl;
        }
        else
        {
            long long res = 0;
            res += n / k;

            if (n % k != 0)
                res++;

            cout << res << endl;
        }
    }
}
