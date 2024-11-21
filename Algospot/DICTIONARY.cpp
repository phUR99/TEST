#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
void solve()
{
    int n;
    cin >> n;
    vector<int> indegree(26, 0);
    vector<vector<int>> adj(26);
    vector<string> strings(n);
    for (auto &s : strings)
    {
        cin >> s;
    }
    for (int i = 0; i < n - 1; i++)
    {
        string cur = strings[i];
        string nxt = strings[i + 1];
        for (int j = 0; j < min(cur.size(), nxt.size()); j++)
        {
            if (cur[j] == nxt[j])
                continue;
            adj[cur[j] - 'a'].push_back(nxt[j] - 'a');
            indegree[nxt[j] - 'a']++;
            // break 구문을 안넣었음 -> 그래프 모델링 잘못되었음
            break;
        }
    }
    vector<char> answer;
    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        answer.push_back(cur + 'a');
        for (int nxt : adj[cur])
        {
            indegree[nxt]--;
            if (indegree[nxt] == 0)
                q.push(nxt);
        }
    }
    if (answer.size() < 26)
        cout << "INVALID HYPOTHESIS\n";
    else
    {
        for (auto &i : answer)
        {
            cout << i;
        }
        cout << '\n';
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