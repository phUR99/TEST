#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
int arr[55];
int dist[1005];
int dist2[1005];
void bfs()
{
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    dist2[0] = 0;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        int there = here * 2;

        if (there <= 1000 && dist[there] == -1)
        {
            q.push(there);
            dist[there] = dist[here] + 1;
            dist2[there] = dist2[here];
        }
        there = here + 1;
        if (there <= 1000 && dist[there] == -1)
        {
            q.push(there);
            dist[there] = dist[here];
            dist2[there] = dist2[here] + 1;
        }
    }
}

int main()
{
    fastio;
    cin >> n;
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bfs();
    int two_count = -1;
    for (int i = 0; i < n; i++)
    {
        two_count = max(two_count, dist[arr[i]]);
    }
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += dist2[arr[i]];
    }
    cout << ret + two_count;

    return 0;
}