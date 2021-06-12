#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;

    string s;
    char x;
    cin >> s;

    unordered_map<char, bool> mp;

    for (long long i = 0; i < m; i++)
    {
        cin >> x;
        mp[x] = true;
    }

    long long res = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        x = s[i];
        if (mp[x] == false)
            count++;
        else
        {
            res += (count) * (count + 1) / 2;
            count = 0;
        }
    }
    res += (count) * (count + 1) / 2;

    cout << res << endl;
}
