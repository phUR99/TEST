#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[1555][105];
int n;
const int MOD = 1e9 + 7;
int arr[] = {1, 5};
int solve(int begin, int remain)
{
    if (begin == n)
        return remain == 0;
    int &ret = cache[begin][remain];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < 2; i++)
    {
        int newRemain = (remain * 10 + arr[i]) % 15;
        ret += solve(begin + 1, newRemain);
        ret %= MOD;
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    int ret = solve(0, 0);
    cout << ret;
    return 0;
}