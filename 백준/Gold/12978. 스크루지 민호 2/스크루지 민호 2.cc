#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int dp[100100][2];
int visited[100100];
vector<int> tree[100100];
void dfs(int cur){
    if(visited[cur])
        return;
    visited[cur] = 1;
    dp[cur][0] = 0;
    dp[cur][1] = 1;
    for(auto next : tree[cur]){
        if(visited[next])
            continue;
        dfs(next);
        dp[cur][0] += dp[next][1];
        dp[cur][1] += min(dp[next][1],dp[next][0]);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++){
        int a,b; cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);
    cout << min(dp[1][0],dp[1][1]);
    return 0;
}