#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int main()
{
    fastio;
    string ed = "123456780";
    string st;
    for (int i = 0; i < 9; i++)
    {
        int a;
        cin >> a;
        st += a + '0';
    }
    unordered_map<string, int> dist;

    queue<string> q;
    q.push(st);
    dist[st] = 0;
    while (!q.empty())
    {
        auto here = q.front();
        int now = dist[here];
        q.pop();
        int i;
        for (i = 0; i < 9; i++)
        {
            if (here[i] == '0')
                break;
        }
        int x = i / 3;
        int y = i % 3;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
                continue;
            int j = nx * 3 + ny;
            swap(here[i], here[j]);
            if (!dist.count(here))
            {
                dist[here] = now + 1;
                q.push(here);
            }
            swap(here[i], here[j]);
        }
    }
    if (dist.count(ed))
        cout << dist[ed];
    else
        cout << -1;

    return 0;
}