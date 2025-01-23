#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int board[1005][1005];
int n, m;
int group[1005][1005];
bool visited[1005][1005];
int counter = 0;
vector<int> numbers(1, 0);
void bfs(int x, int y)
{
    visited[x][y] = 1;
    group[x][y] = ++counter;
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = now.first + dx[dir];
            int ny = now.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (visited[nx][ny] || board[nx][ny] == 0)
                continue;
            visited[nx][ny] = 1;
            group[nx][ny] = counter;
            cnt++;
            q.push({nx, ny});
        }
    }
    numbers.push_back(cnt);
    return;
}
int solve(int x, int y)
{
    set<int> grouped;
    vector<int> arr;
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (grouped.count(group[nx][ny]))
            continue;
        grouped.insert(group[nx][ny]);
        arr.push_back(numbers[group[nx][ny]]);
    }
    return accumulate(arr.begin(), arr.end(), 1);
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && board[i][j] == 1)
                bfs(i, j);
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
                ret = max(ret, solve(i, j));
        }
    }
    cout << ret;
    return 0;
}