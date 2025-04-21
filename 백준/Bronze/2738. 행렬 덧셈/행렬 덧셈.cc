#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;

int main()
{
    fastio;
    cin >> n >> m;
    vector<vector<int>> A(n ,vector<int>(m, 0)), B(n, vector<int>(m, 0));
    for (auto &i : A)
    {
        for (auto &j : i)
        {
            cin >> j;
        }
        
    }
    for (auto &i : B)
    {
        for (auto &j : i)
        {
            cin >> j;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] += B[i][j];
        }
        
    }
    for (auto &i : A)
    {
        for (auto &j : i)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}