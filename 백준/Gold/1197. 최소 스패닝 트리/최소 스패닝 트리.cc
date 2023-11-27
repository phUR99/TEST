#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second

int v, e;
// {비용, #정점}
vector<pair<int, int>> adj[10005];
// chk[i] : i번째 정점이 최소 신장 트리에 속해있는가?
bool chk[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> v >> e;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < e; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({ cost, b });
        adj[b].push_back({ cost, a });
    }
    //minHeap이 필요하므로 (비용, 정점1, 정점2)의 형태로
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    //임의의 점 1을 선택하고 1과 연결되어있는 간선들을 넣어줌
    chk[1] = 1;
    for (auto nxt : adj[1])
    {

        pq.push({ nxt.X, 1, nxt.Y });
    }
    //간선의 개수가 v-1일 때까지 센다
    while (cnt < v - 1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (chk[b]) continue;
        ans += cost;
        //최소 신장 트리에 포함된 정점인지 아닌지를 확인하기 위해서는 b의 값만 체크해주면 됨
        chk[b] = 1;
        cnt++;
        //정점 b로 욺긴 뒤에
        for (auto nxt : adj[b])
        {
            //그룹에 속하지 않은 정점들을 체크하고 그 값을 우선순위 큐에 넣어줌
            //단순히 간선의 가중치의 합만이 필요하다면 (cost, 정점)의 형태로 선언해줘도 됨
            if (!chk[nxt.Y]) pq.push({ nxt.X, b, nxt.Y });
        }
    }
    cout << ans;
}