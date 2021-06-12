
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, sumA = 0, sumB = 0, res = 0;
    cin >> n;
    vector<long long> A(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        sumA += A[i];
    }

    cin >> m;
    vector<long long> B(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
        sumB += B[i];
    }

    if (sumA != sumB)
        cout << "-1" << endl;
    else
    {
        long long i = 0, j = 0, temp1 = 0, temp2 = 0;

        while (i < n && j < m)
        {
            if (A[i] == B[j])
            {
                i++;
                j++;
                res++;
            }
            else
            {
                temp1 += A[i];
                temp2 += B[j];
                while (i < n && j < m)
                {

                    if (temp1 < temp2)
                    {
                        i++;
                        temp1 += A[i];
                        if (temp1 == temp2)
                        {
                            temp1 = 0;
                            temp2 = 0;
                            i++;
                            j++;
                            break;
                        }
                    }
                    else if (temp2 < temp1)
                    {
                        j++;
                        temp2 += B[j];
                        if (temp1 == temp2)
                        {
                            temp1 = 0;
                            temp2 = 0;
                            i++;
                            j++;
                            break;
                        }
                    }
                }
                res++;
            }
        }
        cout << res << endl;
    }
}