#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int N, M;
vector<pair<int, pair<int, int>>> arr;

int parent[1005];
int cnt;
int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return;
    if(u < v) swap(u, v);
    parent[u] = v;
}
bool isParentSame(int u, int v){
    return find(u) == find(v);
}
void init(){
    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }
    cnt = 0;
}

int main(){
    fastio;
    cin >> N >> M;
    int u,v,c;
    for (int i = 0; i < M + 1; i++)
    {
        cin >> u >> v >> c;  
        arr.push_back({1-c, {u, v}});
    }
    init();
    sort(arr.begin(), arr.end());
    int best = 0;
    int worst = 0;
    for (auto cur : arr)
    {
        if(isParentSame(cur.second.first, cur.second.second)) continue;
        else{
            merge(cur.second.first, cur.second.second);
            best += cur.first;
            cnt++;
        }
        if(cnt==N) break;
    }
    best= best * best;
    init();
    sort(arr.begin(), arr.end(), greater<>());

    for (auto cur : arr)
    {
        if(isParentSame(cur.second.first, cur.second.second)) continue;
        else{
            merge(cur.second.first, cur.second.second);

            worst += cur.first;
            cnt++;
        }
        if(cnt==N) break;
    }
    worst = worst * worst;
    cout << worst - best;

    return 0;
}