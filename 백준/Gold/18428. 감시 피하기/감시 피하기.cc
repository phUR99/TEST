#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
char board[10][10];
int n;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool canHide()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'T')
            {
                for (int dir = 0; dir < 4; dir++)
                {
                    for (int nn = 1; nn <= n; nn++)
                    {
                        int nx = i + nn * dx[dir];
                        int ny = j + nn * dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            break;
                        if (board[nx][ny] == 'O')
                            break;
                        if (board[nx][ny] == 'S')
                            return false;
                    }
                }
            }
        }
    }
    return true;
}
void solve()
{
    int maxCnt = n * n * n * n * n * n;

    for (int i = 0; i < maxCnt; i++)
    {
        int first = i / (n * n * n * n);
        int scond = i % (n * n * n * n) / (n * n);
        int third = i % (n * n);
        if (first == scond || scond == third || third == first)
            continue;
        int fx = first / n;
        int fy = first % n;
        int sx = scond / n;
        int sy = scond % n;
        int tx = third / n;
        int ty = third % n;
        if (board[fx][fy] != 'X' || board[sx][sy] != 'X' || board[tx][ty] != 'X')
            continue;
        board[fx][fy] = 'O';
        board[sx][sy] = 'O';
        board[tx][ty] = 'O';
        if (canHide())
        {
            cout << "YES\n";
            return;
        }
        board[fx][fy] = 'X';
        board[sx][sy] = 'X';
        board[tx][ty] = 'X';
    }
    cout << "NO\n";
    return;
}

int main()
{
    fastio;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    solve();

    return 0;
}