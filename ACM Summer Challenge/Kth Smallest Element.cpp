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

ll solve(vector<ll> &a, ll n, ll k)
{
    ll low = a[0] + a[0];
    ll high = a[n - 1] + a[n - 1];

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;

        ll cntLess = 0;
        ll cntEql = 0;

        ll i = 0;
        for (; i < n; i++)
        {
            if (a[i] + a[n - 1] < a[i] + a[i])
                cntLess += (n - i);
            else
                break;
        }

        for (; i < n; i++)
        {
            if (a[i] + a[i] > mid)
                break;

            ll less = lower_bound(a.begin(), a.end(), mid - a[i]) - a.begin() - i;
            ll eql = upper_bound(a.begin(), a.end(), mid - a[i]) - a.begin() - i;

            cntLess += less;
            cntEql = cntEql + eql - less;
        }

        if (cntLess < k && cntLess + cntEql >= k)
        {
            return mid;
        }

        else if (cntLess >= k)
        {
            high = mid - 1;
        }

        else if (cntLess < k && cntLess + cntEql < k)
        {
            low = mid + 1;
        }
    }
}

int main()
{
    fast_cin();

    ll n, k;
    cin >> n >> k;
    vll a(n, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll res = solve(a, n, k);

    cout << res << endl;

    return 0;
}