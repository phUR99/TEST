#include <iostream>

using namespace std;


int parent[1000050];
int cnt[1000005];
int find(int u){
    if (u == parent[u]) return  u;
    return parent[u] = find(parent[u]);    
}
void merge(int u, int v){
    u = find(u), v= find(v);
    if (u==v)
        return;
    if (u < v)
        swap(u, v);
    parent[u]=v;
    cnt[v] += cnt[u];
    cnt[u] = 0;
    return;
    
}
int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i <= 1000000; i++)
    {
        parent[i] = i;
        cnt[i] = 1;
    }
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c=='Q'){
            int m;
            cin >> m;
            cout << cnt[find(m)] << '\n';
        }
        else{
            int a, b;
            cin >> a >> b;
            merge(a, b);
        }
        
    }
    


    return 0;
}