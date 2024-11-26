#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
정점의 용량을 어떻게 줄 것인가??
그래프 모델링
- 정점에 용량을 부여하는 방식 대신에 정점을 들어가는 지점과 나가는 지점 두 가지로 구분하여
들어가는 지점 -> 나가는 지점에 간선을 생성하고 그 간선에 용량을 1로 부여
*/
int capacity[805][805], flow[805][805];
int parent[805];
int n, p;
int networkFlow(int src, int sink)
{
    int totalFlow = 0;
    while (1)
    {
        memset(parent, -1, sizeof(parent));
        queue<int> q;
        q.push(src);
        parent[src] = src;
        while (!q.empty() && parent[sink] == -1)
        {
            int here = q.front();
            q.pop();
            for (int there = 1; there <= n * 2; there++)
            {
                if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
                {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        if (parent[sink] == -1)
            break;
        int amount = 987654321;
        for (int p = sink; p != src; p = parent[p])
        {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }
        for (int p = sink; p != src; p = parent[p])
        {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}

int main()
{
    fastio;
    cin >> n >> p;
    for (int i = 0; i < p; i++)
    {
        int a, b;
        cin >> a >> b;
        int a_out = a + n;
        int b_out = b + n;
        capacity[a_out][b]++;
        capacity[b_out][a]++;
    }
    for (int i = 1; i <= n; i++)
    {
        capacity[i][i + n] = 1;
    }
    capacity[1][1 + n] = 987654321;
    capacity[2][2 + n] = 987654321;
    int ret = networkFlow(1, 2 + n);
    cout << ret << '\n';
    return 0;
}