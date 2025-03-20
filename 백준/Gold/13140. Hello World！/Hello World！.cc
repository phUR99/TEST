#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;

map<char, int> id;
map<char, int> val;
bool visited[10];
void solve(map<char, int>::iterator it)
{
    if (it == id.end())
    {
        string a = "hello";
        string b = "world";
        int answer = 0;
        string c = a + b;
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        for (auto it : c)
        {
            answer += id[it] * val[it];
        }

        if (answer != n)
            return;

        cout << "  ";
        for (auto it : a)
        {
            cout << val[it];
        }
        cout << '\n';
        cout << "+ ";
        for (auto it : b)
        {
            cout << val[it];
        }
        cout << '\n';
        cout << "-------\n";
        string str = to_string(n);
        while (str.size() < 7)
        {
            str = ' ' + str;
        }
        cout << str;
        exit(0);
    }
    char c = it->first;
    int start = (c == 'h' || c == 'w' ? 1 : 0);
    for (int i = start; i < 10; i++)
    {
        if (visited[i])
            continue;
        val[c] = i;
        visited[i] = 1;
        solve(next(it));
        visited[i] = 0;
    }
}
int main()
{
    fastio;
    cin >> n;
    string a = "hello";
    string b = "world";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int pow = 1;
    for (int i = 0; i < a.size(); i++)
    {
        id[a[i]] += pow;
        pow *= 10;
    }
    pow = 1;
    for (int i = 0; i < b.size(); i++)
    {
        id[b[i]] += pow;
        pow *= 10;
    }
    solve(id.begin());
    cout << "No Answer";
    return 0;
}