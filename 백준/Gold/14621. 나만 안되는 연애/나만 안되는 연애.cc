#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int N, M;
bool state[1005];
vector<vector<int>> arr;
int parent[1005];
int find(int u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    parent[u] = v;
}

int main()
{
    fastio;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        char c;
        cin >> c;
        if (c == 'W')
            state[i] = true;
        parent[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int c, u, v;
        cin >> u >> v >> c;
        if (state[u] == state[v])
            continue;
        arr.push_back({c, u, v});
    }
    int cnt = 0;
    int answer = 0;
    sort(arr.begin(), arr.end());
    for (auto a : arr)
    {
        int c = a[0];
        int u = a[1];
        int v = a[2];
        if (find(u) != find(v))
        {
            merge(u, v);
            cnt++;
            answer += c;
        }
    }
    if (cnt == N - 1)
    {
        cout << answer;
    }
    else
        cout << -1;
    return 0;
}