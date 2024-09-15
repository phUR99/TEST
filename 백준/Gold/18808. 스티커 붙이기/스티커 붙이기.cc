#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int shape[105][15][15];
bool board[45][45];
int n, m, k;
int row[105], col[105];

bool check(int x, int y, int num)
{
    int r = row[num];
    int c = col[num];
    for (int i = 0; i < max(r, c); i++)
    {
        for (int j = 0; j < max(r, c); j++)
        {
            if (shape[num][i][j] == 0)
                continue;
            if (x + i >= n || y + j >= m || x + i < 0 || y + j < 0)
                return false;
            if (board[x + i][y + j])
                return false;
        }
    }
    for (int i = 0; i < max(r, c); i++)
    {
        for (int j = 0; j < max(r, c); j++)
        {
            board[x + i][y + j] |= shape[num][i][j];
        }
    }
    return true;
}

bool solve(int num)
{
    int r = row[num];
    int c = col[num];
    int l = max(r, c);
    for (int i = -l; i < n; i++)
    {
        for (int j = -l; j < m; j++)
        {
            if (check(i, j, num))
                return true;
        }
    }
    return false;
}

void rotate(int num)
{
    int r = row[num];
    int c = col[num];
    int l = max(r, c);
    int tmpBoard[15][15];
    memset(tmpBoard, 0, sizeof(tmpBoard));

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            tmpBoard[j][l - 1 - i] = shape[num][i][j];
        }
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            shape[num][i][j] = tmpBoard[i][j];
        }
    }
    swap(row[num], col[num]);
}

int main()
{
    fastio;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        row[i] = r;
        col[i] = c;
        for (int j = 0; j < r; j++)
        {
            for (int l = 0; l < c; l++)
            {
                cin >> shape[i][j][l];
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int t = 0; t < 4; t++)
        {
            if (solve(i))
            {
                break;
            }

            rotate(i);
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            answer += board[i][j];
        }
    }
    cout << answer;
    return 0;
}