#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N;
priority_queue<pair<int, int>> pq;

int main(){
    fastio;
    int cur = 0x7fffffff;
    cin >> N;
    int need, end;

    while (N--)
    {
        cin >> need >>  end;
        pq.push({end, need});
    }
    while (!pq.empty())
    {
        auto tmp = pq.top(); pq.pop();
        cur = min(cur, tmp.first); 
        cur -= tmp.second;
    }
    if( cur < 0 )cout << -1;
    else cout << cur;
    return 0;
}