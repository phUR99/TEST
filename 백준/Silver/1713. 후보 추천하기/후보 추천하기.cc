#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, t;
int thumb[105];
int times[105];
set<int> picture;
int main()
{
    fastio;
    cin >> n >> t;
    for (int i = 0; i < t; i++)
    {
        int x;
        cin >> x;

        thumb[x]++;
        if (picture.count(x))
            continue;
        else
        {
            if (picture.size() == n)
            {
                vector<array<int, 3>> tmp;
                for (auto it : picture)
                {
                    tmp.push_back({thumb[it], times[it], it});
                }
                sort(tmp.begin(), tmp.end());
                int y = tmp.front()[2];
                picture.erase(y);
                thumb[y] = 0;
            }
            picture.insert(x);
            times[x] = i;
        }                
    }
    for (auto it : picture)
    {
        cout << it << ' ';
    }

    return 0;
}