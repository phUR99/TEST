#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


int T, N;
pair<int, int> st, ed;
vector<pair<int, int>> store;      
vector<bool> visited;

string bfs(){
    queue<pair<int, int>> q;
    q.push(st);
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        if(abs(cur.first - ed.first) + abs(cur.second - ed.second) <= 1000) return "happy";
        for (int i = 0; i < N; i++)
        {
            if(visited[i]) continue;
            if(abs(cur.first - store[i].first) + abs(cur.second - store[i].second) > 1000) continue;
            q.push(store[i]);
            visited[i] = true;
        }
        
    }
    return "sad";
}

int main(){
    fastio;
    cin >> T;
    

    for (int t = 0; t < T; t++)
    {
        cin >> N;
        store.clear();
        visited.resize(N);
        fill(visited.begin(), visited.end(), false);
        cin >> st.first >> st.second;
        for (int i = 0; i < N; i++)
        {
            pair<int, int> c;
            cin >> c.first >> c.second;
            store.push_back(c);
        }
       
        cin >> ed.first >> ed.second;
        cout << bfs() << '\n';
        
    }
        


    return 0;
}