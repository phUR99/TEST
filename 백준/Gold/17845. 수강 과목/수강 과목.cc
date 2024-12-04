#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, k;
int cache[10005];

int main()
{
    fastio;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int idx, val;
        cin >> val >> idx;
        for (int j = n; j >= idx; j--)
        {
            cache[j] = max(cache[j], cache[j - idx] + val);
        }
    }
    cout << cache[n];

    return 0;
}