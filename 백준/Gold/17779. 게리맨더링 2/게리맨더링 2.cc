#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int board[25][25];

int n;
bool oob(int x, int y)
{
    return x < 1 || x > n || y < 1 || y > n;
}

int solve(int x, int y, pair<int, int> d)
{
    int d1 = d.first;
    int d2 = d.second;

    bool visited[25][25];
    memset(visited, 0, sizeof(visited));
    vector<int> element(5, 0);
    for (int i = 0; i < d1; i++)
    {
        x += 1;
        y -= 1;
        if (oob(x, y))
            return 987654321;
        visited[x][y] = true;
    }
    for (int i = 0; i < d2; i++)
    {
        x += 1;
        y += 1;
        if (oob(x, y))
            return 987654321;
        visited[x][y] = true;
    }
    for (int i = 0; i < d1; i++)
    {
        x -= 1;
        y += 1;
        if (oob(x, y))
            return 987654321;
        visited[x][y] = true;
    }
    for (int i = 0; i < d2; i++)
    {
        x -= 1;
        y -= 1;
        if (oob(x, y))
            return 987654321;
        visited[x][y] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        vector<pair<int, int>> arr;
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (cnt == 1)
                arr.push_back({i, j});
            if (visited[i][j])
                cnt++;
        }
        if (cnt != 2)
            continue;
        for (auto e : arr)
        {
            int xx = e.first;
            int yy = e.second;
            visited[xx][yy] = true;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (visited[i][j])
            {
                element[4] += board[i][j];
            }
        }
    }

    for (int i = 1; i < x + d1; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (visited[i][j])
                break;
            element[0] += board[i][j];
        }
    }
    for (int i = 1; i <= x + d2; i++)
    {
        int tmp = 0;
        for (int j = y + 1; j <= n; j++)
        {
            if (visited[i][j])
                continue;
            element[1] += board[i][j];
        }
    }
    for (int i = x + d1; i <= n; i++)
    {
        for (int j = 1; j < y - d1 + d2; j++)
        {
            if (visited[i][j])
                break;
            element[2] += board[i][j];
        }
    }
    for (int i = x + d2 + 1; i <= n; i++)
    {
        int tmp = 0;
        for (int j = y - d1 + d2; j <= n; j++)
        {
            if (visited[i][j])
                continue;
            element[3] += board[i][j];
        }
    }
    int m = *min_element(element.begin(), element.end());
    int M = *max_element(element.begin(), element.end());
    return M - m;
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
        }
    }
    vector<pair<int, int>> d1d2;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            d1d2.push_back({i, j});
        }
    }
    int answer = 987654321;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (auto d : d1d2)
            {
                answer = min(answer, solve(i, j, d));
            }
        }
    }
    cout << answer;
    return 0;
}