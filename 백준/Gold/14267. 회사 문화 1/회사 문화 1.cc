#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int n, m;

vector<int> tree[100'005];
int score[100'005];

int main(){
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int parent;
        cin >> parent;
        if(parent == -1) continue;
        tree[parent].push_back(i);
    }
    while (m--)
    {
        int i, w;
        cin >> i >> w;        
        score[i] += w;    
    }
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        auto parent = q.front(); q.pop();
        for (auto child : tree[parent])
        {
            score[child] += score[parent];
            q.push(child);
        }                
    }
    for (int i = 1; i <= n; i++)
    {
        cout << score[i] << ' ';
    }
    
    
    return 0;
}