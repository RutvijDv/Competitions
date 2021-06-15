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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    ll count = 0;
    cin >> s;

    ll n = s.length();
    bool flag = true;

    while (s[0] == '0')
    {
        s = s.substr(1);
    }

    for (ll i = s.length() - 1; i >= 0; i--)
    {
        if (flag)
        {
            if (s[i] == '0')
                count += 1;
            else
            {
                if (i != 0)
                    count += 2;
                flag = false;
            }
        }

        else
        {
            if (s[i] == '0')
                count += 2;
            else
                count += 1;
        }
    }

    cout << count << endl;

    return 0;
}