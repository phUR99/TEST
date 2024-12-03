#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<vector<int>> commands;
int n, m;
map<vector<int>, int> dist;

int dijkstra(vector<int> arr)
{
    vector<int> start(arr);
    priority_queue<pair<int, vector<int>>> pq;

    sort(start.begin(), start.end());
    dist[start] = 0;

    pq.push({0, start});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int cost = -cur.first;
        auto here = cur.second;
        if (dist[here] < cost)
            continue;
        for (int i = 0; i < m; i++)
        {
            int l = commands[i][0];
            int r = commands[i][1];
            int c = commands[i][2];
            swap(here[l], here[r]);
            if (dist.count(here))
            {
                if (cost + c < dist[here])
                {
                    dist[here] = cost + c;
                    pq.push({-dist[here], here});
                }
            }
            else
            {
                dist[here] = cost + c;
                pq.push({-dist[here], here});
            }
            swap(here[l], here[r]);
        }
    }
    if (dist.count(arr))
        return dist[arr];
    return -1;
}

int main()
{
    fastio;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
        l--;
        r--;
        commands.push_back({l, r, c});
    }
    int ret = dijkstra(arr);
    cout << ret;
    return 0;
}