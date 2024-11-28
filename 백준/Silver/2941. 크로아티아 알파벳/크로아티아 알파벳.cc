#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
set<string> dict;
string str;
int main()
{
    fastio;
    dict.insert("c=");
    dict.insert("c-");
    dict.insert("dz=");
    dict.insert("d-");
    dict.insert("lj");
    dict.insert("nj");
    dict.insert("s=");
    dict.insert("z=");
    cin >> str;
    int cnt = 0;
    string tmp;
    for (auto &it : dict)
    {
        int pos;
        while ((pos = str.find(it)) != string::npos)
        {
            cnt++;
            for (int i = 0; i < it.size(); i++)
            {
                str[i + pos] = '0';
            }
        }
    }
    for (auto &s : str)
    {
        if (s != '0')
            cnt++;
    }

    cout << cnt;

    return 0;
}