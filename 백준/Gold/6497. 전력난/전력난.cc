#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int n, m;
vector<vector<int>> vertex;
int parent[200005];

int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return;

    parent[u] = v;    
}

int main(){
    fastio;
    while (true)
    {
        cin >> m >> n;
        if(n == 0 && m == 0) break;
        vertex.clear();
        for (int i = 0; i < m; i++)
        {
            parent[i] = i;
        }
        
        int answer = 0;
        int a, b, c;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b >> c;
            vertex.push_back({c, a, b});
            answer += c;
        }
        sort(vertex.begin(), vertex.end());
        for (int i = 0; i < n; i++)
        {
            int u = vertex[i][1];
            int v = vertex[i][2];
            u = find(u); v = find(v);
            if(u == v) continue;
            merge(u, v);
            answer -= vertex[i][0];
        }
        cout << answer << '\n';
    }
    

    return 0;
}