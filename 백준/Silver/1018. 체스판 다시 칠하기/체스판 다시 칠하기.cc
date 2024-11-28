#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
char board[55][55];

int solve(char c, int x, int y)
{
    int ret = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0 && board[x + i][y + j] != c)
                    ret++;
                if (j % 2 == 1 && board[x + i][y + j] == c)
                    ret++;
            }
            else
            {
                if (j % 2 == 0 && board[x + i][y + j] == c)
                    ret++;
                if (j % 2 == 1 && board[x + i][y + j] != c)
                    ret++;
            }
        }
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    int ret = 987654321;
    for (int i = 0; i + 7 < n; i++)
    {
        for (int j = 0; j + 7 < m; j++)
        {
            ret = min({ret, solve('B', i, j), solve('W', i, j)});
        }
    }
    cout << ret;
    return 0;
}