#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
int h[1000005];

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int idx;
        cin >> idx;
        if (h[idx + 1] == 0)
            h[idx]++;
        else
        {
            h[idx]++;
            h[idx + 1]--;
        }
    }
    cout << accumulate(h, h + 1000001, 0);

    return 0;
}