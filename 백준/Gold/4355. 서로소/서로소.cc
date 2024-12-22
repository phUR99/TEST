#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int main()
{
    fastio;
    auto solve = [](int &n) -> int
    {
        int ret = n;
        if (n == 1)
            return 0;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i)
                continue;
            ret -= ret / i;
            while (n % i == 0)
            {
                n /= i;
            }
        }

        if (n > 1)
            ret -= ret / n;
        return ret;
    };
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        cout << solve(n) << '\n';
    }

    return 0;
}