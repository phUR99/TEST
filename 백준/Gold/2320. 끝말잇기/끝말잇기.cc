#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
string arr[20];
int n;
int cache[1 << 16][26];
int solve(int s, int l)
{
    if (s == (1 << n) - 1)
        return 0;
    int &ret = cache[s][l];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (s & (1 << i))
            continue;
        if (s == 0 || l == arr[i].front() - 'A')
            ret = max(ret, (int)arr[i].length() + solve(s | (1 << i), arr[i].back() - 'A'));
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
    int ret = solve(0, 0);
    cout << ret;

    return 0;
}