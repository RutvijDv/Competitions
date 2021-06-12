#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    char x;
    cin >> s;

    int n = s.length();
    unordered_map<char, int> mp;
    vector<pair<char, int>> vec, oddsvec;

    for (int i = 0; i < n; i++)
    {
        x = s[i];
        mp[x]++;
    }

    int count = 0, oddscount = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        vec.push_back({it->first, it->second});
        count++;
        if (it->second % 2 == 1)
            oddscount++;
    }
    sort(vec.begin(), vec.end());

    int l, m = 0;
    l = oddscount / 2;
    if (oddscount % 2 == 1)
        m = 1;

    string res;
    for (int i = 0; i < count; i++)
    {

        if (l && vec[i].second % 2 == 1)
        {
            vec[i].second++;
            l--;
        }
        else if (m && vec[i].second % 2 == 1)
        {
            m--;
        }
        else if (vec[i].second % 2 == 1)
        {
            vec[i].second--;
        }
    }

    for (int i = 0; i < count; i++)
    {
        int c = vec[i].second / 2;
        if (vec[i].second % 2 == 1)
            x = vec[i].first;
        while (c--)
        {
            res += vec[i].first;
        }
    }

    string answer = res;
    reverse(res.begin(), res.end());
    if (oddscount % 2 == 1)
        answer = answer + x + res;
    else
        answer += res;

    cout << answer << endl;
}
