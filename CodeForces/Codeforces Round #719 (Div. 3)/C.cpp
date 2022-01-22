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

// A utility function to find min of two integers
int minu(int a, int b)
{
    return (a < b) ? a : b;
}

// A utility function to find min of three integers
int min(int a, int b, int c)
{
    return minu(minu(a, b), c);
}

// A utility function to find max of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

void diagonalOrder(int n)
{
    ll ROW = n, COL = n, cnt = 1;
    ll arr[n][n];
    // There will be ROW+COL-1 lines in the output
    for (int line = 1; line <= (ROW + COL - 1); line += 2)
    {
        /* Get column index of the first element
           in this line of output.
           The index is 0 for first ROW lines and
           line - ROW for remaining lines  */
        int start_col = max(0, line - ROW);

        /* Get count of elements in this line. The
           count of elements is equal to minimum of
           line number, COL-start_col and ROW */
        int count = min(line, (COL - start_col), ROW);

        /* Print elements of this line */
        for (int j = 0; j < count; j++)
        {
            arr[minu(ROW, line) - j - 1][start_col + j] = cnt;
            cnt++;
        }
        /* Print elements of next diagonal on next line */
    }
    for (int line = 2; line <= (ROW + COL - 1); line += 2)
    {
        /* Get column index of the first element
           in this line of output.
           The index is 0 for first ROW lines and
           line - ROW for remaining lines  */
        int start_col = max(0, line - ROW);

        /* Get count of elements in this line. The
           count of elements is equal to minimum of
           line number, COL-start_col and ROW */
        int count = min(line, (COL - start_col), ROW);

        /* Print elements of this line */
        for (int j = 0; j < count; j++)
        {
            arr[minu(ROW, line) - j - 1][start_col + j] = cnt;
            cnt++;
        }
        /* Print elements of next diagonal on next line */
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
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
        // cout << "Case #" << t + 1 << ": " << endl;

        ll n;
        cin >> n;
        if (n == 2)
        {
            cout << "-1" << endl;
            continue;
        }

        diagonalOrder(n);
    }
    return 0;
}