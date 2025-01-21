#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll cache[105];

int main()
{
    fastio;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cache[i] = cache[i - 1] + 1;
        for (int j = 3; j < i; j++)
        {
            cache[i] = max(cache[i], cache[i - j] * (j - 1));
        }
    }

    cout << cache[n];
    return 0;
}