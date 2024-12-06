#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[1000005];
static int idx = -1;

void push()
{
    int x;
    cin >> x;
    arr[++idx] = x;
}
int pop()
{
    if (idx == -1)
        return -1;
    return arr[idx--];
}
int size()
{
    return idx + 1;
}
int empty()
{
    if (idx == -1)
        return 1;
    return 0;
}
int top()
{
    if (idx == -1)
        return -1;
    return arr[idx];
}
int main()
{
    fastio;
    int n;
    cin >> n;
    while (n--)
    {
        int command;
        cin >> command;
        switch (command)
        {
        case 1:
            push();
            break;
        case 2:
            cout << pop() << '\n';
            break;
        case 3:
            cout << size() << '\n';
            break;
        case 4:
            cout << empty() << '\n';
            break;
        default:
            cout << top() << '\n';
            break;
        }
    }

    return 0;
}