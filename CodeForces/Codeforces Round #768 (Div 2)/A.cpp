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
}

int main()
{
    fast_cin();

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vii a;
        vii b;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.pb(x);
        }

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            b.pb(x);
        }

        int l = INT_MIN, k = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int m, n;

            m = a[i];
            n = b[i];

            l = max(l, max(m, n));

            if (m >= n)
            {
                k = max(k, n);
            }
            else
            {
                k = max(k, m);
            }
        }

        cout << l * k << "\n";
    }
    return 0;
}