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
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }

    int cnt = n;
    stack<int> s;

    while (cnt > 0)
    {

        int idx = 0;

        while (idx < n)
        {
            if (arr[idx] == cnt)
                break;
            idx++;
        }

        s.push((idx + 1) % cnt);

        rotate(arr.begin(), arr.begin() + (idx + 1) % cnt, arr.end() - (n - cnt));

        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;

        cnt--;
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
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