#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 100000007;
double eps = 1e-12;
#define for0(i, e) for (ll i = 0; i < e; i++)
#define fors1(i, s, e) for (ll i = s; i < e; i++)
#define rfor0(i, s) for (ll i = s; i >= 0; i--)
#define rfor1(i, s, e) for (ll i = s; i >= e; i--)

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

int main()
{
    fast_cin();

    ll n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> mat(n + 2, vector<ll>(m + 2, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    }

    vector<pair<ll, ll>> positions;
    ll x = 1, y = 1;

    int direction = 1;
    if (mat[x][y] == 1)
    {
        direction = 2;
        positions.pb({x, y});
    }
    while (true)
    {

        if (direction == 1)
            y += 1;
        else if (direction == -1)
            y -= 1;
        else if (direction == 2)
            x += 1;
        else if (direction == -2)
            x -= 1;

        if (x == n + 1 || y == m + 1 || x == 0 || y == 0)
        {
            direction *= -1;
            positions.pb({x, y});
            if (x == 1 && y == 0)
                break;
        }
        else if (mat[x][y] == 1)
        {

            if (abs(direction) == 1)
                direction = direction << 1;
            else
                direction = direction >> 1;

            positions.pb({x, y});
            if (x == 1 && y == 0)
                break;
        }
    }

    ll mod = positions.size();
    long long z;
    for (int i = 0; i < q; i++)
    {
        cin >> z;
        z--;
        z = z % mod;
        cout << positions[z].se << " " << positions[z].fi << endl;
    }

    return 0;
}