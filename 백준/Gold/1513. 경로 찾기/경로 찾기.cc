#include <bits/stdc++.h>
using namespace std;
bool isGame[51][51];
int cache[51][51][51][51];

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int N, M, C;
int cnt;
map<pair<int, int>, int> idx;

int solve(int x, int y, int now, int pre)
{
    if (x > N || y > M)
        return 0;
    if (now > cnt)
        return 0;
    if (isGame[x][y])
    {
        if (idx[{x, y}] < pre)
            return 0;
        now++;
        pre = idx[{x, y}];
    }

    if (x == N && y == M)
    {
        if (now == cnt)
            return 1;
        else
            return 0;
    }
    int &ret = cache[x][y][now][pre];
    if (ret != -1)
        return ret;
    ret = 0;
    ret += solve(x + 1, y, now, pre) + solve(x, y + 1, now, pre);
    ret %= 1'000'007;
    return ret;
}

int main()
{
    fastio;
    cin >> N >> M >> C;
    int u, v;
    for (int i = 0; i < C; i++)
    {
        cin >> u >> v;
        isGame[u][v] = true;
        idx[{u, v}] = i + 1;
    }
    for (int i = 0; i <= C; i++)
    {
        cnt = i;
        memset(cache, -1, sizeof(cache));
        cout << solve(1, 1, 0, 0) << ' ';
    }

    return 0;
}