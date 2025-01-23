#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[1005];
int n;

int bfs()
{
    vector<int> dist(n, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        int power = arr[here];
        for (int i = 1; i <= power; i++)
        {
            int nx = here + i;
            if (nx >= n)
                continue;
            if (dist[nx] == -1)
            {
                dist[nx] = dist[here] + 1;
                q.push(nx);
            }
        }
    }
    return dist[n - 1];
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ret = bfs();
    cout << ret;
    return 0;
}