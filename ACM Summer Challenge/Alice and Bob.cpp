#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        vector<ll> v(5, 0);
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        v[1] = a % 2;
        v[2] = b % 2;
        v[3] = c % 2;
        v[4] = d % 2;
        ll sum = a + b + c + d;

        bool flag = false;
        if (sum % 2 == 0)
        {
            if (v[4] == 0)
            {
                if (v[1] == 0 && v[2] == 0 && v[3] == 0)
                    flag = true;
            }
            if (v[4] == 1)
            {
                if (v[1] == 1 && v[2] == 1 && v[3] == 1)
                    flag = true;
            }
        }

        if (sum % 2 == 1)
        {
            if (v[4] == 0)
            {
                if (v[1] == 1 && v[2] == 1 && v[3] == 1)
                    flag = true;
                if (v[1] + v[2] + v[3] == 1)
                    flag = true;
            }

            if (v[4] == 1)
            {
                if (v[1] == 0 && v[2] == 0 && v[3] == 0)
                    flag = true;
                if (v[1] + v[2] + v[3] == 2 && a && b && c)
                    flag = true;
            }
        }

        if (flag)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }
    return 0;
}
