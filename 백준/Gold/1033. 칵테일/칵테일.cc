#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
long long A = 1;
long long gcd(long long a, long long b){
    if(b==0) return a;
    return  gcd(b, a % b);
}
long long arr[10];
long long lcm(long long a, long long b){
    return a * b / gcd(a, b);
}

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
        A *= lcm(m ,d);
        adj[f].push_back({t, d, m});
        adj[t].push_back({f, m, d});
    }
    queue<int> q;
    q.push(0);
    arr[0] = A;
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (auto nxt : adj[cur])
        {
            if(arr[nxt.to]) continue;
            arr[nxt.to] = (arr[cur] / nxt.d) * nxt.m;
            q.push({nxt.to});            
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