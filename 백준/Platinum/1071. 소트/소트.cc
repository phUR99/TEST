#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cnt[1005];
int n;

int main()
{
    fastio;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int idx;
        cin >> idx;
        cnt[idx]++;
    }
    while (n--)
    {
        for (int i = 0; i <= 1000; i++)
        {
            if (!cnt[i])
                continue;
            if (cnt[i + 1])
            {
                int M = 0;
                for (int j = i + 2; j <= 1000; j++)
                {
                    if (cnt[j])
                    {
                        M = j;
                        break;
                    }
                }

                if (M == 0)
                    continue;
                while (cnt[i] > 0)
                {
                    cout << i << ' ';
                    cnt[i]--;
                }
                cout << M << ' ';
                cnt[M]--;
            }
            else
            {
                cout << i << ' ';
                cnt[i]--;
                break;
            }
        }
    }

    return 0;
}