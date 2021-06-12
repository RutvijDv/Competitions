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

    int n, m, x;
    unordered_map<int, int> mp;
    map<int, int> main_map;
    cin >> n >> m;
    if (n == m)
    {
        cout << "-1" << endl;
        return 0;
    }

    vii arr(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[i] = x;
        mp[x]++;
    }
    for (auto i : mp)
    {
        main_map.insert({i.fi, i.se});
    }

    mp.clear();
    int value, count;
    for (auto i : main_map)
    {
        value = i.fi;
        count = i.se;

        if (count >= m)
        {
            mp[value] = m;
            break;
        }
        else
        {
            m -= count;
            mp[value] = count;
        }
    }

    for (int i = 0; i < n; i++)
    {
        value = arr[i];
        count = mp[value];

        if (count > 0)
            mp[value]--;
        else
            cout << value << " ";
    }

    return 0;
}