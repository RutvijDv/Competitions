#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t;
    cin >> t;
    while (t--)
    {
        int m, k;
        cin >> m >> k;

        vector<pair<int, int>> arr;
        vector<int> a;
        vector<int> b;

        for0(i, m)
        {
            int ai;
            cin >> ai;
            a.pb(ai);
        }

        for0(i, m)
        {
            int bi;
            cin >> bi;
            b.pb(bi);
        }

        for0(i, m)
        {
            arr.pb({a[i], b[i]});
        }

        sort(all(arr));

        ll ans = k;

        for0(i, m)
        {
            int a = arr[i].fi;
            int b = arr[i].se;

            if (ans >= a)
            {
                ans += b;
            }
            else
            {
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}