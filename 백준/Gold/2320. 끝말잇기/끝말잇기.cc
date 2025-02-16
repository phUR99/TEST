#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
string arr[20];
int n;
int cache[16][1 << 16][26];
int solve(int cnt, int s, int l)
{
    if (cnt == n)
        return 0;
    int &ret = cache[cnt][s][l];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (s & (1 << i))
            continue;
        if (cnt == 0 || l == arr[i].front() - 'A')
            ret = max(ret, (int)arr[i].length() + solve(cnt + 1, s | (1 << i), arr[i].back() - 'A'));
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ret = solve(0, 0, 0);
    cout << ret;

    return 0;
}