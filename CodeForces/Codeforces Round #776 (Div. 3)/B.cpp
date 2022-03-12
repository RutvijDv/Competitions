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
    ll l, r, a;

    cin >> l >> r >> a;

    ll ans = INT_MIN;

    ll q = r / a;
    ll rem = r % a;

    if (rem < (a - 1) && (r - rem - 1) >= l)
    {
        ans = q - 1;
        ans += a - 1;
    }
    else
    {
        ans = q + rem;
    }

    cout << ans << "\n";
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