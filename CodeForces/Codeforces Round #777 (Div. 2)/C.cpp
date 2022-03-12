#include <bits/stdc++.h>

using namespace std;

#define read(type) readInt<type>() // Fast read
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vii;
#define umap unordered_map;
#define uset unordered_set;
ll MOD = 100000007;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<string>> arr(n, vector<string>(m, "0"));
    string s;

    for (int i = 0; i < n; i++)
    {
        cin >> s;

        for (int j = 0; j < m; j++)
        {
            arr[i][j] = s[j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (arr[i][j] == "1")
            {
                if (!(j - 1 >= 0 || (i - 1 >= 0 && arr[i - 1][j] == "0")))
                {
                    cout << "-1\n";
                    return;
                }
                cnt++;
            }
        }
    }

    cout << cnt << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (arr[i][j] == "1")
            {
                if (j - 1 >= 0)
                {
                    cout << i + 1 << " " << j << " " << i + 1 << " " << j + 1 << "\n";
                }
                else
                {
                    cout << i << " " << j + 1 << " " << i + 1 << " " << j + 1 << "\n";
                }
            }
        }
    }
}

int main()
{
    fast_cin();

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}