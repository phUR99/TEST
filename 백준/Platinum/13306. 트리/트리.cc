#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int n, q;
int parent[200005];
int state[200005];

int find(int u){
    if(state[u] == u) return u;
    return state[u] = find(state[u]);
}

int main(){
    fastio;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        state[i] = i;
    }
    parent[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> parent[i];
    }
    vector<vector<int>> query;
    int c , a, b;
    for (int i = 0; i < n-1+q; i++)
    {
        cin >> c;
        if(c == 1){
            cin >> a >> b;
            query.push_back({c, a, b});
        }
        else{
            cin >> a;
            query.push_back({c, a});
        }    
    }
    reverse(query.begin(), query.end());
    vector<char*> ans;

    for (auto &cur : query)
    {
        if(cur[0] == 1){
            int u = find(cur[1]);
            int v = find(cur[2]);
            if(u == v) ans.push_back("YES\n");
            else ans.push_back("NO\n");
        }
        else{
            int child = cur[1];
            state[child] = parent[child];
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto a : ans)
    {
        cout << a;
    }
    

    return 0;
}