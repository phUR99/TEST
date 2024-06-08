#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

long long dist[100005];
const long long inf = 0x7fffffffffffffff;

vector<pair<int, long long>> adj[100005];
struct node
{
    int to;
    long long cost;
    bool operator< (const node &a) const {
        return a.cost < cost;
    }
};
priority_queue<node> pq;
int n;
long long m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int from ,to;
        cin >> from >> to;
        adj[from].push_back({to, i+1});
        adj[to].push_back({from, i+1});
    }    
    fill(dist+1, dist+100005, inf);
    dist[1] = 0;
    pq.push({1, 0});

    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.to] < cur.cost) continue;
        for (auto nxt : adj[cur.to])
        {
            long long cost = nxt.second;
            /*
            while (cur.cost >= cost)
            {
                cost += m;
            }  
            */
           cost += (cur.cost/m + (cur.cost % m > nxt.second))*m;

            if(dist[nxt.first] > cost){
                dist[nxt.first] = cost;
                pq.push({nxt.first, cost});
            }
        }
        
    }
    cout << dist[n];


    return 0;    
}