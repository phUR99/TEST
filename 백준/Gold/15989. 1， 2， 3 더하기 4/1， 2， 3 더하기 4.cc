#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int arr[10005];
int cache[4][10005];

int solve(int cur, int val)
{
    if (val == 0)
        return 1;
    if (cur == 0)
        return 0;

    int &ret = cache[cur][val];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i <= val; i += arr[cur])
    {
        ret += solve(cur - 1, val - i);
    }
    return ret;
}
int N, T;

int main()
{
    fastio;
    cin >> T;
    memset(cache, -1, sizeof(cache));

    for (int i = 1; i <= 3; i++)
    {
        arr[i] = i;
    }
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        int answer = solve(3, N);
        cout << answer << '\n';
    }
    return 0;
}