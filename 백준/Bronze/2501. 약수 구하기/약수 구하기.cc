#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, k;
stack<int> s;

int main()
{
    fastio;
    cin >> n >> k;
    vector<int> mod;
    for (int i = 1; i <= n; i++)
    {
        if(n % i == 0)
            mod.push_back(i);
    }
    if(mod.size() < k)
        cout << 0;
    else
        cout << mod[k-1];
    
    
    return 0;
}