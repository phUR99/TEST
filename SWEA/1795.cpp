#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define DIST first
#define EDGE second
using namespace std;
const int INF = 987654321;
int dist[1005], reverse_dist[1005];
int N, M, X;
vector<pair<int, int>> adj[1005], reverse_adj[1005];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
    int u, v, d;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> M >> X;
        fill(dist+1, dist+N+1, INF);
        fill(reverse_dist+1, reverse_dist+N+1, INF);
        for (int i = 1; i <= N; i++)
        {
            adj[i].clear();
            reverse_adj[i].clear();
        }
        for (int i = 0; i < M; i++)
        {
            cin >> u >> v >> d;
            adj[u].push_back({d, v});
            reverse_adj[v].push_back({d, u});
        }
        
        dist[X] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push({0, X});
        while (!pq.empty())
        {
            auto cur = pq.top(); pq.pop();
            if(-cur.DIST > dist[cur.EDGE]) continue;
            for (auto nxt : adj[cur.EDGE])
            {
                if(-cur.DIST + nxt.DIST < dist[nxt.EDGE]) {
                    dist[nxt.EDGE] = -cur.DIST + nxt.DIST;
                    pq.push({-dist[nxt.EDGE], nxt.EDGE});
                }
            }
            
        }
        reverse_dist[X] = 0;
        pq.push({0, X});
        while (!pq.empty())
        {
            auto cur = pq.top(); pq.pop();
            if(-cur.DIST > reverse_dist[cur.EDGE]) continue;
            for (auto nxt : reverse_adj[cur.EDGE])
            {
                if(-cur.DIST + nxt.DIST < reverse_dist[nxt.EDGE]) {
                    reverse_dist[nxt.EDGE] = -cur.DIST + nxt.DIST;
                    pq.push({-reverse_dist[nxt.EDGE], nxt.EDGE});
                }
            }
            
        }
        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            ans = max(ans, dist[i] + reverse_dist[i]);
        }
        cout << "#" << test_case << ' ';
        cout << ans << '\n';
	}
	return 0;
}