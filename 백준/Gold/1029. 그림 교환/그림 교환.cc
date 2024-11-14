#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
int n;
int board[15][15];
int cache[15][10][1 << 15];
int maxNum(int index, int currentPrice, int state)
{
    int &ret = cache[index][currentPrice][state];
    if (ret != -1)
        return ret;
    ret = 1;
    for (int nxt = 0; nxt < n; nxt++)
    {

        if (state & (1 << nxt))
            continue;
        if (board[index][nxt] >= currentPrice)
        {
            int nxtstate = state | (1 << nxt);
            ret = max(ret, maxNum(nxt, board[index][nxt], nxtstate) + 1);
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
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    int ret = max(1, maxNum(0, 0, 1));
    cout << ret << '\n';
    return 0;
}