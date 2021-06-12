#include <bits/stdc++.h>
using namespace std;

void maxValue(long long a[], long long n)
{
    long long presum[n];

    presum[0] = a[0];

    for (long long i = 1; i < n; i++)
    {
        presum[i] = presum[i - 1] + a[i];
    }

    long long l[n], r[n];

    stack<long long> st;

    for (long long i = 1; i < n; i++)
    {

        while (!st.empty() &&
               a[st.top()] >= a[i])
            st.pop();

        if (!st.empty())
            l[i] = st.top() + 1;
        else
            l[i] = 0;

        st.push(i);
    }

    while (!st.empty())
        st.pop();

    for (long long i = n - 1; i >= 0; i--)
    {

        while (!st.empty() &&
               a[st.top()] >= a[i])
            st.pop();

        if (!st.empty())
            r[i] = st.top() - 1;
        else
            r[i] = n - 1;

        st.push(i);
    }

    long long maxProduct = 0;

    long long tempProduct;

    for (long long i = 0; i < n; i++)
    {

        tempProduct = a[i] * (presum[r[i]] -
                              (l[i] == 0 ? 0 : presum[l[i] - 1]));

        maxProduct = max(maxProduct,
                         tempProduct);
    }

    cout << maxProduct;
}

int main()
{

    long long n;
    cin >> n;

    long long arr[n] = {0};
    for (long long i = 0; i < n; i++)
        cin >> arr[i];

    maxValue(arr, n);
}
