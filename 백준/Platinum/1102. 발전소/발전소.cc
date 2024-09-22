#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;

int board[16][16];
int cache[(1 << 16)];
int n;
string str;
int p;

int returnCnt(int state)
{
    int ret = 0;
    for (int i = 0; i < 31; i++)
    {
        if (state & (1 << i))
            ret++;
    }
    return ret;
}
int solve(int state)
{
    if (returnCnt(state) >= p)
        return 0;
    int &ret = cache[state];
    if (ret != -1)
        return ret;
    ret = 987654321;
    for (int i = 0; i < n; i++)
    {
        if ((state & (1 << i)) == 0)
            continue;
        for (int j = 0; j < n; j++)
        {
            if (state & (1 << j))
                continue;
            ret = min(ret, solve(state | (1 << j)) + board[i][j]);
        }
    }
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    cin >> str;
    cin >> p;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'Y')
            cur |= (1 << i);
    }
    int answer = solve(cur);
    if (answer == 987654321)
        cout << -1;
    else
        cout << answer;

    return 0;
}