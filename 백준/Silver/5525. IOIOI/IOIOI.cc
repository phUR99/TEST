#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
string str;

int main()
{
    fastio;
    cin >> n >> m;
    cin >> str;
    int ret = 0;
    for (int i = 0; i < m; i++)
    {
        if (str[i] == 'O')
            continue;
        int k = 0;
        while (str[i + 1] == 'O' && str[i + 2] == 'I')
        {
            k++;
            if (k == n)
            {
                k--;
                ret++;
            }
            i += 2;
        }
    }
    cout << ret;
    return 0;
}