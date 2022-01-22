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

void updateMEX(vector<int> &arr, unordered_map<int, bool> &mp, int &curr_minimal)
{
    if (mp[curr_minimal] == false)
        return;

    while (true)
    {
        curr_minimal++;

        if (mp[curr_minimal] == false)
        {
            break;
        }
    }

    return;
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
        vector<int> arr;
        vector<int> barr;

        unordered_map<int, list<int>> entries;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.pb(x);
            entries[x].push_back(i);
        }

        int i = 0;
        int curr_minimal = 0;
        unordered_map<int, bool> mp;

        while (i < n)
        {
            int targetIdx;

            if (entries[curr_minimal].size() > 0 && entries[curr_minimal].front() >= 0)
            {
                targetIdx = entries[curr_minimal].front();

                while (i <= targetIdx)
                {

                    int ele = arr[i];
                    mp[ele] = true;
                    entries[ele].pop_front();

                    i++;
                }
                updateMEX(arr, mp, curr_minimal);
            }
            else
            {
                if (curr_minimal == 0)
                {
                    i++;
                    barr.pb(curr_minimal);
                    continue;
                }
                barr.pb(curr_minimal);
                curr_minimal = 0;
                mp.clear();
            }
        }

        if (curr_minimal > 0)
            barr.pb(curr_minimal);

        cout << barr.size() << endl;

        for (int j = 0; j < barr.size(); j++)
        {
            cout << barr[j] << " ";
        }

        cout << endl;
    }

    return 0;
}