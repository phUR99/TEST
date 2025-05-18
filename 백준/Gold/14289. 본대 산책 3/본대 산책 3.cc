    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    int n, m, d;
    vector<vector<ll>> adj;
    const ll mod = 1e9 + 7;

    vector<vector<ll>> operator*(const vector<vector<ll>> &a, const vector<vector<ll>> &b){
        vector<vector<ll>> ret;
        int row = a.size();
        int col = a[0].size();
        ret.resize(row, vector<ll>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                ll tmp = 0;
                for (int k = 0; k < row; k++)
                {
                    tmp = (tmp + a[i][k] * b[k][j]) % mod;
                }
                ret[i][j] = tmp;
            }
        }
        return ret;   
    }
    vector<vector<ll>> solve(int n){
        if (n == 1) return adj;
        if (n & 1) return adj * solve(n-1);
        auto half = solve(n/2);
        return half * half;
    }


    int main(){
        ios_base::sync_with_stdio(0); cin.tie(0);
        cin >> n >> m;
        adj.resize(n + 1, vector<ll>(n+1, 0));
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        cin >> d;
        auto ret = solve(d);
        cout << ret[1][1];

        return 0;
    }