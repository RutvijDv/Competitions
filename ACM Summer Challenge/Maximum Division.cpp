#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int res = 0, n = s.length();
    bool flag = true;

    for (int i = 0; i < n; i++)
    {

        if (s[i] != s[i - 1])
            flag = true;

        if (flag == true)
        {
            res++;
            flag = !flag;
        }
        else
        {
            if (i + 1 < n)
            {
                i++;
                res++;
                flag = !flag;
            }
        }
    }

    cout << res << endl;
}
