#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
map<int, int> dist;

int main()
{
    fastio;
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        dist[tmp] = 0;
        q.push(tmp);
    }
    int cnt = 0;
    ll ret = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (pq.size() < k)
    {
        int here = q.front(); q.pop();
        int there;
        there = here - 1;
        if(!dist.count(there)){
            dist[there] = dist[here] + 1;
            q.push(there);
            pq.push(dist[there]);
        }
        there = here + 1;
        if(!dist.count(there)){
            dist[there] = dist[here] + 1;
            q.push(there);
            pq.push(dist[there]);
        }
    }
    while (k--)
    {
        ret += pq.top(); pq.pop();
    }
    cout << ret;
    
    
    return 0;
}