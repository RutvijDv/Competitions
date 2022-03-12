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

    map<ll, vector<ll>> wtoc;
    unordered_map<ll, ll> ctoi;

    for (int i = 0; i < m; i++)
    {
        ll c, w;
        cin >> c >> w;

        wtoc[w].push_back(c);
        ctoi[c] = i + 1;
    }

    int cnt = 0;
    vector<ll> cod;

    ll sum = 0;

    for (auto temp : wtoc)
    {

        vector<ll> jemp = temp.second;

        for (int i = 0; i < jemp.size(); i++)
        {
            if (cnt == 2 * n)
            {
                break;
            }
            cod.push_back(jemp[i]);
            sum += temp.first;
            cnt++;
        }
    }

    sort(cod.begin(), cod.end());
    cout << sum << "\n";

    ll l = 0;
    ll r = cod.size() - 1;

    while (l < r)
    {
        int a = ctoi[cod[l]];
        int b = ctoi[cod[r]];

        cout << min(a, b) << " " << max(a, b) << "\n";
        l++;
        r--;
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