#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
int health[25];
int enjoy[25];
int cache[105];
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> health[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> enjoy[i];
    }
    for (int i = 0; i < n; i++)
    {
        int h = health[i];
        int e = enjoy[i];
        for (int j = 100; j != health[i]; j--)
        {
            cache[j] = max(cache[j], cache[j - health[i]] + enjoy[i]);
        }
    }
    cout << cache[100];
    return 0;
}