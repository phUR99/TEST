#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
/*
작은 집합을 큰 집합에 합치는 테크닉 O(NlogN) * 동일 원소 탐색 O(logN) -> O(NlogN^2)로 처리 가능
제거하는 것보다 추가하면서 생각하는 것이 유리하니까 오프라인 쿼리로 진행
*/
int n, q;
int parent[100005];
int state[100005];
set<int> color_pos[100005];

int find(int u){
    if(state[u] == u) return u;
    return state[u] = find(state[u]);
}
void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return;
    if(color_pos[u].size() >= color_pos[v].size()) swap(u, v);
    state[u] = v;
    for (auto &e : color_pos[u])
    {
        color_pos[v].insert(e);
    }
    color_pos[u].clear();  
}

int main(){
    fastio;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        cin >> parent[i];
        state[i] = i;
    }
    state[1] = 1; parent[1] = 1;
    int color;
    for (int i = 1; i <= n; i++)
    {
        cin >> color;
        color_pos[i].insert(color);
    }
    vector<vector<int>> query;
    int a, b;
    for (int i = 0; i < n +q -1; i++)
    {
        cin >> a >> b;
        query.push_back({a, b});
    }
    reverse(query.begin(), query.end());
    vector<int> answer;
    for (auto &cur : query)
    {
        if(cur[0] == 1){
            int c = cur[1];             
            int p = parent[c];
            merge(c, p);          
        }
        else{
            int c = find(cur[1]);
            answer.push_back(color_pos[c].size());
        }
    }
    reverse(answer.begin(), answer.end());
    for (auto &ans : answer)
    {
        cout << ans << '\n';
    }
    

    return 0;
}