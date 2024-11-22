#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<pair<int, int>> clauses;
vector<vector<int>> adj;
int n, m;

void makeLine(int l, int r)
{
    int l_true = (l < 0) ? (abs(l) - 1) * 2 + 1 : (abs(l) - 1) * 2;
    int l_false = l_true ^ 1;
    int r_true = (r < 0) ? (abs(r) - 1) * 2 + 1 : (abs(r) - 1) * 2;
    int r_false = r_true ^ 1;
    adj[l_false].push_back(r_true);
    adj[r_false].push_back(l_true);
}

void makeGraph(const vector<pair<int, int>> &clauses)
{
    adj.resize(2 * m);
    for (auto &clause : clauses)
    {
        makeLine(clause.first, clause.second);
    }
}
vector<int> discovered, group;
int counter = 0, sccCounter = 0;
stack<int> s;
int dfs(int here);

vector<int> SCC()
{
    int n = adj.size();
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
    for (auto there : adj[here])
    {
        if (discovered[there] == -1)
            ret = min(ret, dfs(there));
        else if (group[there] == -1)
            ret = min(ret, discovered[there]);
    }
    if (ret == discovered[here])
    {
        while (1)
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

int main()
{
    fastio;
    cin >> n >> m;
    clauses.resize(n);
    for (auto &clause : clauses)
    {
        cin >> clause.first >> clause.second;
    }
    makeGraph(clauses);
    vector<int> ret = SCC();
    for (int i = 0; i < adj.size(); i += 2)
    {
        if (group[i] == group[i + 1])
        {
            cout << "OTL\n";
            return 0;
        }
    }
    cout << "^_^\n";
    return 0;
}