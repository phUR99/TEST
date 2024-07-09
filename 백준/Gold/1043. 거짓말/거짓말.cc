#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int N, M, T;
bool truth[52];
vector<int> party[52];
int parent[52];

int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return;
    if(truth[u] || truth[v]){
        truth[u] = 1;
        truth[v] = 1;
    }
    parent[u] = v;    
}
int solution(vector<int> &P){
    for (auto p : P){
        if(truth[find(p)]) return 0;
    }
    return 1;
}

int main(){
    fastio;
    cin >> N >> M >> T;
    int n, t;
    while (T--)
    {        
        cin >> t;
        truth[t] = true;
    }
    int answer = 0;
    for (int j = 0; j <= N; j++)
    {
        parent[j] = j;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> n;                                
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            party[i].push_back(tmp);
        }
        for (int j = 0; j < n-1; j++)
        {
            merge(party[i][j], party[i][j+1]);
        }                               
    }
    for (int i = 0; i < M; i++)
    {
        answer += solution(party[i]);        
    }
    cout << answer;

    return 0;
}