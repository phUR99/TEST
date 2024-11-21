#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int indegree[26];
int outdegree[26];
int cnt[26][26];

vector<string> adj[26][26];
bool checkEuler()
{
    int in = 0;
    int out = 0;
    for (int i = 0; i < 26; i++)
    {
        int diff = outdegree[i] - indegree[i];
        if (diff < -1 || diff > 1)
            return false;
        if (diff == 1)
            out++;
        if (diff == -1)
            in++;
    }
    return (in == 1 && out == 1) || (in == 0 && out == 0);
}
void getCircuit(int here, vector<int> &ret)
{
    for (int there = 0; there < 26; there++)
    {
        while (cnt[here][there] > 0)
        {
            cnt[here][there]--;
            getCircuit(there, ret);
        }
    }
    ret.push_back(here);
}

vector<int> solution()
{
    vector<int> ret;
    for (int i = 0; i < 26; i++)
    {
        if (outdegree[i] == indegree[i] + 1)
        {
            getCircuit(i, ret);
            return ret;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (outdegree[i])
        {
            getCircuit(i, ret);
            return ret;
        }
    }
}

void solve()
{
    memset(indegree, 0, sizeof(indegree));
    memset(outdegree, 0, sizeof(outdegree));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            adj[i][j].clear();
        }
    }

    int n;
    cin >> n;
    vector<string> words(n);
    for (string &w : words)
    {
        cin >> w;
        int f = w.front() - 'a';
        int b = w.back() - 'a';
        outdegree[f]++;
        indegree[b]++;
        adj[f][b].push_back(w);
        cnt[f][b]++;
    }
    if (!checkEuler())
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> answer = solution();
    if (answer.size() != words.size() + 1)
    {
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    reverse(answer.begin(), answer.end());

    vector<string> ret;
    for (int i = 1; i < answer.size(); i++)
    {
        int a = answer[i - 1];
        int b = answer[i];

        ret.push_back(adj[a][b].back());
        adj[a][b].pop_back();
    }
    for (auto &i : ret)
    {
        cout << i << ' ';
    }
    cout << '\n';
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