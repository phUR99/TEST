#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

string str;

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0; // '('에는 우선순위 0을 부여
}

int main()
{
    fastio;
    cin >> str;
    int n = str.size();

    stack<char> s;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(str[i]))
        {
            cout << str[i];
        }
        else if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && precedence(s.top()) >= precedence(str[i]))
            {
                cout << s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}
