#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
int a[1005], b[1005];
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] -= b[i];
    }
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 0)
            continue;
        while (a[i] > 0)
        {
            int j;
            int cnt = 987654321;
            for (j = i; j < n; j++)
            {
                if (a[j] <= 0)
                    break;
                cnt = min(cnt, a[j]);
            }
            for (int k = i; k < j; k++)
            {
                a[k] -= cnt;
            }
            ret += cnt;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
            continue;
        while (a[i] < 0)
        {
            int j;
            int cnt = -987654321;
            for (j = i; j < n; j++)
            {
                if (a[j] >= 0)
                    break;
                cnt = max(cnt, a[j]);
            }
            for (int k = i; k < j; k++)
            {
                a[k] -= cnt;
            }
            ret -= cnt;
        }
    }
    cout << ret;
    return 0;
}