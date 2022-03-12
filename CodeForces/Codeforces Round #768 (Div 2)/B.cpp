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

        vll arr;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.pb(x);
        }
        reverse(all(arr));

        int i = 2;

        int cnt = 0;
        int pack = 1;
        int prev = arr[0];

        while (i <= n)
        {
            while (i <= n && arr[i - 1] == prev)
            {
                i++;
                pack++;
            }

            if (pack == n)
            {
                break;
            }

            i = pack * 2;
            pack = i;
            cnt++;
            i++;
        }

        cout << cnt << "\n";
    }
    return 0;
}