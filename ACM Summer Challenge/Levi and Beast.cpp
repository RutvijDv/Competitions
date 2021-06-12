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

    ll n, m, d, t;
    cin >> n >> m >> d >> t;

    vll weights(n, 0), capacity(n, 0), gaps(m, 0), distance(m + 1, 0);

    for0(i, n)
    {
        cin >> weights[i];
        cin >> capacity[i];
    }

    cin >> gaps[0];
    fors1(i, 1, m) cin >> gaps[i];

    sort(gaps.begin(), gaps.end());

    distance[0] = gaps[0];
    fors1(i, 1, m)
    {
        distance[i] = gaps[i] - gaps[i - 1];
    }

    distance[m] = d - gaps[m - 1];
    sort(distance.begin(), distance.end());

    ll no_of_distances = m + 1;
    ll minimum_cap = INT_MIN;

    bool flag = true;
    // speed>1
    if (d > t)
    {
        flag = false;
    }

    // speed=1
    else if (d == t)
    {
        minimum_cap = 2 * distance[m];
    }

    //speed between 0.5 and 1
    else if (d < t && (2 * d > t))
    {
        // ll normal_miles = t % d;
        // ll god_miles = d - normal_miles;

        // // cout << god_miles << " " << normal_miles << endl;

        // for (ll i = 0; i <= m; i++)
        // {
        //     ll dis = distance[i];
        //     // cout << "dis" << dis << endl;

        //     if (dis <= god_miles)
        //     {
        //         ll cap = dis * 2;
        //         god_miles -= dis;

        //         minimum_cap = max(minimum_cap, cap);
        //         // cout << minimum_cap << endl;
        //     }
        //     else
        //     {
        //         ll cap;
        //         if (god_miles)
        //         {
        //             cap = god_miles * 2 + (dis - god_miles) * 1;
        //             god_miles = 0;

        //             minimum_cap = max(minimum_cap, cap);
        //             // cout << minimum_cap << endl;
        //         }
        //         else
        //         {
        //             cap = dis * 1;

        //             minimum_cap = max(minimum_cap, cap);
        //             // cout << minimum_cap << endl;
        //         }
        //     }
        // }
    }

    //speed less than or equal to 0.5
    else
    {
        minimum_cap = distance[m];
    }

    if (flag == false)
        cout << "-1" << endl;
    else
    {
        ll min_weight = INT_MAX;
        bool slag = false;

        for (ll i = 0; i < n; i++)
        {
            if (capacity[i] >= minimum_cap)
            {
                min_weight = min(min_weight, weights[i]);
                slag = true;
            }
        }

        if (slag)
            cout << min_weight << endl;
        else
            cout << "-1" << endl;
    }

    return 0;
}