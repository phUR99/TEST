#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
int N, M;

int parent[1005];
vector<pair<double, pair<int, int>>> arr;

double dist(pair<ll, ll> a, pair<ll, ll> b){
    return sqrt(pow(a.first -b.first, 2)  + pow(b.second - a.second,2));
}

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

int main(){
    fastio;
    cin >> N >> M;
    vector<pair<ll, ll>> coordinate(N+1);
    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> coordinate[i].first >> coordinate[i].second;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = i+1; j <= N; j++)
        {
            arr.push_back({dist(coordinate[i], coordinate[j]), {i, j}});
        }
        
    }
    int u, v;
    int cnt = 0;

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        if(isParentSame(u ,v)) continue;
        merge(u, v);
        cnt++;
    }
    sort(arr.begin(), arr.end());

    double ans = 0;
    for (auto cur : arr)
    {
        if(isParentSame(cur.second.first, cur.second.second)) continue;
        merge(cur.second.first, cur.second.second);
        ans += cur.first;
        cnt++;
        if(cnt == N) break;
    }
    cout << fixed;    
    cout.precision(2);
    cout << ans;

    return 0;
}