#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
/*
제거하는거보다 만드는게 유리
*/
#define MOD 1'000'000'000
int parent[100005];
int SIZE[100005];

int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return;
    if(SIZE[u] >= SIZE[v]) swap(u, v);
    parent[u] = v;
    SIZE[v] += SIZE[u];
    SIZE[u] = 0;
}
int n, m;
vector<vector<int>> arr;

bool cmp(vector<int> &a, vector<int> &b){
    return b[2] < a[2];
}

int main(){
    fastio;
    cin >> n >> m;
    arr.resize(m);
    long long wSum = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        SIZE[i] = 1;
    }
    
    for (int i = 0; i < m; i++)
    {
        arr[i].resize(3);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }       
        wSum += arr[i][2];
    }

    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < m; i++)
    {
        int u = find(arr[i][0]);
        int v = find(arr[i][1]);
        int w = arr[i][2];
        if(u != v) {
            long long s = (long long)SIZE[u] * (long long)SIZE[v] % MOD;
            ans += s * wSum;
            ans %= MOD;
            merge(u, v);   
        }
        wSum -= w;
     
    }
    cout << ans;
    return 0;
}