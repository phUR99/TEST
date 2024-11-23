#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
1. 그래프 구성이 가장 큰 난관
정점은 어떻게 ? A-B의 차이
간선은 어떻게 ? 정점을 차이로, 가중치를 A의 값으로
0부터 시작해서 0으로 다시 들어오는 최단경로를 계산하기(임의의 다른 0을 하나 두기)
-> 그래프의 크기를 얼마만큼 잡아야함?
(1, 200) (200, 1) 이므로 최대 200까지는 잡아야함, 그보다 더 큰 값에 대해서는 가는 것이 항상 손해이므로
더 잡을 필요가 없음(어차피 양수 간선을 써야 하는데 미리 땡겨오는 개념으로)
*/
const int V = 400 + 2;
const int S = 400 + 1;
int dist[V];
vector<vector<pair<int, int>>> adj;
vector<int> A, B;
int vertex(int diff)
{
    return 200 + diff;
}
int dijkstra(int s)
{
    dist[s] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int cost = -cur.first;
        int here = cur.second;
        if (dist[here] < cost)
            continue;
        for (auto nxt : adj[here])
        {
            int nCost = nxt.first;
            int there = nxt.second;
            if (nCost + cost < dist[there])
            {
                dist[there] = nCost + cost;
                pq.push({-dist[there], there});
            }
        }
    }
    return dist[vertex(0)];
}

void solve()
{
    adj.clear();
    adj.resize(V);
    memset(dist, 0x3f, sizeof(dist));
    int n;
    cin >> n;
    A.clear();
    B.clear();
    A.resize(n);
    B.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i] >> B[i];
    }
    // S는 시작점의 0
    // 방향 그래프 구성하기
    for (int i = 0; i < n; i++)
    {
        int diff = A[i] - B[i];
        adj[S].push_back({A[i], vertex(diff)});
    }
    for (int diff = -200; diff <= 200; diff++)
    {
        for (int i = 0; i < n; i++)
        {
            int there = diff + A[i] - B[i];
            if (abs(there) > 200)
                continue;
            adj[vertex(diff)].push_back({A[i], vertex(there)});
        }
    }
    int ret = dijkstra(S);
    if (ret == 0x3f3f3f3f)
        cout << "IMPOSSIBLE\n";
    else
        cout << ret << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}