#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
const int MX = 10000;
bool isPrime[MX + 5];
int dist[MX + 5];
void precalc()
{
    fill(isPrime, isPrime + MX + 5, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MX; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

void solve()
{
    queue<int> q;
    int st, ed;
    cin >> st >> ed;
    memset(dist, -1, sizeof(dist));
    q.push(st);
    dist[st] = 0;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            string there = to_string(here);
            for (int j = 0; j < 10; j++)
            {
                there[i] = j + '0';
                if (stoi(there) < 1000)
                    continue;
                if (dist[stoi(there)] != -1)
                    continue;
                if (!isPrime[stoi(there)])
                    continue;
                dist[stoi(there)] = dist[here] + 1;
                q.push(stoi(there));
            }
        }
    }
    if (dist[ed] == -1)
        cout << "impossible\n";
    else
        cout << dist[ed] << '\n';
}
int main()
{
    fastio;
    precalc();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}