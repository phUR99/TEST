#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int main()
{
    fastio;
    string str;
    getline(cin, str);
    str.push_back(' ');
    vector<string> arr;
    stack<char> stk;
    int pos;
    int cur = 0;
    while ((pos = str.find(' ', cur)) != string::npos)
    {
        int len = pos - cur;
        arr.push_back(str.substr(cur, len));
        cur = pos + 1;
    }
    bool isOpen = false;
    for (auto &s : arr)
    {

        for (auto c : s)
        {
            if (c == '<')
            {
                while (!stk.empty())
                {
                    cout << stk.top();
                    stk.pop();
                }
                cout << c;
                isOpen = 1;
            }
            else if (c == '>')
            {
                cout << c;
                isOpen = 0;
            }
            else
            {
                if (isOpen)
                    cout << c;
                else
                    stk.push(c);
            }
        }
        while (!stk.empty())
        {
            cout << stk.top();
            stk.pop();
        }
        cout << ' ';
    }

    return 0;
}