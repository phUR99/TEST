#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second

int v, e, st;
//비용, #정점
vector<pair<int, int>> adj[20'005];
const int INF = 1e9 + 10;
//최단 거리 테이블
int d[20'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e >> st;
    //INF으로 거리 테이블을 채워줌
    fill(d, d + v + 1, INF);
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        //가중치, 정점으로 그래프를 만들어줌
        adj[u].push_back({ w, v });

    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //시작할 점의 값을 0으로
    d[st] = 0;
    //거리, 시작점의 값으로 우선순위 큐를 만들어줌
    pq.push({ d[st], st });
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        //우선순위 큐의 top의 원소의 거리와 최단거리 테이블에서 찾아온 원소의 테이블이랑 일치하지 않으면 버린다.
        if (d[cur.Y] != cur.X) continue;
        //기준 정점에서 갈 수 있는 원소들을 모두 체크한다.
        for (auto nxt : adj[cur.Y])
        {
            // 테이블에서 찾아온 값이 원소의 가중치 + 현재 정점보다 클 경우만 값을 갱신해준다.
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            // 다시 그 값을 우선순위 큐에 넣어준다.
            pq.push({ d[nxt.Y], nxt.Y });
        }
    }
    for (int i = 1; i <= v; i++)
    {
        if (d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }
}
