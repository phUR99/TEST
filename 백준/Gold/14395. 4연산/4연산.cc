#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
map<ll, ll> parent;
string bfs(int s, int t){
    string ret;
    queue<ll> q;
    q.push(s);
    parent[s] = -1;
    while (!q.empty())
    {   
        ll here = q.front(); q.pop();
        if(here * here <= t){
            ll there = here * here;
            if(!parent.count(there)){
                q.push(there);
                parent[there] = here;
            }
        }
        if(here * 2 <= t){
            ll there = here * 2;
            if(!parent.count(there)){
                q.push(there);
                parent[there] = here;
            }
        }
        if(!parent.count(0)){
            q.push(0);
            parent[0] = here;
        }
        if(!parent.count(1) && here){
            q.push(1);
            parent[1] = here;
        }
    }
    if(s == t) return string("0");
    if(!parent.count(t)) return string("-1");

    for (int i = t; parent[i] != -1; i = parent[i]){
        int p = parent[i];
        int c = i;
        if(p * p == c) ret += '*';        
        else if(p * 2 == c) ret += '+';
        else if(c == 0) ret += "-";
        else if(c == 1) ret += "/";
        
    }
    reverse(ret.begin(), ret.end());
    return ret;

}
int main()
{
    fastio;
    int s, t;
    cin >> s >> t;
    string ret = bfs(s, t);
    cout << ret;
    return 0;
}