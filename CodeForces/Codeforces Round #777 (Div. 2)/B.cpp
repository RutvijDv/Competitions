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
    vector<vector<pair<int, int>>> val(n, vector<pair<int, int>>(m, {0, 0}));
    string s;

    for (int i = 0; i < n; i++)
    {
        cin >> s;

        for (int j = 0; j < m; j++)
        {
            arr[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int common = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == "1")
            {
                val[i][j].first = common;
                common++;
            }
            else
                common = 0;
        }

        common = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            if (arr[i][j] == "1")
            {
                val[i][j].first += common + 1;
                common++;
            }
            else
                common = 0;
        }
    }

    for (int j = 0; j < m; j++)
    {
        int common = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] == "1")
            {
                val[i][j].second = common;
                common++;
            }
            else
                common = 0;
        }

        common = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i][j] == "1")
            {
                val[i][j].second += common + 1;
                common++;
            }
            else
                common = 0;
        }
    }

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mp[val[i][j].first * val[i][j].second]++;
        }
    }

    for (auto x : mp)
    {
        if (x.first > 0)
        {
            if (x.second % x.first != 0)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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