#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int k = m - (2 * n);
        long long int summ = 0, c, w;
        vector<pair<long long int, pair<int, long long int>>> corr(m);
        vector<bool> sel(m, true);
        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
        for (int i = 0; i < k; i++)
        {
            cin >> c >> w;
            corr[i] = make_pair(c, make_pair(i + 1, w));
            summ += w;
            pq.push(make_pair(w, i));
        }

        for (int i = k; i < m; i++)
        {
            cin >> c >> w;
            corr[i] = make_pair(c, make_pair(i, w));
            summ += w;
            if (!pq.empty() && pq.top().first > w)
            {
                pq.pop();
                pq.push(make_pair(w, i + 1));
            }
        }

        while (!pq.empty())
        {
            pair<long long int, long long int> i = pq.top();
            summ -= i.first;
            sel[i.second] = false;
        }

        sort(corr.begin(), corr.end());
        cout << summ << "\n";
        int i = 0, j = m - 1, x = 0;
        while (i < j && x < n)
        {
            if (sel[corr[i].second.first - 1] && sel[corr[j].second.first - 1])
            {
                cout << corr[i].second.first << " " << corr[j].second.first << "\n";
                i++;
                j--;
                x++;
            }
            else
            {
                if (!sel[corr[i].second.first - 1])
                {
                    i++;
                }
                if (!sel[corr[j].second.first - 1])
                {
                    j--;
                }
            }
        }
        cout << "\n";
    }

    return 0;
}