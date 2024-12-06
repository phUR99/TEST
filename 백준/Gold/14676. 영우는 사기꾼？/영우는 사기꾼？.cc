#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<vector<int>> adj;
int n, m, k;
int indegree[100005];
int cnt[100005];
bool solve(vector<pair<int, int>> &arr)
{
    for (auto &i : arr)
    {
        int command = i.first;
        int element = i.second;
        if (command == 1)
        {
            if (indegree[element] != 0)
                return false;
            for (int &there : adj[element])
            {
                if (cnt[element] == 0)
                    indegree[there]--;
            }
            cnt[element]++;
        }
        else
        {
            if (cnt[element] == 0)
                return false;
            cnt[element]--;
            for (int &there : adj[element])
            {
                if (cnt[element] == 0)
                    indegree[there]++;
            }
        }
    }
    return true;
}

int main()
{
    fastio;
    cin >> n >> m >> k;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    vector<pair<int, int>> arr(k);
    for (auto &i : arr)
    {
        cin >> i.first >> i.second;
    }
    if (solve(arr))
        cout << "King-God-Emperor";
    else
        cout << "Lier!";
    return 0;
}