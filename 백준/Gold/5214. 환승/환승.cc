 #include <bits/stdc++.h>
//idea: 모든 간선을 잇는 그래프를 만들기 위해서는 o(n^3) 으로 시간초과 불가능
//처음에 생각했던 벡터의 벡터행렬을 만들어서 해결하는 것은 메모리 사용이 너무 커서 불가능
// ->하이퍼튜브의 정점을 새로 파서 만들어준다. 이렇게 하면 n^2에 해결 가능
// 다만 하이퍼튜브를 거쳐서 가는 방식은 정점을 하나 더 거처가야 하기 때문에 1 2 3 에서 1 -> 3으로 가고 싶을 경우 1 -> 4 -> 3으로 거쳐야 하는 역의 수가 2배가 된다.
// 따라서 결과 값을 확인한 다음에 그 값을 /2 해준 후 +1을 해준다(자기 자신)
// 예시 1번: 10 -> 3 -> 11 -> 6 -> 12 -> 9 = 6
// 하이퍼튜브를 거쳐가는 것이 항상 최적의 해를 보장하는 것을 확인할 수 있다.
using namespace std;
#define ll long long
#define X first
#define Y second
int n, k, m;

vector<int> adj[101'005];
int dist[101'005];

void dfs(int st) {
    queue<int> q;
    q.push(st);
    dist[st] = 0;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) {
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    fill(dist + 1, dist + n +m+ 1, -1);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            //하이퍼튜브를 새로운 정점으로 생각한다. o(n^2)로 해결 가능
            adj[n+i].push_back(x);
            adj[x].push_back(n +i);
        }
    }
    dfs(1);
    if (dist[n] == -1) cout << dist[n];
    else cout << dist[n] / 2 + 1;
}
