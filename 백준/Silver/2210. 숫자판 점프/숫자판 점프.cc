#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[5][5];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
set<int> dict;

void dfs(int x, int y, int cnt, string &tmp)
{
    if (cnt == 5)
    {
        dict.insert(stoi(tmp));
        return;
    }
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
            continue;
        tmp += arr[nx][ny] + '0';
        dfs(nx, ny, cnt + 1, tmp);
        tmp.pop_back();
    }
}

int main()
{
    fastio;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }
    string cur = string();
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cur += arr[i][j] + '0';
            dfs(i, j, 0, cur);
            cur.pop_back();
        }
    }
    cout << dict.size();
    return 0;
}