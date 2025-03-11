#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
string str;
vector<int> arr;
bool visited[55];
void solve(int idx, int maxlen, int cnt)
{
    if (idx == n)
    {
        if (maxlen == cnt)
        {
            for (int i : arr)
            {
                cout << i << ' ';
            }
            exit(0);
        }
    }
    string tmp;
    for (int i = idx; i < n; i++)
    {
        tmp += str[i];
        if (stoi(tmp) > 50)
            return;
        if (visited[stoi(tmp)])
            continue;
        visited[stoi(tmp)] = true;
        arr.push_back(stoi(tmp));
        solve(i + 1, max(maxlen, stoi(tmp)), cnt + 1);
        visited[stoi(tmp)] = false;
        arr.pop_back();
    }
}
int main()
{
    fastio;
    cin >> str;
    n = str.size();
    solve(0, 0, 0);
    return 0;
}