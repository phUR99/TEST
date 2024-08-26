#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
vector<vector<int>> tree;
int N;
int cost[150000];
bool visited[150000];
long long solve(int cur)
{
    long long ret = cost[cur];
    visited[cur] = true;
    for (auto nxt : tree[cur])
    {
        if (visited[nxt])
            continue;
        ret += solve(nxt);
    }
    return max(ret, 0LL);
}
int main()
{
    fastio;
    cin >> N;
    tree.resize(N + 1);
    char c;
    int w, p;

    for (int i = 2; i <= N; i++)
    {
        cin >> c >> w >> p;
        if (c == 'W')
            w = -w;
        cost[i] = w;
        tree[p].push_back(i);
        tree[i].push_back(p);
    }
    long long answer = solve(1);
    cout << answer;

    return 0;
}