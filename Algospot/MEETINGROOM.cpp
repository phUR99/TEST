#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<pair<int, int>> meetings;
vector<vector<int>> adj;

bool disjoint(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second <= b.first || b.second <= a.first;
}

void makeGraph(const vector<pair<int, int>> &meetings)
{
    int n = meetings.size();
    adj.clear();
    adj.resize(2 * n);
    // 둘 중에 하나만 선택하기 (P면 Q가 아니다. Q면 P가 아니다, P가 아니면 Q다. Q가 아니면 P다)
    // !i -> j
    // !j -> i
    for (int i = 0; i < n; i += 2)
    {
        int j = i + 1;
        adj[i * 2 + 1].push_back(j * 2);
        adj[j * 2 + 1].push_back(i * 2);
    }
    // i -> !j
    // j -> !i
    for (int i = 0; i < n; i += 2)
    {
        int j = i + 1;
        adj[i * 2].push_back(j * 2 + 1);
        adj[j * 2].push_back(i * 2 + 1);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // 겹치는 회의 제거
            // i -> !j
            // j -> !i
            if (!disjoint(meetings[i], meetings[j]))
            {
                adj[i * 2].push_back(j * 2 + 1);
                adj[j * 2].push_back(i * 2 + 1);
            }
        }
    }
}
int counter = 0;
int sccCounter = 0;
vector<int> discovered, group;
stack<int> s;
int dfs(int here);

vector<int> SCC()
{
    counter = sccCounter = 0;
    int n = adj.size();
    discovered.clear();
    group.clear();
    discovered.resize(n, -1);
    group.resize(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (discovered[i] == -1)
            dfs(i);
    }
    return group;
}
int dfs(int here)
{
    int ret = discovered[here] = counter++;
    s.push(here);
    for (int there : adj[here])
    {
        // 트리 간선이라면
        if (discovered[there] == -1)
        {
            ret = min(ret, dfs(there));
        }
        // 교차 간선이 아니거나 역방향 간선이라면
        else if (group[there] == -1)
            ret = min(ret, discovered[there]);
    }
    if (ret == discovered[here])
    {
        while (true)
        {
            int now = s.top();
            group[now] = sccCounter;
            s.pop();
            if (now == here)
                break;
        }
        sccCounter++;
    }
    return ret;
}

vector<int> solve2sat()
{
    int n = adj.size() / 2;
    vector<int> label = SCC();
    for (int i = 0; i < 2 * n; i += 2)
    {
        // i , !i가 같은 SCC에 묶여 있다면 답을 도출할 수 없다
        if (label[i] == label[i + 1])
            return vector<int>();
    }
    vector<int> value(n, -1);
    vector<pair<int, int>> order;
    for (int i = 0; i < 2 * n; i++)
    {
        order.push_back({-label[i], i});
    }
    // SCC의 역순서는 위상정렬의 순서임
    sort(order.begin(), order.end());
    for (int i = 0; i < 2 * n; i++)
    {
        int vertex = order[i].second;
        int var = vertex / 2, isTrue = vertex % 2 == 0;
        // !A가 A보다 먼저 나왔다면 A는 반드시 참
        // A가 !A보다 먼저 나왔다면 A는 반드시 거짓
        if (value[var] != -1)
            continue;
        value[var] = !isTrue;
    }
    return value;
}

void solve()
{
    int n;
    cin >> n;
    meetings.clear();
    meetings.resize(2 * n);
    for (auto &i : meetings)
    {
        cin >> i.first >> i.second;
    }
    makeGraph(meetings);

    vector<int> ret = solve2sat();
    if (ret.size() == 0)
        cout << "IMPOSSIBLE\n";
    else
    {
        cout << "POSSIBLE\n";
        for (int i = 0; i < ret.size(); i++)
        {
            if (ret[i])
                cout << meetings[i].first << ' ' << meetings[i].second << '\n';
        }
    }
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