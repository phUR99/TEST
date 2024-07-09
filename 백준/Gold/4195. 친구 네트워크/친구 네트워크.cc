#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

unordered_map<string, string> parent;
unordered_map<string, int> Rank;

string sfind(string u){    
    if(parent[u] == u) return u;
    return parent[u] = sfind(parent[u]);
}
void uni(string u, string v){
    u = sfind(u); v = sfind(v);
    if(u == v) return;    
    parent[v] = u;
    Rank[u] += Rank[v];
}
int T, N;

int main(){
    fastio;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        
        string a, b;
        parent.clear(); Rank.clear();
        cin >> N;
        while (N--)
        {
            cin >> a >> b;
            if(parent.count(a) == 0){
                parent.insert({a, a});
                Rank.insert({a, 1});
            }
            if(parent.count(b) == 0){
                parent.insert({b, b});
                Rank.insert({b, 1});
            }
            uni(a, b);
            cout << Rank[sfind(a)] << '\n';
        }                
    }
        


    return 0;

}