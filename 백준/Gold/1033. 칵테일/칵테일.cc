#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
long long A = 1;
long long gcd(long long a, long long b){
    if(b==0) return a;
    return  gcd(b, a % b);
}
bool visited[10];
long long arr[10];

struct node{
    int to;
    long long m, d;
};

vector<node> adj[10];
int N;

int main(){
    fastio;
    cin >> N;
    for (int i = 0; i < N-1; i++)
    {
        int f, t, m, d;
        cin >> f >> t >> m >> d;
        long long mod = gcd(m, d);
        m /= mod; d /= mod;
        A *= m * d;
        adj[f].push_back({t, d, m});
        adj[t].push_back({f, m, d});
    }
    queue<pair<int, long long>> q;
    q.push({0, A});
    visited[0] = true;
    arr[0] = A;
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (auto nxt : adj[cur.first])
        {
            if(visited[nxt.to]) continue;
            arr[nxt.to] = (arr[cur.first] / nxt.d) * nxt.m;
            q.push({nxt.to, arr[nxt.to]});
            visited[nxt.to] = true;
        }        
    }
    for (int i = 0; i < N; i++)
    {
        A = gcd(A, arr[i]);
    };
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] / A << ' ';
    }

    return 0;
}